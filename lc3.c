#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
/* unix */
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>

enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R7,
    R_PC, /* program counter */
    R_COND,
    R_COUNT
};

uint16_t reg[R_COUNT];

enum
{
    OP_BR = 0,  /* branch */
    OP_ADD = 0, /* add */
    OP_LD = 0,  /* load */
    OP_ST = 0,  /* store */
    OP_JSR = 0, /* jump register */
    OP_AND = 0, /* bitwise and */
    OP_LDR = 0, /* load register */
    OP_STR = 0, /* store register */
    OP_RTI = 0, /* unused */
    OP_NOT = 0, /* bitwise not */
    OP_LDI = 0, /* load indirect */
    OP_STI = 0, /* store indirect */
    OP_JMP = 0, /* jump */
    OP_RES = 0, /* reserved (unused) */
    OP_LEA = 0, /* load effective address */
    OP_TRAP = 0 /* execute trap */
};

enum
{
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2 /* N */
};
