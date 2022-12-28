#include <assert.h>
#include <stdio.h>
#include "../include/list.h"

void test_nodeilist_create();
void test_ilist_create();
void test_ilist_add();
void test_ilist_print();
void test_ilist_destroy();
void test_ilist_get_size();
void test_ilist_get_data();

void
test_nodeilist_create() {
    NodeIList* nil = nodeilist_create(10);
    assert(nil != NULL);
    free(nil);
}

void
test_ilist_create() {
    IList* il = ilist_create();
    assert(il != NULL);
    ilist_destroy(il);
}

void
test_ilist_add() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    assert(il != NULL);
    assert(ilist_get_data(il, 0) == 10);
    assert(ilist_get_data(il, 1) == 30);
    assert(ilist_get_data(il, 2) == -10);
    ilist_destroy(il);
}

void
test_ilist_print() {
    return;
}

void
test_ilist_destroy() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    ilist_destroy(il);
    il = NULL;
    assert(il == NULL);
}

void
test_ilist_get_size() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    assert(il != NULL);
    assert(ilist_get_size(il) == 3);
    ilist_add(il, -20);
    assert(ilist_get_size(il) == 4);
    ilist_destroy(il);
}

void
test_ilist_get_data() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    assert(il != NULL);
    assert(ilist_get_data(il, 0) == 10);
    assert(ilist_get_data(il, 1) == 30);
    assert(ilist_get_data(il, 2) == -10);
    ilist_destroy(il);
}

int
main() {
    test_nodeilist_create();
    test_ilist_create();
    test_ilist_add();
    test_ilist_print();
    test_ilist_destroy();
    test_ilist_get_size();
    test_ilist_get_data();

    printf("All tests passed\n");

    return 0;
}
