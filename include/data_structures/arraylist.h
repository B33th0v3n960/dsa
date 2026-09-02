#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "algorithms/insertion_sort.h"

#include <stddef.h>

typedef struct ArrayList *ArrayList;

ArrayList arraylist_create(size_t element_size);
void arraylist_free(ArrayList list);

size_t arraylist_len(ArrayList list);

int arraylist_append(ArrayList list, void *new_value);
int arraylist_prepend(ArrayList list, void *new_value);
int arraylist_insert(ArrayList list, int insert_index, void *new_value);

int arraylist_pop(ArrayList list, void *out_value);
int arraylist_shift(ArrayList list, void *out_value);
int arraylist_get(ArrayList list, int index, void *out_value);
int arraylist_search(ArrayList list, void *search_value, comp_fn comp);

int arraylist_reverse(ArrayList list);

#endif // !ARRAYLIST_H
