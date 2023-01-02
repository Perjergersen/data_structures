#ifndef IHASHMAP_H
#define IHASHMAP_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "safe_xallocs.h"

typedef struct NodeIHashMap NodeIHashMap;
typedef struct IHashMap     IHashMap;

NodeIHashMap* nodeihashmap_create(int key, int value);
IHashMap*     ihashmap_create(uint32_t size);
void          ihashmap_insert(IHashMap* hm, int key, int value);
NodeIHashMap* ihashmap_get(IHashMap* hm, int key);
void          ihashmap_print(IHashMap* hm);
void          ihashmap_destroy(IHashMap* hm);
int           nodeihashmap_get_value(NodeIHashMap* node);
uint32_t      hash_int(IHashMap* hm, int key);

#endif
