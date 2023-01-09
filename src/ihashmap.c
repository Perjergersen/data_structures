#include "../include/ihashmap.h"

struct IMapNode {
    int           key;
    int           value;
    IMapNode* next;
};

struct IMap {
    IMapNode** map;
    uint32_t       size;
};

IMapNode*
imapnode(int key, int value) {
    IMapNode* node = smalloc(sizeof(IMapNode));
    node->key          = key;
    node->value        = value;
    node->next         = NULL;
    return node;
}

IMap*
imap(uint32_t size) {
    IMap* hashmap = smalloc(sizeof(IMap));
    hashmap->map      = smalloc(sizeof(IMapNode*) * size);
    hashmap->size     = size;

    for (uint32_t i = 0; i < size; i++) {
        hashmap->map[i] = NULL;
    }

    return hashmap;
}

void
imap_insert(IMap* hm, int key, int value) {
    uint32_t      hashed_key = hash_int(hm, key);
    IMapNode* new_node   = imapnode(key, value);

    if (hm->map[hashed_key] == NULL) {
        hm->map[hashed_key] = new_node;
        // printf("k: %d, v: %d -- added at %u\n", key, value, hashed_key);
    } else {
        IMapNode* curr = hm->map[hashed_key];
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
        // printf("k: %d, v: %d -- added at %u (collision)\n", key, value,
        // hashed_key);
    }
}

IMapNode*
imap_get(IMap* hm, int key) {
    // printf("looking for %d...\n", key);
    if (hm == NULL) {
        fprintf(stderr,
                "Passed a IMap* into ihashmap_get_value that was pointing "
                "to NULL");
        exit(EXIT_FAILURE);
    }

    uint32_t hashed_key = hash_int(hm, key);

    if (hm->map[hashed_key] == NULL) {
        // printf("%d key not in hashmap\n", key);
        return NULL;
    }

    if (hm->map[hashed_key]->key == key) {
        // printf("returned k: %d, v: %d at %u\n", hm->map[hashed_key]->key,
        //        hm->map[hashed_key]->value, hashed_key);
        return hm->map[hashed_key];
    }

    IMapNode* curr = hm->map[hashed_key];
    while (curr) {
        if (curr->key == key) {
            // printf("returned k: %d, v: %d at %u\n", curr->key, curr->value,
            //       hashed_key);
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void
imap_print(IMap* hm) {
    printf("{ ");
    for (uint32_t i = 0; i < hm->size; i++) {
        if (hm->map[i] == NULL) {
            continue;
        }

        IMapNode* curr = hm->map[i];
        while (curr) {
            printf("(%d: %d) ", curr->key, curr->value);
            curr = curr->next;
        }
    }
    printf("}\n");
}

void
imap_destroy(IMap* hm) {
    for (uint32_t i = 0; i < hm->size; i++) {
        IMapNode* curr = hm->map[i];
        while (curr) {
            IMapNode* prev = curr;
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
imapnode_value(IMapNode* node) {
    return node->value;
}

uint32_t
hash_int(IMap* hm, int key) {
    uint32_t x = key;
    //
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;

    if (hm != NULL) {
        x = x % hm->size;
    } else {
        fprintf(stderr,
                "Passed a IMap* into hash_int that was pointing to NULL");
        exit(EXIT_FAILURE);
    }
    return x;
}
