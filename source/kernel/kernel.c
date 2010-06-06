#include <multiboot.h>
#include <serial.h>
#include <section.h>
#include <string_io.h>
#include <error.h>
#include <gdt.h>
#include <paging.h>

int PHYS_CODE main(int multiboot_magic, multiboot_info_t *multiboot_info_ptr) {

	if(multiboot_magic != MULTIBOOT_BOOTLOADER_MAGIC){
		error("Must be booted by a multiboot compliant bootloader\n");
	} else {
		puts("Detected multiboot bootloader\n");
	}

	puts("multiboot commandline: ");
	puts((char *)multiboot_info_ptr->cmdline);
	puts("\n");

	gdt_install();

	init_paging();

	puts("still alive\n");

	for(;;);
	return 1;
}
