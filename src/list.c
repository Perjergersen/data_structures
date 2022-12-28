#include "../include/list.h"
#include <stdlib.h>

struct NodeIList {
    int               data;
    struct NodeIList* next;
};

struct IList {
    NodeIList* head;
    NodeIList* tail;
    uint32_t   size;
};

NodeIList*
nodeilist_create(int data) {
    NodeIList* nil = malloc(sizeof(NodeIList));
    nil->data      = data;
    nil->next      = NULL;
    return nil;
}

IList*
ilist_create() {
    IList* il = malloc(sizeof(IList));
    il->head  = NULL;
    il->tail  = NULL;
    il->size  = 0;
    return il;
}

void
ilist_add(IList* list, int data) {
    NodeIList* new = nodeilist_create(data);

    if (list->head == NULL && list->tail == NULL) {
        list->head = new;
        list->tail = new;
        list->size++;
    } else {
        list->tail->next = new;
        list->tail       = list->tail->next;
        list->size++;
    }
}

void
ilist_print(IList* list) {
    NodeIList* curr = list->head;

    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}
void
ilist_destroy(IList* list) {
    NodeIList* curr = list->head;

    while (curr) {
        NodeIList* prev = curr;
        curr            = curr->next;
        free(prev);
    }
    free(list);
}

int
ilist_get_size(IList* list) {
    return list->size;
}

int
ilist_get_data(IList* list, uint32_t index) {
    NodeIList* curr = list->head;

    if (index > list->size - 1) {
        fprintf(stderr, "ilist_get_data(): index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    for (uint32_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}
