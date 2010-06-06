#ifndef __SECTION_H
#define __SECTION_H

#define SECTION(X) __attribute__ ((section (X)))

#define PHYS_CODE SECTION(".phys.text")

#endif
