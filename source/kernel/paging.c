#include <paging.h>

unsigned long kernelpagedir[1024] __attribute__ ((aligned (4096)));
unsigned long lowpagetable[1024] __attribute__ ((aligned (4096)));
 
void init_paging(void){
	int k = 0;
 
	for(k = 0; k < 1024; k++){
		lowpagetable[k] = (k * 4096) | 0x3;	
		kernelpagedir[k] = 0;
	}
 
	kernelpagedir[0] = (unsigned long)lowpagetable | 0x3;
 
	asm volatile (	"mov %0, %%eax\n"
					"mov %%eax, %%cr3\n"
					"mov %%cr0, %%eax\n"
					"orl $0x80000000, %%eax\n"
					"mov %%eax, %%cr0\n" :: "rm" (kernelpagedir));
}
