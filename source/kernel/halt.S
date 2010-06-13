.section .text

.global halt

halt:
	cli
	hlt
	jmp halt

.global idle

idle:
	sti
	hlt
	jmp idle
