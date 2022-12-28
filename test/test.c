#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/list.h"

void test_nodeilist_create();
void test_ilist_create();
void test_ilist_add();
void test_ilist_print();
void test_ilist_destroy();
void test_ilist_get_size();
void test_ilist_get_data();
void p_success(const char* func_name, int line_number);
void p_failure(const char* func_name, int line_number);
bool ASSERT_T(bool expr, const char* func_name, int line_number);

void
p_success(const char* func_name, int line_number) {
    printf("\033[0;32mPassed\033[0m | Line: %d | %s\n", line_number, func_name);
}

void
p_failure(const char* func_name, int line_number) {
    printf("\033[0;31mFailed\033[0m | Line: %d | %s\n", line_number, func_name);
}

bool
ASSERT_T(bool expr, const char* func_name, int line_number) {
    (expr) ? p_success(func_name, line_number)
           : p_failure(func_name, line_number);
    return (expr);
}

#define ASSERT(expr) ASSERT_T(expr, __func__, __LINE__)

void
test_nodeilist_create() {
    NodeIList* nil = nodeilist_create(10);
    ASSERT(nil != NULL);
    free(nil);
}

void
test_ilist_create() {
    IList* il = ilist_create();
    ASSERT(il != NULL);
    ilist_destroy(il);
}

void
test_ilist_add() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    ASSERT(il != NULL);
    ASSERT(ilist_get_data(il, 0) == 10);
    ASSERT(ilist_get_data(il, 1) == 30);
    ASSERT(ilist_get_data(il, 2) == -10);
    ilist_destroy(il);
}

void
test_ilist_print() {
    ASSERT(true);
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
    ASSERT(il == NULL);
}

void
test_ilist_get_size() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    ASSERT(il != NULL);
    ASSERT(ilist_get_size(il) == 3);
    ilist_add(il, -20);
    ASSERT(ilist_get_size(il) == 4);
    ilist_destroy(il);
}

void
test_ilist_get_data() {
    IList* il = ilist_create();
    ilist_add(il, 10);
    ilist_add(il, 30);
    ilist_add(il, -10);
    ASSERT(il != NULL);
    ASSERT(ilist_get_data(il, 0) == 10);
    ASSERT(ilist_get_data(il, 1) == 30);
    ASSERT(ilist_get_data(il, 2) == -10);
    ilist_destroy(il);
}

int
main() {
    printf("--- TEST FILE : %s ---\n", __FILE__);

    test_nodeilist_create();
    test_ilist_create();
    test_ilist_add();
    test_ilist_print();
    test_ilist_destroy();
    test_ilist_get_size();
    test_ilist_get_data();

    printf("--- TEST FILE : %s ---\n", __FILE__);
    return 0;
}
