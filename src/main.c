#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
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

int
main() {
    struct Person* p_ptr = s_malloc(sizeof(struct Person));
    p_ptr->grade         = 12;
    p_ptr->age           = 18;
    void* v_ptr          = p_ptr;

    *(int*) (v_ptr)     = 100;
    *(int*) (v_ptr + 4) = 200;

    int grade = p_ptr->grade;
    int age   = p_ptr->age;

    printf("%d\n%d\n", grade, age);

    int* n = s_malloc(4);
    *n     = 10;
    printf("%d\n", *n);

    return 0;
}
