# Goofkit
Goofkit is an inline function hooking and trampolining rootkit. Goofkit uses inline hooking and trampolining to create a more robust and better hidden rootkit. Goofkit does not modify the system call table instead it inserts hooks into the system calls itself.

![alt text](https://raw.githubusercontent.com/RITRedteam/goofkit/master/docs/Poster.png)

## Features
* Process hiding
  - Hide processes from the /proc directory
* File hiding
  - Hides files from the getdents call
* Hiding itself
  - Unlinks itself from the kobject list and the init list
* File ACLs (broken?)
  - Returns error when specifi files attempt to open
* _Netfilter hook - WIP_
* _Privelege escalation - WIP_

## Support
| Kernel Ver.   | Debian 9 | Centos 7|
| ------------- |--------| ------|
| 4.9.0         | ?      | ?     |
| 3.10.0-957    | ?      | ?     |
| xxxxxxxxxxxxx | ?      | ?     |

## Inline hooking
Instead of using the standard method of system call hooking (overwriting the system call table) Goofkit inserts a jump instruction to change the code flow.
<pre>
\x48\xb8\x88\x77\x66\x55\x44\x33\x22\x11\x48\x89\xc0\xff\xe0

0:    48 b8 88 77 66 55 44      movabs rax,0x1122334455667788   ; load address into RAX
7:    33 22 11
a:    48 89 c0                  mov    rax,rax                  ; required but not sure why
d:    ff e0                     jmp    rax                      ; jump to address
</pre>
When copying these instructions into the systemcall its important to not cut instructions in half. If the instruction is cut in half it will result in garbage bytes in the instructions which will casaue the kernel to crash.<br>
To avoid cutting instructions in half Goofkit uses an LDE (currently BeaEngine) to measure the length of each instruction. Goofkit will calculate the number of 1 byte nop instructions it needs to append to the hook so that insturctions are not cut. <br>
A simplified version of how the LDE is used is shown here:
<pre>
while len < hook_len:
    len += len(*eip)
    eip += len
</pre>

## Trampolining
Trampolining is the reason Goofkit is able to do inline function hooking without multiple writes to the system calls. When a rookit uses inline hooking and wants to pause a specific hook or all malicious behavior it needs to rewrite the systemcall each time. Trampolining allows Goofkit to seemlessly resume normal execution. Instead of rewriting the system call execution can be passed along through the malicious hook to the trampoline and subsequently the original function.

<pre>
syscall_open --> malicious_open --> open_trampoline --> syscall_open+offset_of_hook
</pre>

## Creating new hook
To create a new hook you will need to do the following:
1. Increment the `HOOKS_COUNT` macro
2. Define a "goofy" function `goofy_open()` in goof.h
3. Write your function in goof.c
4. Add a hook: <br>
  a. In  `goof_init` add a `create_tramp` call. Specify the source (eg. `sys_close`). Specify the goof function. Provide an ID number < HOOKS_COUNT. Specify the byte count provided by the `number_of_bytes_to_pad_jump` function.<br>
  b. In `goof_exit` add a remove function passing the ID number of the hook from the previous step.<br>
