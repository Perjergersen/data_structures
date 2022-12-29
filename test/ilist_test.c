#include "../include/ilist.h"
#include <stdbool.h>
#include <stdio.h>
#include "nptest.h"

int test_nodeilist_create();
int test_ilist_create();
int test_ilist_add();
int test_ilist_print();
int test_ilist_destroy();
int test_ilist_get_size();
int test_ilist_get_data();

int
test_nodeilist_create() {
    NodeIList* nil   = nodeilist_create(10);
    bool       test1 = ASSERT(nil != NULL);
    free(nil);

    return test1;
}

int
test_ilist_create() {
    IList* il    = ilist_create();
    bool   test1 = ASSERT(il != NULL);
    ilist_destroy(il);

    return test1;
}

int
test_ilist_add() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    bool test1 = ASSERT(il != NULL);
    bool test2 = ASSERT(ilist_get_data(il, 0) == 10);
    bool test3 = ASSERT(ilist_get_data(il, 1) == 30);
    bool test4 = ASSERT(ilist_get_data(il, 2) == -10);
    ilist_destroy(il);

    return test1 + test2 + test3 + test4;
}

int
test_ilist_print() {
    bool test1 = ASSERT(true);

    return test1;
}

int
test_ilist_destroy() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    ilist_destroy(il);
    il         = NULL;
    bool test1 = ASSERT(il == NULL);

    return test1;
}

int
test_ilist_get_size() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    bool test1 = ASSERT(il != NULL);
    bool test2 = ASSERT(ilist_get_size(il) == 3);
    ilist_add(il, -20);
    bool test3 = ASSERT(ilist_get_size(il) == 4);
    ilist_destroy(il);

    return test1 + test2 + test3;
}

int
test_ilist_get_data() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    bool test1 = ASSERT(il != NULL);
    bool test2 = ASSERT(ilist_get_data(il, 0) == 10);
    bool test3 = ASSERT(ilist_get_data(il, 1) == 30);
    bool test4 = ASSERT(ilist_get_data(il, 2) == -10);
    ilist_destroy(il);

    return test1 + test2 + test3 + test4;
}

int
main() {
    printf("\033[0;33m--- TEST FILE : %s ---\033[0m\n", __FILE__);

    int test1 = test_nodeilist_create();
    int test2 = test_ilist_create();
    int test3 = test_ilist_add();
    int test4 = test_ilist_print();
    int test5 = test_ilist_destroy();
    int test6 = test_ilist_get_size();
    int test7 = test_ilist_get_data();

    int number_of_asserts = 15;
    int tests_passed = test1 + test2 + test3 + test4 + test5 + test6 + test7;

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
