#ifndef _IDTLOADER_H_
#define _IDTLOADER_H_

void load_idt();
void setup_IDT_entry (int index, uint64_t offset);

#endif
