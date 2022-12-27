#include "../include/list.h"

struct NodeIList {
    int               data;
    struct NodeIList* next;
};

struct IList {
    NodeIList* head;
    NodeIList* tail;
    int        size;
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
    } else {
        list->tail->next = new;
        list->tail       = list->tail->next;
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
