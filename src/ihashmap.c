#include "../include/ihashmap.h"

struct NodeIHashMap {
    int           key;
    int           value;
    NodeIHashMap* next;
};

struct IHashMap {
    NodeIHashMap** map;
    uint32_t       size;
};

NodeIHashMap*
nodeihashmap_create(int key, int value) {
    NodeIHashMap* node = malloc(sizeof(NodeIHashMap));
    node->key          = key;
    node->value        = value;
    node->next         = NULL;
    return node;
}

IHashMap*
ihashmap_create(uint32_t size) {
    IHashMap* hashmap = malloc(sizeof(IHashMap));
    hashmap->map      = malloc(sizeof(NodeIHashMap*) * size);
    hashmap->size     = size;

    for (uint32_t i = 0; i < size; i++) {
        hashmap->map[i] = NULL;
    }

    return hashmap;
}

void
ihashmap_add(IHashMap* hm, int key, int value) {
    uint32_t      hashed_key = hash_int(hm, key);
    NodeIHashMap* new_node   = nodeihashmap_create(key, value);

    if (hm->map[hashed_key] == NULL) {
        hm->map[hashed_key] = new_node;
        //printf("k: %d, v: %d -- added at %u\n", key, value, hashed_key);
    } else {
        NodeIHashMap* curr = hm->map[hashed_key];
        if (curr->key == key) {
            printf("duplicate key attempted: %d:%d\n", key, value);
            return;
        }

        while (curr->next) {
            if (curr->key == key) {
                printf("duplicate key attempted: %d:%d\n", key, value);
                return;
            }
            curr = curr->next;
        }
        if (curr)
            curr->next = new_node;
        //printf("k: %d, v: %d -- added at %u (collision)\n", key, value, hashed_key);
    }
}

NodeIHashMap*
ihashmap_get(IHashMap* hm, int key) {
    //printf("looking for %d...\n", key);
    if (hm == NULL) {
        fprintf(stderr,
                "Passed a IHashMap* into ihashmap_get_value that was pointing "
                "to NULL");
        exit(EXIT_FAILURE);
    }

    uint32_t hashed_key = hash_int(hm, key);

    if (hm->map[hashed_key] == NULL) {
        //printf("%d key not in hashmap\n", key);
        return NULL;
    }

    if (hm->map[hashed_key]->key == key) {
        //printf("returned k: %d, v: %d at %u\n", hm->map[hashed_key]->key,
        //       hm->map[hashed_key]->value, hashed_key);
        return hm->map[hashed_key];
    }

    NodeIHashMap* curr = hm->map[hashed_key];
    while (curr) {
        if (curr->key == key) {
            //printf("returned k: %d, v: %d at %u\n", curr->key, curr->value,
            //      hashed_key);
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void
ihashmap_print(IHashMap* hm) {
    for (uint32_t i = 0; i < hm->size; i++) {
        if (hm->map[i] == NULL) {
            continue;
        }

        NodeIHashMap* curr = hm->map[i];
        printf("[Array Pos: %-5d] ", i);
        while (curr) {
            printf("Key:Value:%5d:%-2d -> ", curr->key, curr->value);
            curr = curr->next;
        }
        printf("\n");
    }
}

void
ihashmap_destroy(IHashMap* hm) {
    for (uint32_t i = 0; i < hm->size; i++) {
        NodeIHashMap* curr = hm->map[i];
        while (curr) {
            NodeIHashMap* prev = curr;
            curr               = curr->next;
            free(prev);
            prev = NULL;
        }
    }
    free(hm->map);
    hm->map = NULL;

    free(hm);
    hm = NULL;
}

int
nodeihashmap_get_value(NodeIHashMap* node) {
    return node->value;
}

uint32_t
hash_int(IHashMap* hm, int key) {
    uint32_t x = key;
    //
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;

    if (hm != NULL) {
        x = x % hm->size;
    } else {
        fprintf(stderr,
                "Passed a IHashMap* into hash_int that was pointing to NULL");
        exit(EXIT_FAILURE);
    }
    return x;
}
