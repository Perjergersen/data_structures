#include "../include/iqueue.h"

struct IQueueNode {
    int data;
    IQueueNode* next;
};

struct IQueue {
    IQueueNode* first;
};

IQueue* iqueue_create();
void iqueue_insert(IQueue* iq, int data);
IQueueNode* iqueue_pop(IQueue* iq);
IQueueNode* iqueue_next(IQueue* iq);
void iqueue_print(IQueue* iq);
void iqueue_destroy(IQueue *iq);

