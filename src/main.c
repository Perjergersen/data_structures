#include <stdio.h>
#include "../include/list.h"

int
main() {
    IList* l = ilist_create();
    ilist_add(l, 10);
    ilist_add(l, 20);
    ilist_add(l, -10);
    ilist_add(l, -12);
    ilist_add(l, 4);
    ilist_print(l);
    ilist_destroy(l);
    return 0;
}
