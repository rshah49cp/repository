#include "IOstd.h"


/*
update this file as needed for additional arguments when running executable
*/

void set_stdIO(FILE* input, FILE* output, int argc, char *argv[]){
    switch(argc){
        case 1: /* do nothing, keep original input and output directions */
            input = stdin; /* defaults just in case */
            output = stdout;
        break;

        case 2:
            input = safe_fopen(argv[1], "r"); /* read from a file */
            output = stdout;
        break;

        case 3:
            input = safe_fopen(argv[1], "r"); /* read from a file */
            output = safe_fopen(argv[2], "w"); /* write to a file */
        break;

        default:
            perror("Too many arguments");
        break;
    }

    /* so Werror does not complain about unused values */
    (void)input; 
    (void)output;

}

void close_stdIO(FILE* input, FILE* output){
    if (input != stdin){
        fclose(input);
    }

    if (output != stdout){
        fclose(output);
    }
}