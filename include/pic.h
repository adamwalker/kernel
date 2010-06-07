#ifndef __PIC_H
#define __PIC_H

void PIC_send_EOI(unsigned char irq);
void PIC_remap(int offset1, int offset2);

#endif
