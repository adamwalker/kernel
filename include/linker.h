#ifndef __LINKER_H
#define __LINKER_H

extern unsigned int _kernel_high_start, _kernel_high_end;

#define KERNEL_HIGH_START ((unsigned int)&_kernel_high_start)
#define KERNEL_HIGH_END   ((unsigned int)&_kernel_high_end)

#endif
