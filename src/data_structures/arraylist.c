#include "data_structures/arraylist.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_ARRAYLIST_SIZE 8

struct ArrayList {
    char *data;
    size_t length;
    size_t capacity;
    size_t element_size;
};

/**
 * Realloc and extended the size of `list`.
 *
 * Retval:
 * `0`   on success
 * `-1`  if allocation fails
 */
static int arraylist_grow(ArrayList list) {
    size_t new_capacity = list->capacity * 2;
    if (new_capacity > SIZE_MAX / list->element_size) return -1;

    char *new_data = realloc(list->data, new_capacity * list->element_size);
    if (new_data == NULL) return -1;

    list->data = new_data;
    list->capacity = new_capacity;
    return 0;
}

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
    if (list == NULL) return;

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

/**
 * Append a new element, with value of `new_value`, to the end of `list`.
 *
 * Retval:
 * - `0`    on success
 * - `-1`   if fails
 */
int arraylist_append(ArrayList list, void *new_value) {
    if (list == NULL || list->data == NULL || new_value == NULL) return -1;
    if (list->length == list->capacity && arraylist_grow(list) != 0) return -1;

    char *new_element_address = list->data + list->length * list->element_size;
    memcpy(new_element_address, new_value, list->element_size);
    list->length++;
    return 0;
}

/**
 * Prepend a new element, with value of `new_value`, to the beginning of `list`.
 *
 * Retval:
 * - `0`    on success
 * - `-1`   if fails
 */
int arraylist_prepend(ArrayList list, void *new_value) {
    if (list == NULL || list->data == NULL || new_value == NULL) return -1;
    if (list->length == list->capacity && arraylist_grow(list) != 0) return -1;

    memmove(list->data + list->element_size, list->data, list->element_size * list->length);
    memcpy(list->data, new_value, list->element_size);
    list->length++;
    return 0;
}

/**
 * Insert a new `Node_int`, with value of `new_value`, at index `insert_index` of `list`.
 *
 * Retval:
 * - `0`    on success
 * - `-1`   if fails
 */
int arraylist_insert(ArrayList list, size_t insert_index, void *new_value) {
    if (list == NULL || list->data == NULL || new_value == NULL) return -1;
    if (list->length == list->capacity && arraylist_grow(list) != 0) return -1;

    char *insert_address = list->data + list->element_size * insert_index;
    memmove(insert_address + list->element_size, insert_address, list->element_size * list->length);
    memcpy(insert_address, new_value, list->element_size);
    list->length++;
    return 0;
}

int arraylist_pop(ArrayList list, void *out_value) {
    if (list == NULL || list->data == NULL || out_value == NULL) return -1;
    list->length--;
    memcpy(out_value, list->data + list->length * list->element_size, list->element_size);
    return 0;
}

int arraylist_shift(ArrayList list, void *out_value) {
    if (list == NULL || list->data == NULL || out_value == NULL) return -1;
    memcpy(out_value, list->data, list->element_size);
    memmove(list->data, list->data + list->element_size, list->element_size * --list->length);
    return 0;
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
