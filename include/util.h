#ifndef __UTIL_H
#define __UTIL_H

void halt(void);
void idle(void);
int atoi(const char *str, int *result);
char *strncpy(char *dest, const char *src, int size);
int strlen(const char *str);
void *memset(void *dest, int val, int size);
void *memcpy(void *dest, const void *src, int size);

static inline void sti(void){
	asm volatile ("sti");
}

static inline void cli(void){
	asm volatile ("cli");
}
#define NULL ((void *)0)

#define BIT(x) (1<<(x))
#define MASK(x) (BIT(x) - 1)

#endif
