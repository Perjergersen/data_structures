#include "../include/ilist.h"

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
    NodeIList* nil = smalloc(sizeof(NodeIList));
    nil->data      = data;
    nil->next      = NULL;
    return nil;
}

IList*
ilist_create_empty() {
    IList* il = smalloc(sizeof(IList));
    il->head  = NULL;
    il->tail  = NULL;
    il->size  = 0;
    return il;
}

IList*
ilist_create(int num_of_list_elements, ...) {
    IList*  il = ilist_create_empty();
    va_list args;
    va_start(args, num_of_list_elements);

    for (int i = 0; i < num_of_list_elements; i++) {
        ilist_add(il, va_arg(args, int));
    }

    va_end(args);
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

    printf("[");
    while (curr) {
        printf("%d", curr->data);
        if (curr->next != NULL) {
            printf(", ");
        }
        curr = curr->next;
    }
    printf("]\n");
}
void
ilist_destroy(IList* list) {
    NodeIList* curr = list->head;

    while (curr) {
        NodeIList* prev = curr;
        curr            = curr->next;
        free(prev);
        prev = NULL;
    }
    free(list);
    list = NULL;
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
