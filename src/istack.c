#include "../include/istack.h"

struct IStackNode {
    int         data;
    IStackNode* next;
};

struct IStack {
    IStackNode* head;
    IStackNode* tail;
    int         size;
};

IStackNode*
istacknode_create(int data) {
    IStackNode* isn = smalloc(sizeof(IStackNode));
    isn->data       = data;
    isn->next       = NULL;
    return isn;
}

IStack*
istack_create() {
    IStack* is = smalloc(sizeof(IStack));
    is->head   = NULL;
    is->tail   = NULL;
    is->size   = 0;
    return is;
}

void
istack_insert(IStack* is, int data) {
    IStackNode* new_node = istacknode_create(data);

    if (is->head == NULL) {
        is->head = new_node;
        is->tail = new_node;
        is->size += 1;
        return;
    }

    new_node->next = is->head;
    is->head       = new_node;

    is->size += 1;
}

int
istack_pop(IStack* is) {
    if (is == NULL || is->size <= 0) {
        fprintf(stderr,
                "istack_pop: IStack* is is either NULL or has size 0\n");
        exit(EXIT_FAILURE);
    }
    int         ret      = is->head->data;
    IStackNode* del_node = is->head;
    is->head             = is->head->next;
    free(del_node);
    del_node = NULL;

    is->size -= 1;

    return ret;
}

IStackNode*
istack_next(IStack* is) {
    return is->head;
}
void
istack_print(IStack* is) {
    IStackNode* curr = is->head;
    printf("Stack: T[");
    while (curr) {
        printf("%d", curr->data);
        curr = curr->next;
        if (curr != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

int
istacknode_get_data(IStackNode* is) {
    return is->data;
}

void
istack_destroy(IStack* is) {
    IStackNode* curr = is->head;
    while (curr) {
        IStackNode* prev = curr;
        curr             = curr->next;
        free(prev);
        prev = NULL;
    }
    free(is);
    is = NULL;
}
