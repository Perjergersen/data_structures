#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/ihashmap.h"
#include "../include/ilist.h"
#include "../include/safe_xallocs.h"

int
rand_range(int min, int max) {
    int range = max + 1 - min;
    return (rand() % range) + min;
}

int
main(int argc, char** argv) {
    const char* str = smalloc(1);
    return 0;
}
