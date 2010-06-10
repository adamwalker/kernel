#ifndef __ASSERT_H
#define __ASSERT_H

#include <util.h>

static inline void _fail(const char *s, const char *file, unsigned int line, const char *function) {
    printf("Called fail at %s:%u in function %s. Message \"%s\"\n", file, line, function, s);       
    halt();              
}                        

#define fail(s) _fail(s, __FILE__, __LINE__, __func__)

static inline void __assert_fail(const char *assertion, const char *file, unsigned int line, const char *function) {
    printf("Failed assertion '%s' at %s:%u in function %s\n", assertion, file, line, function);
    halt();
}

#define assert(expr) if(!(expr)) __assert_fail(#expr, __FILE__, __LINE__, __FUNCTION__)

#define compile_assert(name, expr) typedef int __assert_failed_##name[(expr) ? 1 : -1];

#endif
