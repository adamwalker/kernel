#define INT_HANDLER_WITH_ERR_CODE(number)    \
.global int_##number;                        \
int_##number:                                \
    pushl   $0x##number; 					 \
    jmp     isr_common_stub;

#define INT_HANDLER_WITHOUT_ERR_CODE(number) \
.global int_##number;                        \
int_##number:                                \
    pushl   $0x##number; 					 \
    pushl   $0x0;                            \
    jmp     isr_common_stub;

INT_HANDLER_WITHOUT_ERR_CODE(00)
INT_HANDLER_WITHOUT_ERR_CODE(01)
INT_HANDLER_WITHOUT_ERR_CODE(02)
INT_HANDLER_WITHOUT_ERR_CODE(03)
INT_HANDLER_WITHOUT_ERR_CODE(04)
INT_HANDLER_WITHOUT_ERR_CODE(05)
INT_HANDLER_WITHOUT_ERR_CODE(06)
INT_HANDLER_WITHOUT_ERR_CODE(07)
INT_HANDLER_WITH_ERR_CODE(08)
INT_HANDLER_WITHOUT_ERR_CODE(09)
INT_HANDLER_WITH_ERR_CODE(0a)
INT_HANDLER_WITH_ERR_CODE(0b)
INT_HANDLER_WITH_ERR_CODE(0c)
INT_HANDLER_WITH_ERR_CODE(0d)
INT_HANDLER_WITH_ERR_CODE(0e)
INT_HANDLER_WITHOUT_ERR_CODE(0f)

INT_HANDLER_WITHOUT_ERR_CODE(10)
INT_HANDLER_WITH_ERR_CODE(11)
INT_HANDLER_WITHOUT_ERR_CODE(12)
INT_HANDLER_WITHOUT_ERR_CODE(13)
INT_HANDLER_WITHOUT_ERR_CODE(14)
INT_HANDLER_WITHOUT_ERR_CODE(15)
INT_HANDLER_WITHOUT_ERR_CODE(16)
INT_HANDLER_WITHOUT_ERR_CODE(17)
INT_HANDLER_WITHOUT_ERR_CODE(18)
INT_HANDLER_WITHOUT_ERR_CODE(19)
INT_HANDLER_WITHOUT_ERR_CODE(1a)
INT_HANDLER_WITHOUT_ERR_CODE(1b)
INT_HANDLER_WITHOUT_ERR_CODE(1c)
INT_HANDLER_WITHOUT_ERR_CODE(1d)
INT_HANDLER_WITHOUT_ERR_CODE(1e)
INT_HANDLER_WITHOUT_ERR_CODE(1f)

.extern fault_handler

isr_common_stub:
    pusha
    push %ds
    push %es
    push %fs
    push %gs
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %esp, %eax
    push %eax
    call fault_handler
    pop %eax
    pop %gs
    pop %fs
    pop %es
    pop %ds
    popa
    add $0x8, %esp 
    iret           

