#ifndef __GDT_H
#define __GDT_H

struct gdt_entry
{
	unsigned short limit_low;
	unsigned short base_low;
	unsigned char base_middle;
	unsigned char access;
	unsigned char granularity;
	unsigned char base_high;
} __attribute__((packed));
 
struct gdt_ptr
{
	unsigned short limit;
	unsigned int base;
} __attribute__((packed));

#define GDT_CODE_SEL 0x8
#define GDT_DATA_SEL 0x10

void gdt_install(void);

#endif
 
