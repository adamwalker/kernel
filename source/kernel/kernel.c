#include <multiboot.h>
#include <serial.h>
#include <section.h>
#include <string_io.h>
#include <error.h>
#include <gdt.h>
#include <paging.h>
#include <idt.h>
#include <pic.h>

int PHYS_CODE main(int multiboot_magic, multiboot_info_t *multiboot_info_ptr) {

	if(multiboot_magic != MULTIBOOT_BOOTLOADER_MAGIC){
		error("Must be booted by a multiboot compliant bootloader\n");
	} else {
		puts("Detected multiboot bootloader\n");
	}

	printf("Multiboot commandline: %s\n", (char *)multiboot_info_ptr->cmdline);

	gdt_install();

	init_paging();

	idt_install();

	PIC_remap(0x20, 0x28);

	printf("asdf %x %d %x\n", 9, "str", 10);

	puts("still alive\n");

	*(char *)0xbfffffff = 0;

	for(;;);
	return 1;
}
