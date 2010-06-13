#include <malloc.h>
#include <types.h>
#include <paging.h>

unsigned int alloc_bot;

void init_mmap(unsigned int low, unsigned int high){
	alloc_bot = low;
}

unsigned int alloc_page(void){
	unsigned int ret = alloc_bot;
	alloc_bot+=PAGE_SIZE; 
	return ret;
}

