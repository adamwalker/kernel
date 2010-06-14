#ifndef __SYSENTER_H
#define __SYSENTER_H

#define IA32_SYSENTER_CS_MSR    0x174
#define IA32_SYSENTER_ESP_MSR   0x175
#define IA32_SYSENTER_EIP_MSR   0x176

void setup_sysenter_msrs(void);

#endif

