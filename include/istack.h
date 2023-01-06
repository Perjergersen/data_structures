#ifndef ISTACK
#define ISTACK

#include <stdio.h>

#include "safe_xallocs.h"

typedef struct IStackNode IStackNode;
typedef struct IStack     IStack;

IStackNode* istacknode_create(int data);
IStack*     istack_create();
void        istack_insert(IStack* is, int data);
int         istack_pop(IStack* is);
IStackNode* istack_next(IStack* is);
int         istacknode_get_data(IStackNode* is);
void        istack_print(IStack* is);
void        istack_destroy(IStack* is);

#endif
