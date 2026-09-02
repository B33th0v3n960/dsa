#include "data_structures/arraylist.h"
#include <stddef.h>
#include <stdlib.h>

#define DEFAULT_ARRAYLIST_SIZE 8

struct ArrayList {
    void **data;
    size_t length;
    size_t capacity;
    size_t element_size;
};

/**
 * Creates a ArrayList on the heap.
 *
 * Retval:
 * `ArrayList`   on success
 * `NULL`        if allocation fails
 */
ArrayList arraylist_create(size_t element_size) {
    ArrayList list = malloc(sizeof(struct ArrayList));
    if (list == NULL) return NULL;

    list->data = malloc(element_size * DEFAULT_ARRAYLIST_SIZE);
    if (list->data == NULL) {
        free(list);
        return NULL;
    }

    list->capacity = DEFAULT_ARRAYLIST_SIZE;
    list->length = 0;
    list->element_size = element_size;

    return list;
}
/**
 *  Free the `ArrayList` from memory including each list items.
 */
void arraylist_free(ArrayList list) {
    for (size_t i = 0; i < list->length; i++) {
        free(list->data[i]);
    }
    free(list->data);
    free(list);
}

/**
 * Get the length of `list`.
 */
size_t arraylist_len(ArrayList list) {
    if (list == NULL) return 0;
    return list->length;
}

int arraylist_append(ArrayList list, void *new_value) {
    (void)list, (void)new_value;
    return -1;
}
int arraylist_prepend(ArrayList list, void *new_value) {
    (void)list, (void)new_value;
    return -1;
}
int arraylist_insert(ArrayList list, int insert_index, void *new_value) {
    (void)list, (void)insert_index, (void)new_value;
    return -1;
}

int arraylist_pop(ArrayList list, void *out_value) {
    (void)list, (void)out_value;
    return -1;
}
int arraylist_shift(ArrayList list, void *out_value) {
    (void)list, (void)out_value;
    return -1;
}
int arraylist_get(ArrayList list, int index, void *out_value) {
    (void)list, (void)index, (void)out_value;
    return -1;
}
int arraylist_search(ArrayList list, void *search_value, comp_fn comp) {
    (void)list, (void)search_value, (void)comp;
    return -1;
}

int arraylist_reverse(ArrayList list) {
    (void)list;
    return -1;
}
