#ifndef __IO_H
#define __IO_H

#include <types.h>
#include <section.h>

static inline uint8_t inb(uint16_t port)
{
   uint8_t ret;
   asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
   return ret;
}

static inline void outb(uint16_t port, uint8_t value)
{
   asm volatile ("outb %%al,%%dx": :"d" (port), "a" (value));
}

#endif
