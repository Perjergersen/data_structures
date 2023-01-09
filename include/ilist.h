#ifndef LIST_H
#define LIST_H

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "safe_xallocs.h"

typedef struct IListNode IListNode;
typedef struct IList     IList;

IListNode* ilistnode(int data);
IList*     ilist_empty();
IList*     ilist(int num_of_list_elements, ...);
void       ilist_insert(IList* list, int data);
void       ilist_print(IList* list);
void       ilist_destroy(IList* list);
int        ilist_get_size(IList* list);
int        ilist_get_data(IList* list, uint32_t index);

#endif
