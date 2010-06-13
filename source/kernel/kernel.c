#include <multiboot.h>
#include <serial.h>
#include <section.h>
#include <string_io.h>
#include <error.h>
#include <gdt.h>
#include <paging.h>
#include <idt.h>
#include <pic.h>
#include <tss.h>
#include <assert.h>
#include <pit.h>
#include <linker.h>

int main(int multiboot_magic, multiboot_info_t *multiboot_info_ptr) {

	if(multiboot_magic != MULTIBOOT_BOOTLOADER_MAGIC){
		error("Must be booted by a multiboot compliant bootloader\n");
	} else {
		puts("Detected multiboot bootloader\n");
	}

	printf("Multiboot commandline: %s\n", (char *)multiboot_info_ptr->cmdline);

	printf("Kernel high start: %x, kernel high end: %x\n", KERNEL_HIGH_START, KERNEL_HIGH_END);

	printf("Initialising Paging...");
	init_paging();
	printf("Done\n");

	printf("Initialising GDT...");
	gdt_install();
	printf("Done\n");

	printf("Initialising IDT...");
	idt_install();
	printf("Done\n");

	printf("Initialising TSS...");
	tss_install();
	printf("Done\n");

	printf("Remapping the PIC...");
	PIC_remap(0x20, 0x28);
	printf("Done\n");

	printf("Setting the timer rate...");
	timer_hz(100);
	printf("Done\n");

	//*(char *)0xbfffffff = 0;

	sti();

	idle();
	return 1;
}
