#include <stdlib.h>
#include "emu6502.h"

void * emu6502_new() {
  emu6502 *emu = malloc(sizeof(emu6502));

  emu->ram = calloc(0x10000, sizeof(uint8_t));

  emu->destroy = emu6502_destroy;

  emu->carry  = emu6502_carry;
  emu->zero   = emu6502_zero;
  emu->intdis = emu6502_intdis;
  emu->decmod = emu6502_decmod;
  emu->brk    = emu6502_brk;
  emu->over   = emu6502_over;
  emu->neg    = emu6502_neg;

  emu->getbyte      = emu6502_getbyte;
  emu->getword      = emu6502_getword;
  emu->immbyte      = emu6502_immbyte;
  emu->zeropgaddr   = emu6502_zeropgaddr;
  emu->zeropgxaddr  = emu6502_zeropgxaddr;
  emu->zeropgyaddr  = emu6502_zeropgyaddr;
  emu->indxaddr     = emu6502_indxaddr;

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

uint8_t emu6502_getbyte(void *self, uint16_t addr) {
  emu6502 *emu = self;
  return emu->ram[addr];
}

uint16_t emu6502_getword(void *self, uint16_t addr) {
  emu6502 *emu = self;
  return emu->ram[addr] + (emu->ram[addr+1] << 8);
}

uint8_t emu6502_immbyte(void *self) {
  emu6502 *emu = self;
  return emu->ram[emu->pc];
}

uint8_t emu6502_zeropgaddr(void *self) {
  emu6502 *emu = self;
  return emu->ram[emu->pc];
}

uint8_t emu6502_zeropgxaddr(void *self) {
  emu6502 *emu = self;
  return emu->x + emu->ram[emu->pc];
}

uint8_t emu6502_zeropgyaddr(void *self) {
  emu6502 *emu = self;
  return emu->y + emu->ram[emu->pc];
}

uint16_t emu6502_indxaddr(void *self) {
  emu6502 *emu = self;
  return emu->getword(emu, emu->x + emu->ram[emu->pc]);
}

