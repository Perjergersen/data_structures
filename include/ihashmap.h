#ifndef IHASHMAP_H
#define IHASHMAP_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "safe_xallocs.h"

typedef struct IMapNode IMapNode;
typedef struct IMap     IMap;

IMapNode* imapnode(int key, int value);
IMap*     imap(uint32_t size);
void          imap_insert(IMap* hm, int key, int value);
IMapNode* imap_get(IMap* hm, int key);
void          imap_print(IMap* hm);
void          imap_destroy(IMap* hm);
int           imapnode_value(IMapNode* node);
uint32_t      hash_int(IMap* hm, int key);

#endif
