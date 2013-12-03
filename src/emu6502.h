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
  /* Cycles */
  uint32_t cycs;
  uint32_t excycs;
} emu6502;

/* Instruction lookup table */
extern void (*inslookup[256])(emu6502 *emu);

/* Constructor/Destructor */
void * emu6502_new();
void emu6502_destroy(emu6502 *emu);

/* Emulate */
void emu6502_emu(emu6502 *emu);
void emu6502_exeins(emu6502 *emu);

/* Flags Testing */
bool emu6502_carry(emu6502 *emu);   /* Carry Flag         */
bool emu6502_zero(emu6502 *emu);    /* Zero Flag          */
bool emu6502_intdis(emu6502 *emu);  /* Interrupt Disable  */
bool emu6502_decmod(emu6502 *emu);  /* Decimal Mode       */
bool emu6502_brk(emu6502 *emu);     /* Break Command      */
bool emu6502_over(emu6502 *emu);    /* Overflow Flag      */
bool emu6502_neg(emu6502 *emu);     /* Negative Flag      */

/* Helpful Functions */
/* Idea from 6502cpu.js */
void emu6502_addifpgcrs(emu6502 *emu, uint16_t a, uint16_t b);
uint8_t emu6502_getbyte(emu6502 *emu, uint16_t addr);
uint16_t emu6502_getword(emu6502 *emu, uint16_t addr);
uint8_t emu6502_immbyte(emu6502 *emu);
uint8_t emu6502_zeropgaddr(emu6502 *emu);
uint8_t emu6502_zeropgxaddr(emu6502 *emu);
uint8_t emu6502_zeropgyaddr(emu6502 *emu);
uint16_t emu6502_indxaddr(emu6502 *emu);
uint16_t emu6502_indyaddr(emu6502 *emu);
uint16_t emu6502_absaddr(emu6502 *emu);
uint16_t emu6502_absxaddr(emu6502 *emu);
uint16_t emu6502_absyaddr(emu6502 *emu);
void emu6502_bchreladdr(emu6502 *emu);
void emu6502_push(emu6502 *emu, uint8_t val);
uint8_t emu6502_pop(emu6502 *emu);
void emu6502_pushword(emu6502 *emu, uint16_t val);
uint16_t emu6502_popword(emu6502 *emu);

/* Opcode Functions */
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);
void op00(emu6502 *emu);
void op01(emu6502 *emu);
void op02(emu6502 *emu);
void op03(emu6502 *emu);
void op04(emu6502 *emu);
void op05(emu6502 *emu);
void op06(emu6502 *emu);
void op07(emu6502 *emu);
void op08(emu6502 *emu);
void op09(emu6502 *emu);
void op0A(emu6502 *emu);
void op0B(emu6502 *emu);
void op0C(emu6502 *emu);
void op0D(emu6502 *emu);
void op0E(emu6502 *emu);
void op0F(emu6502 *emu);

#endif /* EMU6502_H */
