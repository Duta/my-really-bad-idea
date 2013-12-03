#include <stdlib.h>
#include "emu6502.h"

void (*inslookup[256])(uint8_t val) = {
  /* TODO */
};

void * emu6502_new() {
  emu6502 *emu = malloc(sizeof(emu6502));
  emu->ram = calloc(0x10000, sizeof(uint8_t));
  emu->pc = 0;
  emu->x = 0;
  emu->y = 0;
  emu->acc = 0;
  emu->psw = 0;
  emu->sp = 0;
  emu->cycs = 0;
  emu->excycs = 0;
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

void emu6502_emu(emu6502 *emu) {
  while(!emu6502_brk(emu)) {
    emu6502_exeins(emu);
  }
} 

void emu6502_exeins(emu6502 *emu) {
  uint8_t ins = emu->ram[emu->pc++];
  /* TODO */
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

void emu6502_addifpgcrs(emu6502 *emu, uint16_t a, uint16_t b) {
  if((a & 0xFF00) != (b & 0xFF00)) {
    emu->excycs++;
  }
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

uint16_t emu6502_indyaddr(emu6502 *emu) {
  uint16_t a = emu6502_getword(emu, emu->ram[emu->pc]);
  uint16_t b = (a + emu->y);
  emu6502_addifpgcrs(emu, a, b);
  return b;
} 

uint16_t emu6502_absaddr(emu6502 *emu) {
  return emu6502_getword(emu, emu->pc);
}

uint16_t emu6502_absxaddr(emu6502 *emu) {
  uint16_t a = emu6502_getword(emu, emu->pc);
  uint16_t b = (a + emu->x);
  emu6502_addifpgcrs(emu, a, b);
  return b;
}

uint16_t emu6502_absyaddr(emu6502 *emu) {
  uint16_t a = emu6502_getword(emu, emu->pc);
  uint16_t b = (a + emu->x);
  emu6502_addifpgcrs(emu, a, b);
  return b;
}

void emu6502_bchreladdr(emu6502 *emu) {
  emu->excycs++;
  uint8_t addr = emu->ram[emu->pc++];
  addr = addr & 0x80 ? emu->pc - (addr ^ 255) - 1 : emu->pc + addr;
  emu6502_addifpgcrs(emu, emu->pc, addr);
  emu->pc = addr;
}

void emu6502_push(emu6502 *emu, uint8_t val) {
  emu->ram[--emu->sp + 0x100] = val;
}

uint8_t emu6502_pop(emu6502 *emu) {
  return emu->ram[emu->sp++ + 0x100];
}

void emu6502_pushword(emu6502 *emu, uint16_t val) {
  emu6502_push(emu, 0xFF & (val >> 8));
  emu6502_push(emu, 0xFF & val);
} 

uint16_t emu6502_popword(emu6502 *emu) {
  uint16_t val = emu6502_pop(emu);
  val += emu6502_pop(emu) << 8;
  return val;
}

