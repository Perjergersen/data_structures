#include "../include/ivector.h"

struct IVector {
    int* vec;
    int  size;
    int  mem_alloc;
};

IVector*
ivector_create_empty() {
    IVector* iv   = smalloc(sizeof(IVector));
    iv->mem_alloc = 2;
    iv->vec       = scalloc(iv->mem_alloc, sizeof(int));
    iv->size      = 0;
    return iv;
}

IVector*
ivector_create(int num_of_vec_elements, ...) {
    IVector* iv = ivector_create_empty();
    va_list  args;
    va_start(args, num_of_vec_elements);

    for (int i = 0; i < num_of_vec_elements; i++) {
        ivector_insert(iv, va_arg(args, int));
    }

    va_end(args);
    return iv;
}

void
ivector_insert(IVector* iv, int data) {
    if (iv->size == iv->mem_alloc) {
        iv->mem_alloc *= 2;
        iv->vec = srealloc(iv->vec, iv->mem_alloc * sizeof(int));
        // printf("new allocd size: %d\n", iv->mem_alloc);
    }
    iv->vec[iv->size] = data;
    iv->size++;
}

void
ivector_print(IVector* iv) {
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
ivector_get(IVector* iv, int index) {
    if (index < 0 || index >= iv->size) {
        fprintf(stderr, "ivector_get index out of bounds\n");
        fprintf(stderr, "attempting to access index %d in size %d array\n",
                index, iv->size);
        exit(EXIT_FAILURE);
    }

    return iv->vec[index];
}

int
ivector_size(IVector* iv) {
    return iv->size;
}

void
ivector_destroy(IVector* iv) {
    free(iv->vec);
    iv->vec = NULL;
    free(iv);
    iv = NULL;
}
