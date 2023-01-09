#ifndef IVECTOR
#define IVECTOR

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "safe_xallocs.h"

typedef struct IVec IVec;

IVec* ivec_empty();
IVec* ivec(int num_of_vec_elements, ...);
void     ivec_insert(IVec* iv, int data);
void     ivec_print(IVec* iv);
int      ivec_get(IVec* iv, int index);
int      ivec_size(IVec* iv);
void     ivec_destroy(IVec* iv);

#endif
