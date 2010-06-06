ENTRY(_kernel_entry)

KERNEL_PHYS_BASE = 0x00000000;
KERNEL_LOAD_BASE = 0x00100000;
KERNEL_VIRT_BASE = 0xe0000000;
KERNEL_OFFSET = KERNEL_VIRT_BASE - KERNEL_PHYS_BASE;

SECTIONS
{
    /*  Physically linked part of init code and data. Start/end is 4K aligned.
        This section is reclaimed after kernelInit completes.
    */

    /* load kernel to 1M to avoid the famous IA-32 memory holes below */
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
        _boot_PD_bottom = .;
        . = . + 4K;
        _boot_PD_top = .;
    }

    _phys_end_init_start = .;
    PHYS_END = .;

    /*  Virtually linked part of init code and data. Start/end is 4K aligned.
        This section is reclaimed after kernelInit completes.
    */
    . = KERNEL_OFFSET;

    .init.text . : AT(ADDR(.init.text) - KERNEL_OFFSET + PHYS_END)
    {
        *(.init)
    }
    .init.data . : AT(ADDR(.init.data) - KERNEL_OFFSET + PHYS_END)
    {
        *(.init.data)
    }
    . = ALIGN(4K);

    _init_end_kernel_start = .;

    /*  Virtually linked part of actual kernel code and data. Start/end is 4K aligned. */

    .text . : AT(ADDR(.text) - KERNEL_OFFSET + PHYS_END)
    {
        *(.text)
    }

    .rodata . : AT(ADDR(.rodata) - KERNEL_OFFSET + PHYS_END)
    {
        *(.rodata)
        *(.rodata.*)
    }

    .data . : AT(ADDR(.data) - KERNEL_OFFSET + PHYS_END)
    {
        *(.data) /* .data is empty, but linker crashes if it is not put here */
    }

    .bss . : AT(ADDR(.bss) - KERNEL_OFFSET + PHYS_END)
    {
        *(.bss)
        *(COMMON)
    }

    . = ALIGN(4K);
    _kernel_end = .;

    /DISCARD/ :
    {
        *(.*)
    }
}

