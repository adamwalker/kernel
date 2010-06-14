#include <sysenter.h>
#include <types.h>
#include <machine.h>
#include <gdt.h>

extern void handle_sysenter(void);

void setup_sysenter_msrs(void){
	wrmsr(IA32_SYSENTER_CS_MSR,  (uint32_t)GDT_CS_0);
    wrmsr(IA32_SYSENTER_EIP_MSR, (uint32_t)&handle_sysenter);
    wrmsr(IA32_SYSENTER_ESP_MSR, 0); 
}

