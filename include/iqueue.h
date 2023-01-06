#ifndef IQUEUE
#define IQUEUE

#include <stdio.h>

#include "safe_xallocs.h"

typedef struct IQueueNode IQueueNode;
typedef struct IQueue     IQueue;

IQueueNode* iqueuenode_create(int data);
IQueue*     iqueue_create();
void        iqueue_insert(IQueue* iq, int data);
int         iqueue_pop(IQueue* iq);
IQueueNode* iqueue_next(IQueue* iq);
int         iqueuenode_get_data(IQueueNode* iq);
void        iqueue_print(IQueue* iq);
void        iqueue_destroy(IQueue* iq);

#endif
