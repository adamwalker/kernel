#ifndef __UTIL_H
#define __UTIL_H

void halt(void);
int atoi(const char *str, int *result);
char *strncpy(char *dest, const char *src, int size);
int strlen(const char *str);
void *memset(void *dest, int val, int size);
void *memcpy(void *dest, const void *src, int size);

#define NULL ((void *)0)

#endif
