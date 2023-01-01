#include "../include/safe_xallocs.h"

void*
s_malloc(size_t      size,
         const char* file_name,
         int         line_number,
         const char* func_name) {
    void* p = malloc(size);

    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed [%s:%d] %s\n", file_name,
                line_number, func_name);
        exit(EXIT_FAILURE);
    }

    return p;
}

void*
s_calloc(size_t      nmemb,
         size_t      size,
         const char* file_name,
         int         line_number,
         const char* func_name) {
    void* p = calloc(nmemb, size);

    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed [%s:%d] %s\n", file_name,
                line_number, func_name);
        exit(EXIT_FAILURE);
    }

    return p;
}

void*
s_realloc(void*       ptr,
          size_t      size,
          const char* file_name,
          int         line_number,
          const char* func_name) {
    void* p = realloc(ptr, size);

    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed [%s:%d] %s\n", file_name,
                line_number, func_name);
        exit(EXIT_FAILURE);
    }

    return p;
}
