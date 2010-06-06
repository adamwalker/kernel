#include <serial.h>
#include <section.h>
#include <string_io.h>

void PHYS_CODE puts(char *str){
	while(*str){
		serial_send(*str);
		str++;
	}
}

const char hexchars[] = "0123456789ABCDEF";

void putx(unsigned int x){
	int i;
	for(i=0; i<8; i++){
		serial_send(hexchars[(x&0xf0000000) >> 28]);
		x <<= 4;
	}
}
