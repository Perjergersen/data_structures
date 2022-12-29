#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/ihashmap.h"
#include "../include/ilist.h"

void* safe_malloc(size_t bytes, int line_number, char* file);

#define s_malloc(x) safe_malloc(x, __LINE__, __FILE__)

void*
safe_malloc(size_t bytes, int line_number, char* file) {
    void* s = malloc(bytes);

    if (s && bytes) {
        return s;
    }

    fprintf(stderr,
            "\033[0;31mLine: %d - safe_malloc() failed.\nFile: %s\n\033[0m",
            line_number, file);
    exit(EXIT_FAILURE);
}

struct Person {
    int grade;
    int age;
};

int*
twoSum(int* nums, int numsSize, int target, int* returnSize) {
    returnSize   = malloc(sizeof(int) * 2);
    IHashMap* hm = ihashmap_create(16);

    for (int i = 0; i < numsSize; i++) {
        int comp = target - nums[i];
        NodeIHashMap* try
            = ihashmap_get(hm, comp);
        if (try) {
            returnSize[0] = nodeihashmap_get_value(try);
            returnSize[1] = i;
            printf("\n");
            ihashmap_print(hm);
            ihashmap_destroy(hm);
            printf("\n");
            return returnSize;
        }
        ihashmap_add(hm, nums[i], i);
    }
    return NULL;
}

int
main() {
#ifdef TWOSUM
    int  nums[]    = {2, 7, 11, 15};
    int  size      = sizeof(nums) / sizeof(nums[0]);
    int  targ      = 26;
    int* returnArr = twoSum(nums, size, targ, returnArr);

    printf("[%d,%d]\n", returnArr[0], returnArr[1]);

    free(returnArr);
    returnArr = NULL;
#endif

    IHashMap* hm = ihashmap_create(1000);
    ihashmap_add(hm, 10, 0);
    ihashmap_add(hm, 492, 1);
    ihashmap_add(hm, 488, 2);
    ihashmap_add(hm, 93, 3);
    ihashmap_add(hm, 590, 4);
    ihashmap_add(hm, 182, 5);
    ihashmap_add(hm, 4995, 6);
    ihashmap_add(hm, -283, 7);
    ihashmap_add(hm, 9283, 8);
    ihashmap_add(hm, -283, 100);

    ihashmap_print(hm);

    ihashmap_destroy(hm);

    return 0;
}
