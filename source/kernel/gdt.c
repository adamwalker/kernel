#include <gdt.h>
#include <tss.h>
#include <section.h>

HIGH_DATA struct gdt_entry gdt[6];
struct gdt_ptr gp;

extern tss_t the_tss;
 
void gdt_flush(void);
 
static void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran) {
	gdt[num].base_low = (base & 0xFFFF);
	gdt[num].base_middle = (base >> 16) & 0xFF;
	gdt[num].base_high = (base >> 24) & 0xFF;
 
	gdt[num].limit_low = (limit & 0xFFFF);
	gdt[num].granularity = ((limit >> 16) & 0x0F);
 
	gdt[num].granularity |= (gran & 0xF0);
	gdt[num].access = access;
}
 
void gdt_install(void) {
	gp.limit = (sizeof(struct gdt_entry) * 6) - 1;
	gp.base = (unsigned int)&gdt;
 
	gdt_set_gate(0, 0, 0, 0, 0);
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	gdt_set_gate(3, 0, 0xFFFFFFFF, 0xfA, 0xCF);
	gdt_set_gate(4, 0, 0xFFFFFFFF, 0xf2, 0xCF);
	gdt_set_gate(5, (unsigned int)&the_tss, sizeof(struct tss), 0x89, 0x40);
 
	gdt_flush();
}

