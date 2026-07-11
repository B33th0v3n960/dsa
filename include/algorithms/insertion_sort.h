#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <stddef.h>
#include <stdlib.h>

typedef int (*comp_fn)(const void *, const void *);
int insertion_sort(void *base, size_t nmemb, size_t size, comp_fn comp);

#endif // !INSERTION_SORT_H
