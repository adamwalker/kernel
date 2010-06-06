.section .text

.extern gp
.global gdt_flush

gdt_flush:
	lgdt gp
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
	jmp $0x08, $flush2
 
flush2:
	ret



