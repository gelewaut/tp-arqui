/*
 *   interrupts.h
 *
 *  Created on: Apr 18, 2010
 *      Author: anizzomc
 */

#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#include <stdint.h>

void _cli(void);
void _sti(void);
void _hlt(void);
//Termina la ejecución de la cpu.
void haltcpu(void);

void picMasterMask(uint8_t mask);
void picSlaveMask(uint8_t mask);

void _irq00Handler(void);
void _irq01Handler(void);
void _irq02Handler(void);
void _irq03Handler(void);
void _irq04Handler(void);
void _irq05Handler(void);

void _exception0Handler(void);
void _exception6Handler(void);

void _sysCall80Handler(void);
void _writeAtHandler(void);
uint64_t _clockHandler(uint64_t code);
void _timerTickHandler(void);
void _infoRegHandler(void);
void _printMemHandler(void);
void _clearScreenHandler(void);

void saveRegs();
void nextReg();

#endif /* INTERRUPS_H_ */