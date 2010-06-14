#ifndef __MACHINE_H
#define __MACHINE_H

#include <types.h>

uint64_t rdmsr(const uint32_t reg);
void wrmsr(const uint32_t reg, const uint64_t val);
void setCurrentPD(uint32_t addr);
void invalidateTLB(void);
void invalidateTLBentry(uint32_t vptr);
uint32_t getFaultAddr(void);

#endif
