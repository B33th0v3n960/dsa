#include "utils/swap.h"
#include <stddef.h>
#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    char tmp;
    char *pa = (char *)a;
    char *pb = (char *)b;

    for (size_t i = 0; i < size; i++) {
        tmp = pa[i];
        pa[i] = pb[i];
        pb[i] = tmp;
    }
}
