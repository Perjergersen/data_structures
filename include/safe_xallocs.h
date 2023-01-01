#ifndef SAFE_XALLOCS
#define SAFE_XALLOCS

#include <stdio.h>
#include <stdlib.h>

void* s_malloc(size_t      size,
               const char* file_name,
               int         line_number,
               const char* func_name);

void* s_calloc(size_t      nmemb,
               size_t      size,
               const char* file_name,
               int         line_number,
               const char* func_name);

void* s_realloc(void*       ptr,
                size_t      size,
                const char* file_name,
                int         line_number,
                const char* func_name);

#define smalloc(size)        s_malloc(size, __FILE__, __LINE__, __func__)
#define scalloc(nmemb, size) s_calloc(nmemb, size, __FILE__, __LINE__, __func__)
#define srealloc(ptr, size)  s_realloc(ptr, size, __FILE__, __LINE__, __func__)

#endif
