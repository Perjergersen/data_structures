#ifndef IVECTOR
#define IVECTOR

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "safe_xallocs.h"

typedef struct IVector IVector;

IVector* ivector_create_empty();
IVector* ivector_create(int num_of_vec_elements, ...);
void     ivector_insert(IVector* iv, int data);
void     ivector_print(IVector* iv);
int      ivector_get(IVector* iv, int index);
int      ivector_size(IVector* iv);
void     ivector_destroy(IVector* iv);

#endif
