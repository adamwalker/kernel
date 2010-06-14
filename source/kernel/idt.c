#include <idt.h>
#include <gdt.h>
#include <isr.h>
#include <util.h>
#include <string_io.h>
#include <section.h>

HIGH_DATA struct idt_entry idt[256];
struct idt_ptr idtp;

static void idt_set_entry(int num, unsigned long offset, unsigned short sel, unsigned char type){
	idt[num].offset_low = (offset & 0xFFFF);
	idt[num].offset_high = (offset >> 16) & 0xFFFF;

	idt[num].selector = sel;

	idt[num].zero = 0;
 
	idt[num].type_attr = type;
}

#define INT_GATE_32 0x8E

void (*isrs[])(void) = 
{
	int_00,
	int_01,
	int_02,
	int_03,
	int_04,
	int_05,
	int_06,
	int_07,
	int_08,
	int_09,
	int_0a,
	int_0b,
	int_0c,
	int_0d,
	int_0e,
	int_0f,
	int_10,
	int_11,
	int_12,
	int_13,
	int_14,
	int_15,
	int_16,
	int_17,
	int_18,
	int_19,
	int_1a,
	int_1b,
	int_1c,
	int_1d,
	int_1e,
	int_1f,
	int_20,
	int_21,
	int_22,
	int_23,
	int_24,
	int_25,
	int_26,
	int_27,
	int_28,
	int_29,
	int_2a,
	int_2b,
	int_2c,
	int_2d,
	int_2e,
	int_2f,
};

void idt_install(void){
	int i;

	idtp.size = (sizeof (struct idt_entry) * 256) - 1;
	idtp.base = (unsigned int)&idt;

	memset(idt, 0, sizeof(idt));

	for(i=0; i<0x30; i++){
		idt_set_entry(i, (unsigned int)isrs[i], GDT_CS_0, 0x8e);
	}
 
	asm volatile (	"lidt %0\n" :: "m" (idtp));
}
