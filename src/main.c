#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/ihashmap.h"
#include "../include/ilist.h"
#include "../include/ivector.h"
#include "../include/iqueue.h"
#include "../include/safe_xallocs.h"

int
rand_range(int min, int max) {
    int range = max + 1 - min;
    return (rand() % range) + min;
}

IVector*
two_sum(IVector* nums, int nums_size, int target, int* return_size) {
    IHashMap* map = ihashmap_create(300);

    IVector* ret = ivector_create_empty();

    for (int i = 0; i < nums_size; i++) {
        int           comp = target - ivector_get(nums, i);
        NodeIHashMap* get  = ihashmap_get(map, comp);
        if (get) {
            ivector_insert(ret, nodeihashmap_get_value(get));
            ivector_insert(ret, i);
            *return_size = 2;

            ihashmap_destroy(map);
            return ret;
        }
        ihashmap_insert(map, ivector_get(nums, i), i);
    }
    *return_size = 0;
    ihashmap_destroy(map);
    printf("change for git testing\n");
    return ret;
}

int
main() {
    IQueue* iq = iqueue_create();
    iqueue_insert(iq, 10);
    iqueue_insert(iq, 69);
    iqueue_insert(iq, 39);
    iqueue_insert(iq, 59);
    iqueue_insert(iq, 20);
    iqueue_print(iq);
    iqueue_pop(iq);
    iqueue_print(iq);
    iqueue_insert(iq, 499);
    iqueue_print(iq);
    iqueue_pop(iq);
    iqueue_print(iq);
    iqueue_destroy(iq);


    return 0;
}
