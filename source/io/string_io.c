#include <serial.h>
#include <section.h>
#include <string_io.h>
#include <stdarg.h>

int puts(char *str){
	int n = 0;
	while(*str){
		serial_send(*str);
		str++;
		n++;
	}
	return n;
}

const char hexchars[] = "0123456789ABCDEF";

void putx(unsigned int x){
	int i;
	for(i=0; i<8; i++){
		serial_send(hexchars[(x&0xf0000000) >> 28]);
		x <<= 4;
	}
}

static int vprintf(const char *format, va_list args) {
	char c;
	int n = 0;
	while((c = *format++)){
		switch(c){
			case '%': {
				switch(*format++){
					case '%':
						putc('%');
						n++;
						break;
					case 'x':
						putx(va_arg(args, unsigned int));
						n+=8;
						break;
					case 's':
						n += puts(va_arg(args, char *));
						break;
					case '\0':
						return n;
					default:
						va_arg(args, unsigned int);
						putc('?');
						n+=1;
						break;
				}
				break;
			}
			default: {
				putc(c);
				n++;
				break;
			}
		}
	}
	return n;
}

unsigned int printf(const char *format, ...){
	va_list args;
	unsigned int i;
	va_start(args, format);
	i = vprintf(format, args);
	va_end(args);
	return i;
}
