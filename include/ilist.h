#ifndef LIST_H
#define LIST_H

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "safe_xallocs.h"

typedef struct NodeIList NodeIList;
typedef struct IList     IList;

NodeIList* nodeilist_create(int data);
IList*     ilist_create_empty();
IList*     ilist_create(int num_of_list_elements, ...);
void       ilist_insert(IList* list, int data);
void       ilist_print(IList* list);
void       ilist_destroy(IList* list);
int        ilist_get_size(IList* list);
int        ilist_get_data(IList* list, uint32_t index);

#endif
