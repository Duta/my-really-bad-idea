#include <stdlib.h>
#include "emu6502.h"

void * emu6502_new() {
  emu6502 *emu = malloc(sizeof(emu6502));
  emu->ram = calloc(0x10000, sizeof(uint8_t));
  return emu;
} 

void emu6502_destroy(emu6502 *emu) {
  if(emu) {
    if(emu->ram) {
      free(emu->ram);
    } 
    free(emu);
  }
}

bool emu6502_carry(emu6502 *emu) {
  return emu->psw & (1 << 0) ? 1 : 0;
}

bool emu6502_zero(emu6502 *emu) {
  return emu->psw & (1 << 1) ? 1 : 0;
}

bool emu6502_intdis(emu6502 *emu) {
  return emu->psw & (1 << 2) ? 1 : 0;
} 

bool emu6502_decmod(emu6502 *emu) {
  return emu->psw & (1 << 3) ? 1 : 0;
} 

bool emu6502_brk(emu6502 *emu) {
  return emu->psw & (1 << 4) ? 1 : 0;
} 

bool emu6502_over(emu6502 *emu) {
  return emu->psw & (1 << 6) ? 1 : 0;
} 

bool emu6502_neg(emu6502 *emu) {
  return emu->psw & (1 << 7) ? 1 : 0;
} 

uint8_t emu6502_getbyte(emu6502 *emu, uint16_t addr) {
  return emu->ram[addr];
}

uint16_t emu6502_getword(emu6502 *emu, uint16_t addr) {
  return emu->ram[addr] + (emu->ram[addr+1] << 8);
}

uint8_t emu6502_immbyte(emu6502 *emu) {
  return emu->ram[emu->pc];
}

uint8_t emu6502_zeropgaddr(emu6502 *emu) {
  return emu->ram[emu->pc];
}

uint8_t emu6502_zeropgxaddr(emu6502 *emu) {
  return emu->x + emu->ram[emu->pc];
}

uint8_t emu6502_zeropgyaddr(emu6502 *emu) {
  return emu->y + emu->ram[emu->pc];
}

uint16_t emu6502_indxaddr(emu6502 *emu) {
  return emu6502_getword(emu, emu->x + emu->ram[emu->pc]);
}

