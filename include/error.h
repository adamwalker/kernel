#ifndef __ERROR_H
#define __ERROR_H

#include <string_io.h>

static inline void error(char *message){
	puts(message);
	for(;;);
}

#endif
