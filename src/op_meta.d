module op_meta;

import std.bitmanip;

enum : byte {
    END_OF_PROGRAM,
}

extern(C) {
    struct instruction;
    struct expanded_instruction {
        ubyte op;
        ubyte dst;
        ubyte mod;
        union {
            struct Reg_Reg {
                ubyte reg1;
                ubyte reg2;
                ubyte reserved;
            }
            struct Reg_Imm {
                ubyte reg1;
                ushort half_immediate; 
            }
            uint immediate;
        }
    }
    expanded_instruction expand(instruction* instruction);
    struct Byte_hl {
        byte high;
        byte low;
    }
    Byte_hl split(ubyte b);
}



// the value will be negative if the operation has an immediate
public int get_op_arity(byte op) {
    switch(op) {
        case END_OF_PROGRAM:
        default:
            return 0;
    }
}
