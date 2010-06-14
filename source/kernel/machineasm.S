.section .text

.extern gp
.global gdt_flush
.global rdmsr
.global wrmsr
.global setCurrentPD
.global invalidateTLB
.global invalidateTLBEntry
.global getFaultAddr

gdt_flush:
	lgdt gp
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
	ljmp $0x08, $flush2
 
flush2:
	ret

rdmsr:              
    movl 4(%esp),  %ecx     # MSR register index
    rdmsr                   # 8 bytes output will be in EDX:EAX 
    ret                  

wrmsr:              
    movl 4(%esp),  %ecx     # MSR register index
    movl 8(%esp),  %eax     # 4 least significant bytes     
    movl 12(%esp), %edx     # 4 most significant bytes
    wrmsr                
    ret

setCurrentPD:
    movl 4(%esp), %eax
    movl %eax,    %cr3
    ret

invalidateTLB:
    movl %cr3, %eax
    movl %eax, %cr3
    ret

invalidateTLBentry:
    movl 4(%esp), %eax
    invlpg (%eax)
    ret

getFaultAddr:
    movl %cr2, %eax
    ret

