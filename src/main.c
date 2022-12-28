#include <stdio.h>
#include <unistd.h>
#include "../include/list.h"

void* safe_malloc(size_t bytes, int line_number, char* file);

#define s_malloc(x) safe_malloc(x, __LINE__, __FILE__)

void*
safe_malloc(size_t bytes, int line_number, char* file) {
    void* s = malloc(bytes);

    if (s && bytes) {
        return s;
    }

    fprintf(stderr, "**safe_malloc() failed - line: %d.**\n**File: %s**\n",
            line_number, file);
    exit(EXIT_FAILURE);
}

int
main() {
    IList* l = ilist_create();
    ilist_add(l, 10);
    ilist_add(l, 20);
    ilist_add(l, -10);
    ilist_add(l, -12);
    ilist_add(l, 4);
    ilist_add(l, 3);
    ilist_add(l, 200);
    ilist_print(l);
    int list_size = ilist_get_size(l);
    printf("size: %d\n", list_size);

    printf("index: 5, data: %d\n", ilist_get_data(l, 5));

    ilist_destroy(l);
    return 0;
}
