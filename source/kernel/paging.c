#include <paging.h>
#include <linker.h>

unsigned long kernelpagedir[1024] __attribute__ ((aligned (PAGE_SIZE)));
unsigned long lowpagetable[1024] __attribute__ ((aligned (PAGE_SIZE)));

unsigned long highpagetable[1024] __attribute__ ((aligned (PAGE_SIZE)));
 
void init_paging(void){
	int k = 0;
 
	for(k = 0; k < PT_ENTRIES; k++){
		lowpagetable[k] = (k * PAGE_SIZE) | PRESENT | WRITABLE;
		kernelpagedir[k] = 0;
	}

	for(k = 0; k < PT_ENTRIES; k++){
		highpagetable[k] = (KERNEL_HIGH_START + (k * PAGE_SIZE)) | PRESENT | WRITABLE;
	}
 
	kernelpagedir[0] = (unsigned long)lowpagetable | PRESENT | WRITABLE;
	kernelpagedir[PDIR_PART(KERNEL_HIGH)] = (unsigned long)highpagetable | PRESENT | WRITABLE;
 
	asm volatile (	"mov %0, %%eax\n"
					"mov %%eax, %%cr3\n"
					"mov %%cr0, %%eax\n"
					"orl $0x80000000, %%eax\n"
					"mov %%eax, %%cr0\n" :: "rm" (kernelpagedir));
}
