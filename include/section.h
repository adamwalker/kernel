#ifndef __SECTION_H
#define __SECTION_H

#define SECTION(X) __attribute__ ((section (X)))

#define HIGH_CODE SECTION(".text.high")
#define HIGH_DATA SECTION(".data.high")
#define HIGH_BSS  SECTION(".bss.high")

#endif
