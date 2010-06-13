#include <io.h>
#include <serial.h>
#include <section.h>

#define PORT 0x3f8

void serial_send(char c) {
	while((inb(PORT+5) & 0x20) == 0);
	outb(PORT, c);
}

int serial_recv(void) {
	while((inb(PORT+5) & 0x01) == 0);
	return inb(PORT);
}
