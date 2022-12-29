#ifndef NPTEST_H
#define NPTEST_H

#include <stdio.h>

void p_success(const char* func_name, int line_number);
void p_failure(const char* func_name, int line_number);
bool ASSERT_T(bool expr, const char* func_name, int line_number);

#define ASSERT(expr) ASSERT_T(expr, __func__, __LINE__)

void
p_success(const char* func_name, int line_number) {
    printf("\033[0;32mAssert Passed\033[0m | Line: %-3d | %s\n", line_number,
           func_name);
}

void
p_failure(const char* func_name, int line_number) {
    printf("\033[0;31mAssert Failed\033[0m | Line: %-3d | %s\n", line_number,
           func_name);
}

bool
ASSERT_T(bool expr, const char* func_name, int line_number) {
    (expr) ? p_success(func_name, line_number)
           : p_failure(func_name, line_number);
    return (expr);
}

#endif
