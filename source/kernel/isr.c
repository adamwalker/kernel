#include <isr.h>
#include <string_io.h>
#include <util.h>
#include <pic.h>
#include <section.h>

HIGH_DATA char *exception_messages[] =
{
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
	"Breakpoint",
	"Overflow",
	"Bounds Check",
	"Invalid Opode",
	"Coprocessor Not Available",
	"Double Fault",
	"Coprocessor Segment Overrun",
	"Invalid TSS",
	"Segment Not Present",
	"Stack Exception",
	"General Protection Violation",
	"Page Fault",
	"Unknown Interrupt",
	"Coprocessor Error",
	"Alignment Check",
	"Machine Check",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
};

HIGH_CODE void fault_handler(struct regs *r) {
    if (r->int_no < 32) {
		printf("%s exception, system halted\n", exception_messages[r->int_no]);
        halt();
    } else {
		printf("interrupt %x\n", r->int_no);
		PIC_send_EOI(r->int_no - 0x20);
	}
}

