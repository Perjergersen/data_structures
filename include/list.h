#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeIList NodeIList;
typedef struct IList     IList;

NodeIList* nodeilist_create(int data);
IList*     ilist_create();
void       ilist_add(IList* list, int data);
void       ilist_print(IList* list);
void       ilist_destroy(IList* list);
int        ilist_get_size(IList* list);
int        ilist_get_data(IList* list, uint32_t index);

#endif
