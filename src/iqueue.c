#include "../include/iqueue.h"

struct IQueueNode {
    int         data;
    IQueueNode* next;
};

struct IQueue {
    IQueueNode* head;
    IQueueNode* tail;
    int         size;
};

IQueueNode*
iqueuenode_create(int data) {
    IQueueNode* iqn = smalloc(sizeof(IQueueNode));
    iqn->data       = data;
    iqn->next       = NULL;
    return iqn;
}

IQueue*
iqueue_create() {
    IQueue* iq = smalloc(sizeof(IQueue));
    iq->head   = NULL;
    iq->tail   = NULL;
    iq->size   = 0;
    return iq;
}

void
iqueue_insert(IQueue* iq, int data) {
    IQueueNode* new_node = iqueuenode_create(data);

    if (iq->head == NULL) {
        iq->head = new_node;
        iq->tail = new_node;
        iq->size += 1;
        return;
    }

    iq->tail->next = new_node;
    iq->tail       = new_node;
    iq->size += 1;
}

int
iqueue_pop(IQueue* iq) {
    if (iq == NULL || iq->size <= 0) {
        fprintf(stderr,
                "iqueue_pop: IQueue* iq is either NULL or has size 0\n");
        exit(EXIT_FAILURE);
    }
    int         ret      = iq->head->data;
    IQueueNode* del_node = iq->head;
    iq->head             = iq->head->next;
    free(del_node);
    del_node = NULL;

    iq->size -= 1;

    return ret;
}

IQueueNode*
iqueue_next(IQueue* iq) {
    return iq->head;
}
void
iqueue_print(IQueue* iq) {
    IQueueNode* curr = iq->head;
    printf("Queue: F[");
    while (curr) {
        printf("%d", curr->data);
        curr = curr->next;
        if (curr != NULL) {
            printf(", ");
        }
    }
    printf("]B\n");
}

int
iqueuenode_get_data(IQueueNode* iq) {
    return iq->data;
}

void
iqueue_destroy(IQueue* iq) {
    IQueueNode* curr = iq->head;
    while (curr) {
        IQueueNode* prev = curr;
        curr             = curr->next;
        free(prev);
        prev = NULL;
    }
    free(iq);
    iq = NULL;
}
