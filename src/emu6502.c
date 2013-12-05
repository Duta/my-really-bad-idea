#include <stdlib.h>
#include "emu6502.h"

/* Forward Declaration macro */
#define FD(x) static void op##x(emu6502 *emu)
FD(00); FD(01); FD(02); FD(03); FD(04); FD(05); FD(06); FD(07);
FD(08); FD(09); FD(0A); FD(0B); FD(0C); FD(0D); FD(0E); FD(0F);
FD(10); FD(11); FD(12); FD(13); FD(14); FD(15); FD(16); FD(17);
FD(18); FD(19); FD(1A); FD(1B); FD(1C); FD(1D); FD(1E); FD(1F);
FD(20); FD(21); FD(22); FD(23); FD(24); FD(25); FD(26); FD(27);
FD(28); FD(29); FD(2A); FD(2B); FD(2C); FD(2D); FD(2E); FD(2F);
FD(30); FD(31); FD(32); FD(33); FD(34); FD(35); FD(36); FD(37);
FD(38); FD(39); FD(3A); FD(3B); FD(3C); FD(3D); FD(3E); FD(3F);
FD(40); FD(41); FD(42); FD(43); FD(44); FD(45); FD(46); FD(47);
FD(48); FD(49); FD(4A); FD(4B); FD(4C); FD(4D); FD(4E); FD(4F);
FD(50); FD(51); FD(52); FD(53); FD(54); FD(55); FD(56); FD(57);
FD(58); FD(59); FD(5A); FD(5B); FD(5C); FD(5D); FD(5E); FD(5F);
FD(60); FD(61); FD(62); FD(63); FD(64); FD(65); FD(66); FD(67);
FD(68); FD(69); FD(6A); FD(6B); FD(6C); FD(6D); FD(6E); FD(6F);
FD(70); FD(71); FD(72); FD(73); FD(74); FD(75); FD(76); FD(77);
FD(78); FD(79); FD(7A); FD(7B); FD(7C); FD(7D); FD(7E); FD(7F);
FD(80); FD(81); FD(82); FD(83); FD(84); FD(85); FD(86); FD(87);
FD(88); FD(89); FD(8A); FD(8B); FD(8C); FD(8D); FD(8E); FD(8F);
FD(90); FD(91); FD(92); FD(93); FD(94); FD(95); FD(96); FD(97);
FD(98); FD(99); FD(9A); FD(9B); FD(9C); FD(9D); FD(9E); FD(9F);
FD(A0); FD(A1); FD(A2); FD(A3); FD(A4); FD(A5); FD(A6); FD(A7);
FD(A8); FD(A9); FD(AA); FD(AB); FD(AC); FD(AD); FD(AE); FD(AF);
FD(B0); FD(B1); FD(B2); FD(B3); FD(B4); FD(B5); FD(B6); FD(B7);
FD(B8); FD(B9); FD(BA); FD(BB); FD(BC); FD(BD); FD(BE); FD(BF);
FD(C0); FD(C1); FD(C2); FD(C3); FD(C4); FD(C5); FD(C6); FD(C7);
FD(C8); FD(C9); FD(CA); FD(CB); FD(CC); FD(CD); FD(CE); FD(CF);
FD(D0); FD(D1); FD(D2); FD(D3); FD(D4); FD(D5); FD(D6); FD(D7);
FD(D8); FD(D9); FD(DA); FD(DB); FD(DC); FD(DD); FD(DE); FD(DF);
FD(E0); FD(E1); FD(E2); FD(E3); FD(E4); FD(E5); FD(E6); FD(E7);
FD(E8); FD(E9); FD(EA); FD(EB); FD(EC); FD(ED); FD(EE); FD(EF);
FD(F0); FD(F1); FD(F2); FD(F3); FD(F4); FD(F5); FD(F6); FD(F7);
FD(F8); FD(F9); FD(FA); FD(FB); FD(FC); FD(FD); FD(FE); FD(FF);
#undef FD

