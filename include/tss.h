#ifndef __TSS_H
#define __TSS_H

#include <types.h>

typedef struct tss {
	uint16_t	backlink, __blh;
	uint32_t	esp0;
	uint16_t	ss0, __ss0h;
	uint32_t	esp1;
	uint16_t	ss1, __ss1h;
	uint32_t	esp2;
	uint16_t	ss2, __ss2h;
	uint32_t	cr3;
	uint32_t	eip;
	uint32_t	eflags;
	uint32_t	eax, ecx, edx, ebx;
	uint32_t	esp, ebp, esi, edi;
	uint16_t	es, __esh;
	uint16_t	cs, __csh;
	uint16_t	ss, __ssh;
	uint16_t	ds, __dsh;
	uint16_t	fs, __fsh;
	uint16_t	gs, __gsh;
	uint16_t	ldt, __ldth;
	uint16_t	trace, bitmap;
} tss_t;

void tss_install(void);

#endif
