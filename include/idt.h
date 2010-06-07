#ifndef __IDT_H
#define __IDT_H

struct idt_entry{
   unsigned short offset_low; 
   unsigned short selector; 
   unsigned char zero;     
   unsigned char type_attr; 
   unsigned short offset_high; 
} __attribute__((packed));

struct idt_ptr
{
	unsigned short size;
	unsigned int base;
} __attribute__((packed));

void idt_install(void);

#endif

