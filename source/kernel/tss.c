#include <tss.h>
#include <gdt.h>
#include <section.h>

HIGH_DATA struct tss the_tss;

void tss_install(void){
	asm volatile (	"ltr %%ax\n" :: "a" (GDT_TSS_SEL));
}
