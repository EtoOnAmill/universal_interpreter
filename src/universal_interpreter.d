import std.stdio;
import std.file : read;
import std.exception : ErrnoException;
import std.mmfile;
import std.range;
import std.math.algebraic;
import std.getopt;
import std.algorithm;

import op_meta;

// 1 instruction, 3 register parameters, 1 immediate parameter of maximum size
// 1 instruction, 64 register parameters :3
const enum Max_instruction_size = 1 * 2 * 16;

const enum Exit_code {
    NO_ERROR,
    OPTION_ERROR,
    FILE_ERROR,
    NO_PROGRAM_GIVEN_ERROR,
}

struct Program {
    MmFile source;
    byte[] src_bytes;
    size_t index = 0;

    this(string source) {
        this.source = new MmFile(source);
        this.src_bytes = cast(byte[]) source[];
    }
    byte get_op() {
        return src_bytes[index];
    }
}

// objective: calculate the sequence { a(n) = n(a(n-1) + 1), a(0) = 0 }
/*
rec sequence_a =
    > n; n iota! n fold!!(> i acc /; acc sequence_a(n 1 -) + <)
    \ 0; 0 <
rec sequence_b =
    > n; sequence_b(n 1 -) 1 + n *
    \ 0; 0 <
*/

// read n bytes from current_program file
// loop <n bytes were read

int main(string[] argv) {
try {
    string[] p,l;
    arraySep = ",";
    auto args = getopt(argv, 
        "p", &p,
        "l", &l);


    size_t curr_program = 0;
    Program[] programs;
    foreach(pp; p) {
        programs ~= [ Program(pp) ];
    }

    if(programs.empty) {
        writeln("No program was Given");
        writeln("Executing input from stdin");
        programs ~= [ Program() ];
    }

    Program[] libraries;
    foreach(ll; l) {
        libraries ~= [ Program(ll) ];
    }

// execution loop
    for(;;) {
        byte op = programs[curr_program].get_op();
        writefln("%x", op);
        writefln("%x", op_meta.split(op).low);
        writefln("%x", op_meta.split(op).high);
        break;
    }

    writeln(p, l, programs.length);

    return Exit_code.NO_ERROR;



}
catch (GetOptException e) {
    writeln("Error in given options: ", e.msg);
    return Exit_code.OPTION_ERROR;
}
catch (ErrnoException e) {
    writeln("Error in opening file: ", e.msg);
    return Exit_code.FILE_ERROR;
}
}
