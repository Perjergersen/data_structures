#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/ihashmap.h"
#include "../include/ilist.h"
#include "../include/iqueue.h"
#include "../include/istack.h"
#include "../include/ivector.h"
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
    IList* list = ilist_create(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    ilist_print(list);
    ilist_destroy(list);

    IQueue* iq = iqueue_create();
    for (int i = 0; i < 10; i++) {
        iqueue_insert(iq, i);
    }
    iqueue_print(iq);
    iqueue_pop(iq);
    iqueue_print(iq);
    iqueue_destroy(iq);

    IVector* iv = ivector_create(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    ivector_print(iv);
    ivector_destroy(iv);

    IHashMap* map = ihashmap_create(100);
    ihashmap_insert(map, 0, 0);
    ihashmap_insert(map, 1, 1);
    ihashmap_insert(map, 2, 2);
    ihashmap_insert(map, 3, 3);
    ihashmap_insert(map, 4, 4);
    ihashmap_insert(map, 5, 5);
    ihashmap_insert(map, 6, 6);
    ihashmap_insert(map, 7, 7);
    ihashmap_insert(map, 8, 8);
    ihashmap_insert(map, 9, 9);
    ihashmap_print(map);
    ihashmap_destroy(map);

    IStack* is = istack_create();
    istack_insert(is, 10);
    istack_insert(is, 11);
    istack_insert(is, 12);
    istack_insert(is, 13);
    istack_insert(is, 14);
    istack_insert(is, 15);
    istack_print(is);
    printf("%d\n", istack_pop(is));
    istack_print(is);
    istack_pop(is);
    istack_pop(is);
    istack_pop(is);
    istack_print(is);
    istack_destroy(is);

    NodeIList* il     = nodeilist_create(10);
    void*      il_ptr = il;

    printf("%d\n", *(int*) (il_ptr));
    *(int*) (il_ptr) = 20;
    printf("%d\n", *(int*) (il_ptr));

    return 0;
}
