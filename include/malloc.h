#ifndef __MALLOC_H
#define __MALLOC_H

void init_mmap(unsigned int low, unsigned int high);
unsigned int alloc_page(void);

#endif
