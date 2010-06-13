ENTRY(_kernel_entry)

KERNEL_PHYS_BASE = 0x00000000;
KERNEL_LOAD_BASE = 0x00100000;
KERNEL_VIRT_BASE = 0xe0000000;
KERNEL_OFFSET = KERNEL_VIRT_BASE - KERNEL_PHYS_BASE;

SECTIONS
{
    . = KERNEL_LOAD_BASE;

    _phys_start = .;
    .phys . :
    {
        *(.mbh)
        *(.phys.text)
        _boot_stack_bottom = .;
        . = . + 4K;
        . = ALIGN(4K);
        _boot_stack_top = .;
    }

    _phys_end_init_start = .;
    PHYS_END = .;

    .text . :
    {
        *(.text)
    }

    .rodata . :
    {
        *(.rodata)
        *(.rodata.*)
    }

    .data . :
    {
        *(.data) 
    }

    .bss . :
    {
        *(.bss)
        *(COMMON)
    }

    . = ALIGN(4K);
    _kernel_low_end = .;

    /DISCARD/ :
    {
        *(.*)
    }
}

