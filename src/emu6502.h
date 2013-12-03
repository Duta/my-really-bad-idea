#ifndef EMU6502_H
#define EMU6502_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
  /* Memory */
  uint8_t *ram;
  /* Program Counter */
  uint16_t pc;
  /* Index Registers */
  uint8_t x, y;
  /* Accumulator */
  uint8_t acc;
  /* Processor Status Word */
  uint8_t psw;
  /* Stack Pointer */
  uint8_t sp;
  /* Flags Testing */
  bool (*carry)(void *self);  /* Carry Flag */
  bool (*zero)(void *self);   /* Zero Flag */
  bool (*intdis)(void *self); /* Interrupt Disable */
  bool (*decmod)(void *self); /* Decimal Mode */
  bool (*brk)(void *self);    /* Break Command */
  bool (*over)(void *self);   /* Overflow Flag */
  bool (*neg)(void *self);    /* Negative Flag */
  /* Helpful Methods */
  uint8_t (*getbyte)(void *self, uint16_t addr);
  uint16_t (*getword)(void *self, uint16_t addr);
  uint8_t (*immbyte)(void *self);
  uint8_t (*zeropgaddr)(void *self);
  uint8_t (*zeropgxaddr)(void *self);
  uint8_t (*zeropgyaddr)(void *self);
  uint16_t (*indxaddr)(void *self);
  /* Destructor */
  void (*destroy)(void *self);
} emu6502;

void * emu6502_new();
void emu6502_destroy(void *self);

bool emu6502_carry(void *self);
bool emu6502_zero(void *self);
bool emu6502_intdis(void *self);
bool emu6502_decmod(void *self);
bool emu6502_brk(void *self);
bool emu6502_over(void *self);
bool emu6502_neg(void *self);

uint8_t emu6502_getbyte(void *self, uint16_t addr);
uint16_t emu6502_getword(void *self, uint16_t addr);
uint8_t emu6502_immbyte(void *self);
uint8_t emu6502_zeropgaddr(void *self);
uint8_t emu6502_zeropgxaddr(void *self);
uint8_t emu6502_zeropgyaddr(void *self);
uint16_t emu6502_indxaddr(void *self);

#endif /* EMU6502_H */
