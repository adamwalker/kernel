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

#define GDT_NULL 0x0
#define GDT_CS_0 0x8
#define GDT_DS_0 0x10
#define GDT_CS_3 0x18
#define GDT_DS_3 0x20
#define GDT_TSS  0x28

void gdt_install(void);

#endif
 
