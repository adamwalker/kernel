#include <isr.h>
#include <string_io.h>

char *exception_messages[] =
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

void fault_handler(struct regs *r) {
    if (r->int_no < 32) {
        puts(exception_messages[r->int_no]);
        puts(" Exception. System Halted!\n");
        for (;;);
    }
}

