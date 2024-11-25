#pragma once
#ifndef instructions_h_INCLUDED
#define instructions_h_INCLUDED

#include <string.h>
#include "types.h"

enum type_op {
    IMMEDIATE,
    REG_IMM,
};

struct instruction {
    Byte op : 8;
    Byte dst : 4;
    Byte mod : 4;
    union {
        struct {
            Byte reg1 : 4;
            Byte reg2 : 4;
            Byte reg3 : 4;
            Byte reserved : 4;
        } regs;
        struct {
            Byte reg : 4;
            HWord half_immediate : 12; 
        } reg_imm;
        Word immediate : 16;
    } params;
};

struct expanded_instruction {
    Byte op;
    Byte dst;
    Byte mod;
    union {
        struct {
            Byte reg1;
            Byte reg2;
            Byte reg3;
            Byte reserved;
        } regs;
        struct {
            Byte reg;
            HWord half_immediate; 
        } reg_imm;
        Word immediate;
    } params;
};

typedef struct {
    Byte high;
    Byte low;
} Byte_hl;

Byte_hl split(Byte b);

#endif // instructions_h_INCLUDED
