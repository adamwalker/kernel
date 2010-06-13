#ifndef __ISR_H
#define __ISR_H

struct regs {
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;
};

void fault_handler(struct regs *r);

extern void int_00(void);
extern void int_01(void);
extern void int_02(void);
extern void int_03(void);
extern void int_04(void);
extern void int_05(void);
extern void int_06(void);
extern void int_07(void);
extern void int_08(void);
extern void int_09(void);
extern void int_0a(void);
extern void int_0b(void);
extern void int_0c(void);
extern void int_0d(void);
extern void int_0e(void);
extern void int_0f(void);
extern void int_10(void);
extern void int_11(void);
extern void int_12(void);
extern void int_13(void);
extern void int_14(void);
extern void int_15(void);
extern void int_16(void);
extern void int_17(void);
extern void int_18(void);
extern void int_19(void);
extern void int_1a(void);
extern void int_1b(void);
extern void int_1c(void);
extern void int_1d(void);
extern void int_1e(void);
extern void int_1f(void);
extern void int_20(void);
extern void int_21(void);
extern void int_22(void);
extern void int_23(void);
extern void int_24(void);
extern void int_25(void);
extern void int_26(void);
extern void int_27(void);
extern void int_28(void);
extern void int_29(void);
extern void int_2a(void);
extern void int_2b(void);
extern void int_2c(void);
extern void int_2d(void);
extern void int_2e(void);
extern void int_2f(void);

#endif
