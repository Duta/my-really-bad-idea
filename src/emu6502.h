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
bool emu6502_carry(emu6502 *emu);   /* Carry Flag          */
bool emu6502_zero(emu6502 *emu);    /* Zero Flag           */
bool emu6502_intdis(emu6502 *emu);  /* Interrupts Disabled */
bool emu6502_decmod(emu6502 *emu);  /* Decimal Mode        */
bool emu6502_brk(emu6502 *emu);     /* Break Command       */
bool emu6502_over(emu6502 *emu);    /* Overflow Flag       */
bool emu6502_neg(emu6502 *emu);     /* Negative Flag       */

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
void op10(emu6502 *emu);
void op11(emu6502 *emu);
void op12(emu6502 *emu);
void op13(emu6502 *emu);
void op14(emu6502 *emu);
void op15(emu6502 *emu);
void op16(emu6502 *emu);
void op17(emu6502 *emu);
void op18(emu6502 *emu);
void op19(emu6502 *emu);
void op1A(emu6502 *emu);
void op1B(emu6502 *emu);
void op1C(emu6502 *emu);
void op1D(emu6502 *emu);
void op1E(emu6502 *emu);
void op1F(emu6502 *emu);
void op20(emu6502 *emu);
void op21(emu6502 *emu);
void op22(emu6502 *emu);
void op23(emu6502 *emu);
void op24(emu6502 *emu);
void op25(emu6502 *emu);
void op26(emu6502 *emu);
void op27(emu6502 *emu);
void op28(emu6502 *emu);
void op29(emu6502 *emu);
void op2A(emu6502 *emu);
void op2B(emu6502 *emu);
void op2C(emu6502 *emu);
void op2D(emu6502 *emu);
void op2E(emu6502 *emu);
void op2F(emu6502 *emu);
void op30(emu6502 *emu);
void op31(emu6502 *emu);
void op32(emu6502 *emu);
void op33(emu6502 *emu);
void op34(emu6502 *emu);
void op35(emu6502 *emu);
void op36(emu6502 *emu);
void op37(emu6502 *emu);
void op38(emu6502 *emu);
void op39(emu6502 *emu);
void op3A(emu6502 *emu);
void op3B(emu6502 *emu);
void op3C(emu6502 *emu);
void op3D(emu6502 *emu);
void op3E(emu6502 *emu);
void op3F(emu6502 *emu);
void op40(emu6502 *emu);
void op41(emu6502 *emu);
void op42(emu6502 *emu);
void op43(emu6502 *emu);
void op44(emu6502 *emu);
void op45(emu6502 *emu);
void op46(emu6502 *emu);
void op47(emu6502 *emu);
void op48(emu6502 *emu);
void op49(emu6502 *emu);
void op4A(emu6502 *emu);
void op4B(emu6502 *emu);
void op4C(emu6502 *emu);
void op4D(emu6502 *emu);
void op4E(emu6502 *emu);
void op4F(emu6502 *emu);
void op50(emu6502 *emu);
void op51(emu6502 *emu);
void op52(emu6502 *emu);
void op53(emu6502 *emu);
void op54(emu6502 *emu);
void op55(emu6502 *emu);
void op56(emu6502 *emu);
void op57(emu6502 *emu);
void op58(emu6502 *emu);
void op59(emu6502 *emu);
void op5A(emu6502 *emu);
void op5B(emu6502 *emu);
void op5C(emu6502 *emu);
void op5D(emu6502 *emu);
void op5E(emu6502 *emu);
void op5F(emu6502 *emu);
void op60(emu6502 *emu);
void op61(emu6502 *emu);
void op62(emu6502 *emu);
void op63(emu6502 *emu);
void op64(emu6502 *emu);
void op65(emu6502 *emu);
void op66(emu6502 *emu);
void op67(emu6502 *emu);
void op68(emu6502 *emu);
void op69(emu6502 *emu);
void op6A(emu6502 *emu);
void op6B(emu6502 *emu);
void op6C(emu6502 *emu);
void op6D(emu6502 *emu);
void op6E(emu6502 *emu);
void op6F(emu6502 *emu);
void op70(emu6502 *emu);
void op71(emu6502 *emu);
void op72(emu6502 *emu);
void op73(emu6502 *emu);
void op74(emu6502 *emu);
void op75(emu6502 *emu);
void op76(emu6502 *emu);
void op77(emu6502 *emu);
void op78(emu6502 *emu);
void op79(emu6502 *emu);
void op7A(emu6502 *emu);
void op7B(emu6502 *emu);
void op7C(emu6502 *emu);
void op7D(emu6502 *emu);
void op7E(emu6502 *emu);
void op7F(emu6502 *emu);
void op80(emu6502 *emu);
void op81(emu6502 *emu);
void op82(emu6502 *emu);
void op83(emu6502 *emu);
void op84(emu6502 *emu);
void op85(emu6502 *emu);
void op86(emu6502 *emu);
void op87(emu6502 *emu);
void op88(emu6502 *emu);
void op89(emu6502 *emu);
void op8A(emu6502 *emu);
void op8B(emu6502 *emu);
void op8C(emu6502 *emu);
void op8D(emu6502 *emu);
void op8E(emu6502 *emu);
void op8F(emu6502 *emu);
void op90(emu6502 *emu);
void op91(emu6502 *emu);
void op92(emu6502 *emu);
void op93(emu6502 *emu);
void op94(emu6502 *emu);
void op95(emu6502 *emu);
void op96(emu6502 *emu);
void op97(emu6502 *emu);
void op98(emu6502 *emu);
void op99(emu6502 *emu);
void op9A(emu6502 *emu);
void op9B(emu6502 *emu);
void op9C(emu6502 *emu);
void op9D(emu6502 *emu);
void op9E(emu6502 *emu);
void op9F(emu6502 *emu);
void opA0(emu6502 *emu);
void opA1(emu6502 *emu);
void opA2(emu6502 *emu);
void opA3(emu6502 *emu);
void opA4(emu6502 *emu);
void opA5(emu6502 *emu);
void opA6(emu6502 *emu);
void opA7(emu6502 *emu);
void opA8(emu6502 *emu);
void opA9(emu6502 *emu);
void opAA(emu6502 *emu);
void opAB(emu6502 *emu);
void opAC(emu6502 *emu);
void opAD(emu6502 *emu);
void opAE(emu6502 *emu);
void opAF(emu6502 *emu);
void opB0(emu6502 *emu);
void opB1(emu6502 *emu);
void opB2(emu6502 *emu);
void opB3(emu6502 *emu);
void opB4(emu6502 *emu);
void opB5(emu6502 *emu);
void opB6(emu6502 *emu);
void opB7(emu6502 *emu);
void opB8(emu6502 *emu);
void opB9(emu6502 *emu);
void opBA(emu6502 *emu);
void opBB(emu6502 *emu);
void opBC(emu6502 *emu);
void opBD(emu6502 *emu);
void opBE(emu6502 *emu);
void opBF(emu6502 *emu);
void opC0(emu6502 *emu);
void opC1(emu6502 *emu);
void opC2(emu6502 *emu);
void opC3(emu6502 *emu);
void opC4(emu6502 *emu);
void opC5(emu6502 *emu);
void opC6(emu6502 *emu);
void opC7(emu6502 *emu);
void opC8(emu6502 *emu);
void opC9(emu6502 *emu);
void opCA(emu6502 *emu);
void opCB(emu6502 *emu);
void opCC(emu6502 *emu);
void opCD(emu6502 *emu);
void opCE(emu6502 *emu);
void opCF(emu6502 *emu);
void opD0(emu6502 *emu);
void opD1(emu6502 *emu);
void opD2(emu6502 *emu);
void opD3(emu6502 *emu);
void opD4(emu6502 *emu);
void opD5(emu6502 *emu);
void opD6(emu6502 *emu);
void opD7(emu6502 *emu);
void opD8(emu6502 *emu);
void opD9(emu6502 *emu);
void opDA(emu6502 *emu);
void opDB(emu6502 *emu);
void opDC(emu6502 *emu);
void opDD(emu6502 *emu);
void opDE(emu6502 *emu);
void opDF(emu6502 *emu);
void opE0(emu6502 *emu);
void opE1(emu6502 *emu);
void opE2(emu6502 *emu);
void opE3(emu6502 *emu);
void opE4(emu6502 *emu);
void opE5(emu6502 *emu);
void opE6(emu6502 *emu);
void opE7(emu6502 *emu);
void opE8(emu6502 *emu);
void opE9(emu6502 *emu);
void opEA(emu6502 *emu);
void opEB(emu6502 *emu);
void opEC(emu6502 *emu);
void opED(emu6502 *emu);
void opEE(emu6502 *emu);
void opEF(emu6502 *emu);
void opF0(emu6502 *emu);
void opF1(emu6502 *emu);
void opF2(emu6502 *emu);
void opF3(emu6502 *emu);
void opF4(emu6502 *emu);
void opF5(emu6502 *emu);
void opF6(emu6502 *emu);
void opF7(emu6502 *emu);
void opF8(emu6502 *emu);
void opF9(emu6502 *emu);
void opFA(emu6502 *emu);
void opFB(emu6502 *emu);
void opFC(emu6502 *emu);
void opFD(emu6502 *emu);
void opFE(emu6502 *emu);
void opFF(emu6502 *emu);

#endif /* EMU6502_H */