void (*inslookup[256])(emu6502 *emu) = {
  op00, op01, op02, op03, op04, op05, op06, op07,
  op08, op09, op0A, op0B, op0C, op0D, op0E, op0F,
  op10, op11, op12, op13, op14, op15, op16, op17,
  op18, op19, op1A, op1B, op1C, op1D, op1E, op1F,
  op20, op21, op22, op23, op24, op25, op26, op27,
  op28, op29, op2A, op2B, op2C, op2D, op2E, op2F,
  op30, op31, op32, op33, op34, op35, op36, op37,
  op38, op39, op3A, op3B, op3C, op3D, op3E, op3F,
  op40, op41, op42, op43, op44, op45, op46, op47,
  op48, op49, op4A, op4B, op4C, op4D, op4E, op4F,
  op50, op51, op52, op53, op54, op55, op56, op57,
  op58, op59, op5A, op5B, op5C, op5D, op5E, op5F,
  op60, op61, op62, op63, op64, op65, op66, op67,
  op68, op69, op6A, op6B, op6C, op6D, op6E, op6F,
  op70, op71, op72, op73, op74, op75, op76, op77,
  op78, op79, op7A, op7B, op7C, op7D, op7E, op7F,
  op80, op81, op82, op83, op84, op85, op86, op87,
  op88, op89, op8A, op8B, op8C, op8D, op8E, op8F,
  op90, op91, op92, op93, op94, op95, op96, op97,
  op98, op99, op9A, op9B, op9C, op9D, op9E, op9F,
  opA0, opA1, opA2, opA3, opA4, opA5, opA6, opA7,
  opA8, opA9, opAA, opAB, opAC, opAD, opAE, opAF,
  opB0, opB1, opB2, opB3, opB4, opB5, opB6, opB7,
  opB8, opB9, opBA, opBB, opBC, opBD, opBE, opBF,
  opC0, opC1, opC2, opC3, opC4, opC5, opC6, opC7,
  opC8, opC9, opCA, opCB, opCC, opCD, opCE, opCF,
  opD0, opD1, opD2, opD3, opD4, opD5, opD6, opD7,
  opD8, opD9, opDA, opDB, opDC, opDD, opDE, opDF,
  opE0, opE1, opE2, opE3, opE4, opE5, opE6, opE7,
  opE8, opE9, opEA, opEB, opEC, opED, opEE, opEF,
  opF0, opF1, opF2, opF3, opF4, opF5, opF6, opF7,
  opF8, opF9, opFA, opFB, opFC, opFD, opFE, opFF
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
  inslookup[ins](emu);
}

#define CARRY_BIT  0
#define ZERO_BIT   1
#define INTDIS_BIT 2
#define DECMOD_BIT 3
#define BRK_BIT    4
#define OVER_BIT   6
#define NEG_BIT    7

#define GET_FLAG(x) !!(emu->psw & (1 << x))
#define SET_FLAG(x) emu->psw |= 1 << x
#define CLR_FLAG(x) emu->psw &= ~(1 << x)

bool emu6502_carry(emu6502 *emu) {
  return GET_FLAG(CARRY_BIT);
}

bool emu6502_zero(emu6502 *emu) {
  return GET_FLAG(ZERO_BIT);
}

bool emu6502_intdis(emu6502 *emu) {
  return GET_FLAG(INTDIS_BIT);
}

bool emu6502_decmod(emu6502 *emu) {
  return GET_FLAG(DECMOD_BIT);
}

bool emu6502_brk(emu6502 *emu) {
  return GET_FLAG(BRK_BIT);
}

bool emu6502_over(emu6502 *emu) {
  return GET_FLAG(OVER_BIT);
}

bool emu6502_neg(emu6502 *emu) {
  return GET_FLAG(NEG_BIT);
}

void emu6502_setcarry(emu6502 *emu) {
  SET_FLAG(CARRY_BIT);
}

void emu6502_setzero(emu6502 *emu) {
  SET_FLAG(ZERO_BIT);
}

void emu6502_setintdis(emu6502 *emu) {
  SET_FLAG(INTDIS_BIT);
}

void emu6502_setdecmod(emu6502 *emu) {
  SET_FLAG(DECMOD_BIT);
}

void emu6502_setbrk(emu6502 *emu) {
  SET_FLAG(BRK_BIT);
}

void emu6502_setover(emu6502 *emu) {
  SET_FLAG(OVER_BIT);
}

void emu6502_setneg(emu6502 *emu) {
  SET_FLAG(NEG_BIT);
}

void emu6502_clrcarry(emu6502 *emu) {
  CLR_FLAG(CARRY_BIT);
}

void emu6502_clrzero(emu6502 *emu) {
  CLR_FLAG(ZERO_BIT);
}

