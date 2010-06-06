#define ASM
#include <multiboot.h>

.section .mbh
    /* MultiBoot header */
    .align  4
    .long   MULTIBOOT_HEADER_MAGIC;
    .long   MULTIBOOT_HEADER_FLAGS;
    .long   - MULTIBOOT_HEADER_FLAGS - MULTIBOOT_HEADER_MAGIC;

.section .phys.text

.extern _boot_stack_top
.extern main

.global _kernel_entry

_kernel_entry:

    /* Load kernel boot stack pointer */
    leal    _boot_stack_top, %esp

    /* Reset EFLAGS register (also disables interrupts etc.) */
    pushl   $0
    popf

    /* Push parameters for calling kernel main */
    pushl   %ebx  /* 2nd parameter: multiboot_info_ptr */
    pushl   %eax  /* 1st parameter: multiboot_magic    */

	call 	main
