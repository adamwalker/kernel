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
#include <malloc.h>
#include <sysenter.h>

int main(int multiboot_magic, multiboot_info_t *mbi) {

	if(multiboot_magic != MULTIBOOT_BOOTLOADER_MAGIC){
		error("Must be booted by a multiboot compliant bootloader\n");
	} else {
		puts("Detected multiboot bootloader\n");
	}

	printf("Multiboot commandline: %s\n", (char *)mbi->cmdline);

	printf("Kernel high start: %x, kernel high end: %x\n", KERNEL_HIGH_START, KERNEL_HIGH_END);

	printf("Physical memory low start: %x, end: %x\n", 0, mbi->mem_lower << 10);
	printf("Physical memory high start: %x, end: %x\n", 0x100000, 0x100000 + (mbi->mem_upper << 10));

	printf("Bootloader provided %x module(s)\n", mbi->mods_count);

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

	printf("Setting up sysenter MSRs...");
	setup_sysenter_msrs();
	printf("Done\n");

	init_mmap(KERNEL_PHYS_END, mbi->mem_upper << 10);

	asm volatile ("sysenter");

	*(char *)0xbfffffff = 0;

	sti();

	idle();
	return 1;
}
