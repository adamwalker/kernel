#include <idt.h>
#include <gdt.h>
#include <isr.h>

struct idt_entry idt[256];
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
};

void idt_install(void)
{
	int i;

	idtp.size = (sizeof (struct idt_entry) * 256) - 1;
	idtp.base = (unsigned int)&idt;

	for(i=0; i<0x20; i++){
		idt_set_entry(i, (unsigned int)isrs[i], GDT_CODE_SEL, 0x8e);
	}
 
	asm volatile (	"lidt %0\n" :: "m" (idtp));
}
