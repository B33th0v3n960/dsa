#include "algorithms/insertion_sort.h"
#include "utils/swap.h"
#include <stddef.h>
#include <stdlib.h>

void insertion_sort(void *base, size_t nmemb, size_t size, comp_fn comp) {
    for (size_t i = 1; i < nmemb; i++) {
        size_t j = i - 1;
        char *elem_j = (char *)base + j * size;

        while (comp((void *)(elem_j + size), (void *)elem_j) < 0) {
            swap((void *)(elem_j + size), (void *)elem_j, size);
            if (j == 0) break;
            j--;
            elem_j = (char *)base + j * size;
        }
    }
}
