#include "emu6502.h"

void * emu6502_new() {
  emu6502 *emu = malloc(sizeof(emu6502));
  emu->destroy = emu6502_destroy;
  emu->carry = emu6502_carry;
  emu->zero = emu6502_zero;
  emu->intdis = emu6502_intdis;
  emu->decmod = emu6502_decmod;
  emu->brk = emu6502_brk;
  emu->over = emu6502_over;
  emu->neg = emu6502_neg;
  return emu;
} 

void emu6502_destroy(void *self) {
  emu6502 *emu = self;
  if(emu) {
    free(emu);
  }
}

bool emu6502_carry(void *self) {
  emu6502 *emu = self;
  return emu->psw & (1 << 0) ? 1 : 0;
}

bool emu6502_zero(void *self) {
  emu6502 *emu = self;
  return emu->psw & (1 << 1) ? 1 : 0;
}

bool emu6502_intdis(void *self) {
  emu6502 *emu = self;
  return emu->psw & (1 << 2) ? 1 : 0;
} 

bool emu6502_decmod(void *self) {
  emu6502 *emu = self;
  return emu->psw & (1 << 3) ? 1 : 0;
} 

bool emu6502_brk(void *self) {
  emu6502 *emu = self;
  return emu->psw & (1 << 4) ? 1 : 0;
} 

bool emu6502_over(void *self) {
  emu6502 *emu = self;
  return emu->psw & (1 << 6) ? 1 : 0;
} 

bool emu6502_neg(void *self) {
  emu6502 *emu = self;
  return emu->psw & (1 << 7) ? 1 : 0;
} 

