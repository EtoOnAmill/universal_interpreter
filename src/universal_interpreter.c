#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "instructions.h"

void load_nth_program(String programs[], int nth);

int programs_count = 0;
FILE* program = NULL;

int main(int argc, String argv[]) {
    int current_program = 0;
    programs_count = argc - 1;
    char** programs = argv + 1;

    int buff_size = (1 + 2 + 16) * 8; // instruction, 4 parameters, immediate bytes
    Byte buffer[buff_size];
    for(int i=0; i<buff_size; i++) { buffer[i] = 0; }

    load_nth_program(programs, current_program);

    while(1) {

        size_t read = fread(buffer, ByteSize, buff_size, program);
        size_t total_read = read;

        if( feof(program) ) { rewind(program); }

        for(int i=0; i < buff_size && total_read < buff_size; i++) {
            Byte* new_buf_start = buffer + total_read;
            size_t new_buf_size = buff_size - total_read;

            read = fread(new_buf_start, ByteSize, new_buf_size, program);
            total_read += read;

            if( feof(program) ) { rewind(program); }
        }


        break;
    }


    if(program) {
        fclose(program);
    }

    Byte_hl hl = split(0x7a);
    return 0;
}



void load_program(String new_program) {
    if(program) { fclose(program); }

    program = fopen(new_program, "rb");

    if(!program) {
        fprintf(stderr, "Error in opening file %s\n", new_program);
        exit(INVALID_PROGRAM_PATH);
    }
    return;
}



void load_nth_program(String programs[], int nth) {
    if(programs_count) {
        load_program(programs[nth % programs_count]);
    } else {
        printf("no program provided\n");
        exit(NO_PROGRAM);
    }
}
