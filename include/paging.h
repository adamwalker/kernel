#ifndef __PAGING_H
#define __PAGING_H

#include <util.h>

void init_paging(void);

#define PAGE_SIZE (4096)
#define PT_ENTRIES (1024)

#define PRESENT BIT(0)
#define WRITABLE BIT(1)
#define USER BIT(2)

#define PDIR_PART(x) ((x) >> 22) & MASK(10)
#define PTAB_PART(x) ((x) >> 12) & MASK(10)

#endif
