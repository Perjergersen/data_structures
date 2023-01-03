#ifndef IVECTOR
#define IVECTOR

#include <stdio.h>
#include <stdlib.h>

#include "safe_xallocs.h"

typedef struct IVector IVector;

IVector* ivector_create();
void     ivector_insert(IVector* iv, int data);
void     ivector_print(IVector* iv);
int      ivector_get(IVector* iv, int index);
int      ivector_size(IVector* iv);
void     ivector_destroy(IVector* iv);

#endif
