#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "eof_logic.c"

void load_program(String new_program);
void load_nth_program(String programs[], int nth);

enum exit_value {
    NO_ERROR,
    INVALID_PROGRAM_PATH,
};

int programs_count = 0;
FILE* program = NULL;

int main(int argc, String argv[]) {
    int current_program = 0;
    programs_count = argc - 1;
    char** programs = argv + 1;

    int buff_size = (1 + 2 + 16) * 8; // instruction, 4 parameters, immediate bytes
    Byte buffer[buff_size];

    load_nth_program(programs, current_program);
    (void*) setvbuf(program, (char*)buffer, _IOFBF, buff_size);

    while(1) {
        break;
    }

    if(program) {
        fclose(program);
    }
    return 0;
}


void load_nth_program(String programs[], int nth) {
    if(programs_count) {
        load_program(programs[nth % programs_count]);
    } else {
        printf("no program provided\n");
    }
}

void load_program(String new_program) {
    if(!program) {
        fclose(program);
    }
    program = fopen(new_program, "rb");

    if(program == NULL) {
        fprintf(stderr, "Error in opening file %s\n", new_program);
        exit(INVALID_PROGRAM_PATH);
    }
    return;
}
