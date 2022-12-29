#include "../include/ihashmap.h"
#include <stdbool.h>
#include <stdio.h>
#include "nptest.h"

int
test_nodeihashmap_create() {
    NodeIHashMap* node  = nodeihashmap_create(10, 20);
    bool          test1 = ASSERT(node != NULL);
    void*         vp    = node;
    bool          test2 = ASSERT(*(int*) (vp) == 10);
    bool          test3 = ASSERT(*(int*) (vp + 4) == 20);
    free(node);

    return test1 + test2 + test3;
}

int
test_ihashmap_create() {
    IHashMap* hm    = ihashmap_create(10000);
    bool      test1 = ASSERT(hm != NULL);
    ihashmap_destroy(hm);
    return test1;
}

int
test_ihashmap_add() {
    IHashMap* hm = ihashmap_create(10000);
    ihashmap_add(hm, 10, 20);
    ihashmap_add(hm, 20, 30);
    ihashmap_add(hm, -20, 59);
    ihashmap_add(hm, -399, 40);
    bool test1 = ASSERT(nodeihashmap_get_value(ihashmap_get(hm, 10)) == 20);
    bool test2 = ASSERT(nodeihashmap_get_value(ihashmap_get(hm, 20)) == 30);
    bool test3 = ASSERT(nodeihashmap_get_value(ihashmap_get(hm, -20)) == 59);
    bool test4 = ASSERT(nodeihashmap_get_value(ihashmap_get(hm, -399)) == 40);
    ihashmap_destroy(hm);
    return test1 + test2 + test3 + test4;
}

int
test_ihashmap_get_value() {
    IHashMap* hm = ihashmap_create(10000);
    ihashmap_add(hm, 10, 20);
    ihashmap_add(hm, 20, 30);
    ihashmap_add(hm, -20, 59);
    ihashmap_add(hm, -399, 40);
    bool test1 = ASSERT(nodeihashmap_get_value(ihashmap_get(hm, 10)) == 20);
    bool test2 = ASSERT(nodeihashmap_get_value(ihashmap_get(hm, 20)) == 30);
    bool test3 = ASSERT(nodeihashmap_get_value(ihashmap_get(hm, -20)) == 59);
    bool test4 = ASSERT(nodeihashmap_get_value(ihashmap_get(hm, -399)) == 40);
    ihashmap_destroy(hm);
    return test1 + test2 + test3 + test4;
}

int
test_ihashmap_print() {
    return 1;
}

int
test_ihashmap_destroy() {
    IHashMap* hm = ihashmap_create(10000);
    ihashmap_add(hm, 10, 20);
    ihashmap_add(hm, 20, 300);
    ihashmap_add(hm, -20, 400);
    ihashmap_destroy(hm);
    return 1;
}

int
test_hash_int() {
    return 1;
}

int
main() {
    printf("\033[0;33m--- TEST FILE : %s ---\033[0m\n", __FILE__);

    int test1 = test_nodeihashmap_create();
    int test2 = test_ihashmap_create();
    int test3 = test_ihashmap_add();
    int test4 = test_ihashmap_get_value();
    int test5 = test_ihashmap_destroy();
    int test6 = test_hash_int();

    int number_of_asserts = 14;
    int tests_passed      = test1 + test2 + test3 + test4 + test5 + test6;

    if (tests_passed == number_of_asserts) {
        printf("\033[0;32m%d / %d Passed\033[0m\n", tests_passed,
               number_of_asserts);
    } else {
        printf("\033[0;31m%d / %d Passed\033[0m\n", tests_passed,
               number_of_asserts);
    }

    printf("\033[0;33m--- TEST FILE : %s ---\033[0m\n\n", __FILE__);
    return 0;
}