void emu6502_clrintdis(emu6502 *emu) {
  CLR_FLAG(INTDIS_BIT);
}

void emu6502_clrdecmod(emu6502 *emu) {
  CLR_FLAG(DECMOD_BIT);
}

void emu6502_clrbrk(emu6502 *emu) {
  CLR_FLAG(BRK_BIT);
}

void emu6502_clrover(emu6502 *emu) {
  CLR_FLAG(OVER_BIT);
}

void emu6502_clrneg(emu6502 *emu) {
  CLR_FLAG(NEG_BIT);
}

#undef GET_FLAG
#undef SET_FLAG
#undef CLR_FLAG
/* Other undefs after opXX functions */

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
  uint16_t b = a + emu->y;
  emu6502_addifpgcrs(emu, a, b);
  return b;
}

uint16_t emu6502_absaddr(emu6502 *emu) {
  return emu6502_getword(emu, emu->pc);
}

uint16_t emu6502_absxaddr(emu6502 *emu) {
  uint16_t a = emu6502_getword(emu, emu->pc);
  uint16_t b = a + emu->x;
  emu6502_addifpgcrs(emu, a, b);
  return b;
}

uint16_t emu6502_absyaddr(emu6502 *emu) {
  uint16_t a = emu6502_getword(emu, emu->pc);
  uint16_t b = a + emu->x;
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

#define STACK_OFF 0x100
void emu6502_push(emu6502 *emu, uint8_t val) {
  emu->ram[--emu->sp + STACK_OFF] = val;
}

uint8_t emu6502_pop(emu6502 *emu) {
  return emu->ram[emu->sp++ + STACK_OFF];
}
#undef STACK_OFF

void emu6502_pushword(emu6502 *emu, uint16_t val) {
  emu6502_push(emu, 0xFF & (val >> 8));
  emu6502_push(emu, 0xFF & val);
}

uint16_t emu6502_popword(emu6502 *emu) {
  uint16_t val = emu6502_pop(emu);
  val += emu6502_pop(emu) << 8;
  return val;
}

/* Comments for opXX functions is from: */
/* www.atarimax.com/jindroush.atari.org/aopc.html */

#define ADD_CYCS(x) emu->cycs += x

/* Syntax: BRK */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 7 */
static void op00(emu6502 *emu) {

}

/* Syntax: ORA ($44,X) */
/* Mode: Indirect,X */
/* Bytes: 2 */
/* Time: 6 */
static void op01(emu6502 *emu) {
  ADD_CYCS(6);
  emu->acc |= emu6502_indxaddr(emu);
  if(emu->acc & (1 << NEG_BIT))
    emu6502_setneg(emu);
  else
    emu6502_clrneg(emu);
  if(emu->acc)
    emu6502_clrzero(emu);
  else
    emu6502_setzero(emu);
}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op02(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op03(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op04(emu6502 *emu) {

}

/* Syntax: ORA $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 2 */
static void op05(emu6502 *emu) {
  ADD_CYCS(2);
  emu->acc |= emu6502_zeropgaddr(emu);
  if(emu->acc & (1 << NEG_BIT))
    emu6502_setneg(emu);
  else
    emu6502_clrneg(emu);
  if(emu->acc)
    emu6502_clrzero(emu);
  else
    emu6502_setzero(emu);
}

/* Syntax: ASL $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 5 */
static void op06(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op07(emu6502 *emu) {

}

/* Syntax: PHP */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 3 */
static void op08(emu6502 *emu) {

}

/* Syntax: ORA #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void op09(emu6502 *emu) {
  ADD_CYCS(2);
  emu->acc |= emu6502_immbyte(emu);
  if(emu->acc & (1 << NEG_BIT))
    emu6502_setneg(emu);
  else
    emu6502_clrneg(emu);
  if(emu->acc)
    emu6502_clrzero(emu);
  else
    emu6502_setzero(emu);
}

/* Syntax: ASL A */
/* Mode: Accumulator */
/* Bytes: 1 */
/* Time: 2 */
static void op0A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op0B(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op0C(emu6502 *emu) {

}

/* Syntax: ORA $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void op0D(emu6502 *emu) {

}

/* Syntax: ASL $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 6 */
static void op0E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op0F(emu6502 *emu) {

}

/* Syntax: BPL */
/* Mode: - */
/* Bytes: 2 */
/* Time: 2 (+1 if branch taken, +1 if page boundary crossed) */
static void op10(emu6502 *emu) {

}

/* Syntax: ORA ($44),Y */
/* Mode: Indirect,Y */
/* Bytes: 2 */
/* Time: 5 (+1 if page boundary crossed) */
static void op11(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op12(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op13(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op14(emu6502 *emu) {

}

/* Syntax: ORA $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 3 */
static void op15(emu6502 *emu) {

}

/* Syntax: ASL $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 6 */
static void op16(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op17(emu6502 *emu) {

}

/* Syntax: CLC */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void op18(emu6502 *emu) {

}

/* Syntax: ORA $4400,Y */
/* Mode: Absolute,Y */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void op19(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op1A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op1B(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op1C(emu6502 *emu) {

}

/* Syntax: ORA $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void op1D(emu6502 *emu) {

}

/* Syntax: ASL $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 7 */
static void op1E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op1F(emu6502 *emu) {

}

/* Syntax: JSR $5597 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 6 */
static void op20(emu6502 *emu) {

}

/* Syntax: AND ($44,X) */
/* Mode: Indirect,X */
/* Bytes: 2 */
/* Time: 6 */
static void op21(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op22(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op23(emu6502 *emu) {

}

/* Syntax: BIT $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void op24(emu6502 *emu) {

}

/* Syntax: AND $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 2 */
static void op25(emu6502 *emu) {

}

/* Syntax: ROL $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 5 */
static void op26(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op27(emu6502 *emu) {

}

/* Syntax: PLP */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 4 */
static void op28(emu6502 *emu) {

}

/* Syntax: AND #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void op29(emu6502 *emu) {

}

/* Syntax: ROL A */
/* Mode: Accumulator */
/* Bytes: 1 */
/* Time: 2 */
static void op2A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op2B(emu6502 *emu) {

}

/* Syntax: BIT $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void op2C(emu6502 *emu) {

}

/* Syntax: AND $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void op2D(emu6502 *emu) {

}

/* Syntax: ROL $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 6 */
static void op2E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op2F(emu6502 *emu) {

}

/* Syntax: BMI */
/* Mode: - */
/* Bytes: 2 */
/* Time: 2 (+1 if branch taken, +1 if page boundary crossed) */
static void op30(emu6502 *emu) {

}

/* Syntax: AND ($44),Y */
/* Mode: Indirect,Y */
/* Bytes: 2 */
/* Time: 5 (+1 if page boundary crossed) */
static void op31(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op32(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op33(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op34(emu6502 *emu) {

}

/* Syntax: AND $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 3 */
static void op35(emu6502 *emu) {

}

/* Syntax: ROL $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 6 */
static void op36(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op37(emu6502 *emu) {

}

/* Syntax: SEC */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void op38(emu6502 *emu) {

}

/* Syntax: AND $4400,Y */
/* Mode: Absolute,Y */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void op39(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op3A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op3B(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op3C(emu6502 *emu) {

}

/* Syntax: AND $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void op3D(emu6502 *emu) {

}

/* Syntax: ROL $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 7 */
static void op3E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op3F(emu6502 *emu) {

}

/* Syntax: RTI */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 6 */
static void op40(emu6502 *emu) {

}

/* Syntax: EOR ($44,X) */
/* Mode: Indirect,X */
/* Bytes: 2 */
/* Time: 6 */
static void op41(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op42(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op43(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op44(emu6502 *emu) {

}

/* Syntax: EOR $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void op45(emu6502 *emu) {

}

/* Syntax: LSR $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 5 */
static void op46(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op47(emu6502 *emu) {

}

/* Syntax: PHA */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 3 */
static void op48(emu6502 *emu) {

}

/* Syntax: EOR #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void op49(emu6502 *emu) {

}

/* Syntax: LSR A */
/* Mode: Accumulator */
/* Bytes: 1 */
/* Time: 2 */
static void op4A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op4B(emu6502 *emu) {

}

/* Syntax: JMP $5597 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 3 */
static void op4C(emu6502 *emu) {

}

/* Syntax: EOR $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void op4D(emu6502 *emu) {

}

/* Syntax: LSR $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 6 */
static void op4E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op4F(emu6502 *emu) {

}

/* Syntax: BVC */
/* Mode: - */
/* Bytes: 2 */
/* Time: 2 (+1 if branch taken, +1 if page boundary crossed) */
static void op50(emu6502 *emu) {

}

/* Syntax: EOR ($44),Y */
/* Mode: Indirect,Y */
/* Bytes: 2 */
/* Time: 5 (+1 if page boundary crossed) */
static void op51(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op52(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op53(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op54(emu6502 *emu) {

}

/* Syntax: EOR $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 4 */
static void op55(emu6502 *emu) {

}

/* Syntax: LSR $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 6 */
static void op56(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op57(emu6502 *emu) {

}

/* Syntax: CLI */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void op58(emu6502 *emu) {

}

/* Syntax: EOR $4400,Y */
/* Mode: Absolute,Y */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void op59(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op5A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op5B(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op5C(emu6502 *emu) {

}

/* Syntax: EOR $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void op5D(emu6502 *emu) {

}

/* Syntax: LSR $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 7 */
static void op5E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op5F(emu6502 *emu) {

}

/* Syntax: RTS */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 6 */
static void op60(emu6502 *emu) {

}

/* Syntax: ADC ($44,X) */
/* Mode: Indirect,X */
/* Bytes: 2 */
/* Time: 6 */
static void op61(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op62(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op63(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op64(emu6502 *emu) {

}

/* Syntax: ADC $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void op65(emu6502 *emu) {

}

/* Syntax: ROR $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 5 */
static void op66(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op67(emu6502 *emu) {

}

/* Syntax: PLA */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 4 */
static void op68(emu6502 *emu) {

}

/* Syntax: ADC #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void op69(emu6502 *emu) {

}

/* Syntax: ROR A */
/* Mode: Accumulator */
/* Bytes: 1 */
/* Time: 2 */
static void op6A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op6B(emu6502 *emu) {

}

/* Syntax: JMP ($5597) */
/* Mode: Indirect */
/* Bytes: 3 */
/* Time: 5 */
static void op6C(emu6502 *emu) {

}

/* Syntax: ADC $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void op6D(emu6502 *emu) {

}

/* Syntax: ROR $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 6 */
static void op6E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op6F(emu6502 *emu) {

}

/* Syntax: BVS */
/* Mode: - */
/* Bytes: 2 */
/* Time: 2 (+1 if branch taken, +1 if page boundary crossed) */
static void op70(emu6502 *emu) {

}

/* Syntax: ADC ($44),Y */
/* Mode: Indirect,Y */
/* Bytes: 2 */
/* Time: 5 (+1 if page boundary crossed) */
static void op71(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op72(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op73(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op74(emu6502 *emu) {

}

/* Syntax: ADC $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 4 */
static void op75(emu6502 *emu) {

}

/* Syntax: ROR $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 6 */
static void op76(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op77(emu6502 *emu) {

}

/* Syntax: SEI */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void op78(emu6502 *emu) {

}

/* Syntax: ADC $4400,Y */
/* Mode: Absolute,Y */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void op79(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op7A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op7B(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op7C(emu6502 *emu) {

}

/* Syntax: ADC $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void op7D(emu6502 *emu) {

}

/* Syntax: ROR $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 7 */
static void op7E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op7F(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op80(emu6502 *emu) {

}

/* Syntax: STA ($44,X) */
/* Mode: Indirect,X */
/* Bytes: 2 */
/* Time: 6 */
static void op81(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op82(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op83(emu6502 *emu) {

}

/* Syntax: STY $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void op84(emu6502 *emu) {

}

/* Syntax: STA $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void op85(emu6502 *emu) {

}

/* Syntax: STX $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void op86(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op87(emu6502 *emu) {

}

/* Syntax: DEY */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void op88(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op89(emu6502 *emu) {

}

/* Syntax: TXA */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void op8A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op8B(emu6502 *emu) {

}

/* Syntax: STY $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void op8C(emu6502 *emu) {

}

/* Syntax: STA $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void op8D(emu6502 *emu) {

}

/* Syntax: STX $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void op8E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op8F(emu6502 *emu) {

}

/* Syntax: BCC */
/* Mode: - */
/* Bytes: 2 */
/* Time: 2 (+1 if branch taken, +1 if page boundary crossed) */
static void op90(emu6502 *emu) {

}

/* Syntax: STA ($44),Y */
/* Mode: Indirect,Y */
/* Bytes: 2 */
/* Time: 6 */
static void op91(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op92(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op93(emu6502 *emu) {

}

/* Syntax: STY $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 4 */
static void op94(emu6502 *emu) {

}

/* Syntax: STA $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 4 */
static void op95(emu6502 *emu) {

}

/* Syntax: STX $44,Y */
/* Mode: Zero Page,Y */
/* Bytes: 2 */
/* Time: 4 */
static void op96(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op97(emu6502 *emu) {

}

/* Syntax: TYA */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void op98(emu6502 *emu) {

}

/* Syntax: STA $4400,Y */
/* Mode: Absolute,Y */
/* Bytes: 3 */
/* Time: 5 */
static void op99(emu6502 *emu) {

}

/* Syntax: TXS */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void op9A(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op9B(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op9C(emu6502 *emu) {

}

/* Syntax: STA $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 5 */
static void op9D(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op9E(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void op9F(emu6502 *emu) {

}

/* Syntax: LDY #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void opA0(emu6502 *emu) {

}

/* Syntax: LDA ($44,X) */
/* Mode: Indirect,X */
/* Bytes: 2 */
/* Time: 6 */
static void opA1(emu6502 *emu) {

}

/* Syntax: LDX #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void opA2(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opA3(emu6502 *emu) {

}

/* Syntax: LDY $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void opA4(emu6502 *emu) {

}

/* Syntax: LDA $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void opA5(emu6502 *emu) {

}

/* Syntax: LDX $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void opA6(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opA7(emu6502 *emu) {

}

/* Syntax: TAY */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opA8(emu6502 *emu) {

}

/* Syntax: LDA #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void opA9(emu6502 *emu) {

}

/* Syntax: TAX */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opAA(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opAB(emu6502 *emu) {

}

/* Syntax: LDY $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void opAC(emu6502 *emu) {

}

/* Syntax: LDA $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void opAD(emu6502 *emu) {

}

/* Syntax: LDX $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void opAE(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opAF(emu6502 *emu) {

}

/* Syntax: BCS */
/* Mode: - */
/* Bytes: 2 */
/* Time: 2 (+1 if branch taken, +1 if page boundary crossed) */
static void opB0(emu6502 *emu) {

}

/* Syntax: LDA ($44),Y */
/* Mode: Indirect,Y */
/* Bytes: 2 */
/* Time: 5 (+1 if page boundary crossed) */
static void opB1(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opB2(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opB3(emu6502 *emu) {

}

/* Syntax: LDY $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 4 */
static void opB4(emu6502 *emu) {

}

/* Syntax: LDA $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 4 */
static void opB5(emu6502 *emu) {

}

/* Syntax: LDX $44,Y */
/* Mode: Zero Page,Y */
/* Bytes: 2 */
/* Time: 4 */
static void opB6(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opB7(emu6502 *emu) {

}

/* Syntax: CLV */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opB8(emu6502 *emu) {

}

/* Syntax: LDA $4400,Y */
/* Mode: Absolute,Y */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void opB9(emu6502 *emu) {

}

/* Syntax: TSX */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opBA(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opBB(emu6502 *emu) {

}

/* Syntax: LDY $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void opBC(emu6502 *emu) {

}

/* Syntax: LDA $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void opBD(emu6502 *emu) {

}

/* Syntax: LDX $4400,Y */
/* Mode: Absolute,Y */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void opBE(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opBF(emu6502 *emu) {

}

/* Syntax: CPY #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void opC0(emu6502 *emu) {

}

/* Syntax: CMP ($44,X) */
/* Mode: Indirect,X */
/* Bytes: 2 */
/* Time: 6 */
static void opC1(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opC2(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opC3(emu6502 *emu) {

}

/* Syntax: CPY $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void opC4(emu6502 *emu) {

}

/* Syntax: CMP $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void opC5(emu6502 *emu) {

}

/* Syntax: DEC $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 5 */
static void opC6(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opC7(emu6502 *emu) {

}

/* Syntax: INY */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opC8(emu6502 *emu) {

}

/* Syntax: CMP #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void opC9(emu6502 *emu) {

}

/* Syntax: DEX */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opCA(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opCB(emu6502 *emu) {

}

/* Syntax: CPY $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void opCC(emu6502 *emu) {

}

/* Syntax: CMP $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void opCD(emu6502 *emu) {

}

/* Syntax: DEC $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 6 */
static void opCE(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opCF(emu6502 *emu) {

}

/* Syntax: BNE */
/* Mode: - */
/* Bytes: 2 */
/* Time: 2 (+1 if branch taken, +1 if page boundary crossed) */
static void opD0(emu6502 *emu) {

}

/* Syntax: CMP ($44),Y */
/* Mode: Indirect,Y */
/* Bytes: 2 */
/* Time: 5 (+1 if page boundary crossed) */
static void opD1(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opD2(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opD3(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opD4(emu6502 *emu) {

}

/* Syntax: CMP $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 4 */
static void opD5(emu6502 *emu) {

}

/* Syntax: DEC $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 6 */
static void opD6(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opD7(emu6502 *emu) {

}

/* Syntax: CLD */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opD8(emu6502 *emu) {

}

/* Syntax: CMP $4400,Y */
/* Mode: Absolute,Y */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void opD9(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opDA(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opDB(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opDC(emu6502 *emu) {

}

/* Syntax: CMP $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void opDD(emu6502 *emu) {

}

/* Syntax: DEC $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 7 */
static void opDE(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opDF(emu6502 *emu) {

}

/* Syntax: CPX #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void opE0(emu6502 *emu) {

}

/* Syntax: SBC ($44,X) */
/* Mode: Indirect,X */
/* Bytes: 2 */
/* Time: 6 */
static void opE1(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opE2(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opE3(emu6502 *emu) {

}

/* Syntax: CPX $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void opE4(emu6502 *emu) {

}

/* Syntax: SBC $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 3 */
static void opE5(emu6502 *emu) {

}

/* Syntax: INC $44 */
/* Mode: Zero Page */
/* Bytes: 2 */
/* Time: 5 */
static void opE6(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opE7(emu6502 *emu) {

}

/* Syntax: INX */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opE8(emu6502 *emu) {

}

/* Syntax: SBC #$44 */
/* Mode: Immediate */
/* Bytes: 2 */
/* Time: 2 */
static void opE9(emu6502 *emu) {

}

/* Syntax: NOP */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opEA(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opEB(emu6502 *emu) {

}

/* Syntax: CPX $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void opEC(emu6502 *emu) {

}

/* Syntax: SBC $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 4 */
static void opED(emu6502 *emu) {

}

/* Syntax: INC $4400 */
/* Mode: Absolute */
/* Bytes: 3 */
/* Time: 6 */
static void opEE(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opEF(emu6502 *emu) {

}

/* Syntax: BEQ */
/* Mode: - */
/* Bytes: 2 */
/* Time: 2 (+1 if branch taken, +1 if page boundary crossed) */
static void opF0(emu6502 *emu) {

}

/* Syntax: SBC ($44),Y */
/* Mode: Indirect,Y */
/* Bytes: 2 */
/* Time: 5 (+1 if page boundary crossed) */
static void opF1(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opF2(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opF3(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opF4(emu6502 *emu) {

}

/* Syntax: SBC $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 4 */
static void opF5(emu6502 *emu) {

}

/* Syntax: INC $44,X */
/* Mode: Zero Page,X */
/* Bytes: 2 */
/* Time: 6 */
static void opF6(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opF7(emu6502 *emu) {

}

/* Syntax: SED */
/* Mode: Implied */
/* Bytes: 1 */
/* Time: 2 */
static void opF8(emu6502 *emu) {

}

/* Syntax: SBC $4400,Y */
/* Mode: Absolute,Y */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void opF9(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opFA(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opFB(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opFC(emu6502 *emu) {

}

/* Syntax: SBC $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 4 (+1 if page boundary crossed) */
static void opFD(emu6502 *emu) {

}

/* Syntax: INC $4400,X */
/* Mode: Absolute,X */
/* Bytes: 3 */
/* Time: 7 */
static void opFE(emu6502 *emu) {

}

/* Syntax: ? */
/* Mode: ? */
/* Bytes: ? */
/* Time: ? */
static void opFF(emu6502 *emu) {

}

#undef ADD_CYCS

#undef CARRY_BIT
#undef ZERO_BIT
#undef INTDIS_BIT
#undef DECMOD_BIT
#undef BRK_BIT
#undef OVER_BIT
#undef NEG_BIT
