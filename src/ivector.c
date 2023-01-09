#include "../include/ivector.h"

struct IVec {
    int* vec;
    int  size;
    int  mem_alloc;
};

IVec*
ivec_empty() {
    IVec* iv   = smalloc(sizeof(IVec));
    iv->mem_alloc = 2;
    iv->vec       = scalloc(iv->mem_alloc, sizeof(int));
    iv->size      = 0;
    return iv;
}

IVec*
ivec(int num_of_vec_elements, ...) {
    IVec* iv = ivec_empty();
    va_list  args;
    va_start(args, num_of_vec_elements);

    for (int i = 0; i < num_of_vec_elements; i++) {
        ivec_insert(iv, va_arg(args, int));
    }

    va_end(args);
    return iv;
}

void
ivec_insert(IVec* iv, int data) {
    if (iv->size == iv->mem_alloc) {
        iv->mem_alloc *= 2;
        iv->vec = srealloc(iv->vec, iv->mem_alloc * sizeof(int));
        // printf("new allocd size: %d\n", iv->mem_alloc);
    }
    iv->vec[iv->size] = data;
    iv->size++;
}

void
ivec_print(IVec* iv) {
    printf("Vector: [");
    for (int i = 0; i < iv->size; i++) {
        printf("%d", iv->vec[i]);
        if (i != iv->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int
ivec_get(IVec* iv, int index) {
    if (index < 0 || index >= iv->size) {
        fprintf(stderr, "ivec_get index out of bounds\n");
        fprintf(stderr, "attempting to access index %d in size %d array\n",
                index, iv->size);
        exit(EXIT_FAILURE);
    }

    return iv->vec[index];
}

int
ivec_size(IVec* iv) {
    return iv->size;
}

void
ivec_destroy(IVec* iv) {
    free(iv->vec);
    iv->vec = NULL;
    free(iv);
    iv = NULL;
}
