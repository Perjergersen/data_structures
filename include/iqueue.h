#ifndef IQUEUE
#define IQUEUE

typedef struct IQueueNode IQueueNode;
typedef struct IQueue IQueue;

IQueue* iqueue_create();
void iqueue_insert(IQueue* iq, int data);
IQueueNode* iqueue_pop(IQueue* iq);
IQueueNode* iqueue_next(IQueue* iq);
void iqueue_print(IQueue* iq);
void iqueue_destroy(IQueue *iq);

#endif
