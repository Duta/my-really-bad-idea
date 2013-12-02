#ifndef EMU6502_H
#define EMU6502_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
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
  /* Has flags testing */
  bool (*carry)(void *self);  /* Carry Flag */
  bool (*zero)(void *self);   /* Zero Flag */
  bool (*intdis)(void *self); /* Interrupt Disable */
  bool (*decmod)(void *self); /* Decimal Mode */
  bool (*brk)(void *self);    /* Break Command */
  bool (*over)(void *self);   /* Overflow Flag */
  bool (*neg)(void *self);    /* Negative Flag */
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

#endif /* EMU6502_H */
