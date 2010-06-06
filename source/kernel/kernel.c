#include <multiboot.h>
#include <serial.h>
#include <section.h>

int PHYS_CODE main(void) {
	serial_send('w');
	for(;;);
	return 1;
}
