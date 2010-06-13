ENTRY(_kernel_entry)

KERNEL_LOAD_BASE = 0x00100000;
KERNEL_HIGH_BASE = 0xf0000000;

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
	_kernel_high_start = .;

	LOW_END = .;

	. = KERNEL_HIGH_BASE;

    .text.high . : AT(ADDR(.text.high) - KERNEL_HIGH_BASE + LOW_END)
    {
        *(.text.high)
    }

    .rodata.high . : AT(ADDR(.rodata.high) - KERNEL_HIGH_BASE + LOW_END)
    {
        *(.rodata.high)
        *(.rodata.high.*)
    }

    .data.high . : AT(ADDR(.data.high) - KERNEL_HIGH_BASE + LOW_END)
    {
        *(.data.high) 
    }

    .bss.high . : AT(ADDR(.bss.high) - KERNEL_HIGH_BASE + LOW_END)
    {
        *(.bss.high)
    }

    . = ALIGN(4K);

	_kernel_high_end = . - KERNEL_HIGH_BASE + LOW_END;

	_kernel_phys_end = . - KERNEL_HIGH_BASE + LOW_END;

    /DISCARD/ :
    {
        *(.*)
    }
}

