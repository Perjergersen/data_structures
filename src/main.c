#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/ihashmap.h"
#include "../include/ilist.h"
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
    return ret;
}

int
main() {
    IVector* nums = ivector_create(4, 2, 5, 8, 10);
    ivector_print(nums);
    printf("%d\n", ivector_size(nums));
    int      target   = 12;
    int*     ret_size = smalloc(sizeof(int) * 1);
    IVector* ts       = two_sum(nums, ivector_size(nums), target, ret_size);
    ivector_print(ts);

    return 0;
}
