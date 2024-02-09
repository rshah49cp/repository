#ifndef IOstd
#define IOstd

#include "include_all.h"
#include "safe_ops.h"

void set_stdIO(FILE* input, FILE* output, int argc, char *argv[]);
void close_stdIO(FILE* input, FILE* output);

#endif