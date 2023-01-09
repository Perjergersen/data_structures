#include "../include/ilist.h"

struct IListNode {
    int               data;
    struct IListNode* next;
};

struct IList {
    IListNode* head;
    IListNode* tail;
    uint32_t   size;
};

IListNode*
ilistnode(int data) {
    IListNode* nil = smalloc(sizeof(IListNode));
    nil->data      = data;
    nil->next      = NULL;
    return nil;
}

IList*
ilist_empty() {
    IList* il = smalloc(sizeof(IList));
    il->head  = NULL;
    il->tail  = NULL;
    il->size  = 0;
    return il;
}

IList*
ilist(int num_of_list_elements, ...) {
    IList*  il = ilist_empty();
    va_list args;
    va_start(args, num_of_list_elements);

    for (int i = 0; i < num_of_list_elements; i++) {
        ilist_insert(il, va_arg(args, int));
    }

    va_end(args);
    return il;
}

void
ilist_insert(IList* list, int data) {
    IListNode* new = ilistnode(data);

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
    IListNode* curr = list->head;

    printf("List: [");
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
    IListNode* curr = list->head;

    while (curr) {
        IListNode* prev = curr;
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
    IListNode* curr = list->head;

    if (index > list->size - 1) {
        fprintf(stderr, "ilist_get_data(): index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    for (uint32_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}
