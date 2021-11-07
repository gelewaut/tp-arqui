#include <stdint.h>
#include <defs.h>
#include <interrupts.h>
#include <idtLoader.h>

#pragma pack(push)		/* Push de la alineación actual */
#pragma pack (1) 		/* Alinear las siguiente estructuras a 1 byte */

/* Descriptor de interrupcion */
typedef struct {
  uint16_t offset_l, selector;
  uint8_t cero, access;
  uint16_t offset_m;
  uint32_t offset_h, other_cero;
} DESCR_INT;

#pragma pack(pop)		/* Reestablece la alinceación actual */

DESCR_INT * idt = (DESCR_INT *) 0;	// IDT de 255 entradas

void load_idt() {
  _cli();

// Exceptions

  // divide by zero
  setup_IDT_entry(0x00, (uint64_t)&_exception0Handler);

  // Invalid OPCODE
  setup_IDT_entry(0x06, (uint64_t)&_exception6Handler);

// Interruptions
  setup_IDT_entry(0x20, (uint64_t)&_irq00Handler); //Timer Tick
  setup_IDT_entry(0x21, (uint64_t)&_irq01Handler); //Teclado

  setup_IDT_entry(0x80, (uint64_t)&_sysCall80Handler);
  setup_IDT_entry(0x81, (uint64_t)&_writeAtHandler);
  setup_IDT_entry(0x82, (uint64_t)&_clockHandler);
  setup_IDT_entry(0x83, (uint64_t)&_timerTickHandler);
  setup_IDT_entry(0x84, (uint64_t)&_infoRegHandler);
  setup_IDT_entry(0x85, (uint64_t)&_printMemHandler);
  setup_IDT_entry(0x86, (uint64_t)&_clearScreenHandler);


	//0xFE Solo interrupcion timer tick habilitadas
	//0xFC Timer tick y teclado habilitadas
  picMasterMask(0xFC); 
	picSlaveMask(0xFF);
        
	_sti();
}

void setup_IDT_entry (int index, uint64_t offset) {
  idt[index].selector = 0x08;
  idt[index].offset_l = offset & 0xFFFF;
  idt[index].offset_m = (offset >> 16) & 0xFFFF;
  idt[index].offset_h = (offset >> 32) & 0xFFFFFFFF;
  idt[index].access = ACS_INT;
  idt[index].cero = 0;
  idt[index].other_cero = (uint64_t) 0;
}