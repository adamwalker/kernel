#ifndef __STRING_IO_H
#define __STRING_IO_H

#include <serial.h>

int puts(char *str);
void putx(unsigned int x);
unsigned int printf(const char *format, ...);

#define putc serial_send

#endif
