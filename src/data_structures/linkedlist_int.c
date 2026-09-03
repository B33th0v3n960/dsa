#include "data_structures/linkedlist_int.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node_int {
    int data;
    struct Node_int *next;
    struct Node_int *prev;
};

struct LinkedList_int {
    struct Node_int *head;
    struct Node_int *tail;
    size_t length;
};

/**
 * Creates a LinkedList on the heap.
 *
 * Retval:
 * `LinkedList_int`   on success
 * `NULL`             if allocation fails
 */
LinkedList_int linkedlist_create_int(void) {
    LinkedList_int list = calloc(1, sizeof(struct LinkedList_int));
    return list;
}

/**
 *  Free the `LinkedList_int` from memory including each list items.
 */
void linkedlist_free_int(LinkedList_int list) {
    struct Node_int *curr = list->head;
    while (curr != NULL) {
        list->head = curr->next;
        free(curr);
        curr = list->head;
    }
    list->tail = NULL;
    free(list);
}

/**
 * Get the length of `list`.
 */
size_t linkedlist_len_int(LinkedList_int list) {
    if (list == NULL) return 0;
    return list->length;
}

/**
 * Check if `list` is empty.
 */
bool linkedlist_is_empty_int(LinkedList_int list) {
    if (list == NULL) return true;
    return list->length == 0;
}

/**
 * Append a new `Node_int`, with value of `new_value`, to the end of `list`.
 *
 * Retval:
 * - `0`    on success
 * - `-1`   if fails
 */
int linkedlist_append_int(LinkedList_int list, int new_value) {
    if (list == NULL) return -1;

    struct Node_int *new_node = calloc(1, sizeof(struct Node_int));
    if (new_node == NULL) return -1;
    new_node->data = new_value;

    if (list->head == NULL) {
        list->head = list->tail = new_node;
        list->length = 1;
        return 0;
    }

    list->tail->next = new_node;
    new_node->prev = list->tail;
    list->tail = new_node;
    list->length++;
    return 0;
}

/**
 * Prepend a new `Node_int`, with value of `new_value`, to the start of `list`.
 *
 * Retval:
 * - `0`    on success
 * - `-1`   if fails
 */
int linkedlist_prepend_int(LinkedList_int list, int new_value) {
    if (list == NULL) return -1;

    struct Node_int *new_node = calloc(1, sizeof(struct Node_int));
    if (new_node == NULL) return -1;
    new_node->data = new_value;

    if (list->head == NULL) {
        list->head = list->tail = new_node;
        list->length = 1;
        return 0;
    }

    list->head->prev = new_node;
    new_node->next = list->head;
    list->head = new_node;
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
int linkedlist_insert_int(LinkedList_int list, int insert_index, int new_value) {
    if (list == NULL || list->head == NULL) return -1;
    struct Node_int *new_node = malloc(sizeof(struct Node_int));
    if (new_node == NULL) return -1;
    new_node->data = new_value;

    struct Node_int *current;
    current = list->head;
    int current_index;
    for (current_index = 0; current_index < insert_index; current_index++)
        current = current->next;

    if (current_index != insert_index) return -1;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    new_node->next = current;
    current->prev = new_node;
    return 0;
}

/**
 * Pop out the last value in `list` and delete the last node.
 *
 * Retval:
 * - `0`    on success
 * - `-1`   if fails
 */
int linkedlist_pop_int(LinkedList_int list, int *out_value) {
    if (list == NULL || list->tail == NULL) return -1;
    *out_value = list->tail->data;

    if (list->head == list->tail) {
        free(list->head);
        list->head = list->tail = NULL;
        list->length = 0;
        return 0;
    }

    list->tail = list->tail->prev;
    free(list->tail->next);
    list->tail->next = NULL;
    list->length--;
    return 0;
}

/**
 * Shift out the first value in `list` and delete the first node.
 *
 * Retval:
 * - `0`    on success
 * - `-1`   if fails
 */
int linkedlist_shift_int(LinkedList_int list, int *out_value) {
    if (list == NULL || list->head == NULL) return -1;
    *out_value = list->head->data;

    if (list->head == list->tail) {
        free(list->head);
        list->head = list->tail = NULL;
        list->length = 0;
        return 0;
    }

    list->head = list->head->next;
    free(list->head->prev);
    list->head->prev = NULL;
    list->length--;
    return 0;
}

/**
 * Get the value at give `index`.
 *
 * Retval:
 * - `0`    on success
 * - `-1`   if fails
 */
int linkedlist_get_int(LinkedList_int list, int index, int *out_value) {
    if (list == NULL || list->head == NULL) return -1;
    if (index >= (int)list->length || index < 0) return -1;

    struct Node_int *current;
    current = list->head;
    for (int i = 0; i < index; i++)
        current = current->next;
    *out_value = list->head->data;
    return 0;
}

/**
 * Get the index of the first node that has value of `search_value`.
 *
 * Retval:
 * - `index`  index of the element if exist.
 * - `-1`     if fails
 */
int linkedlist_search_int(LinkedList_int list, int search_value) {
    if (list == NULL || list->head == NULL) return -1;

    struct Node_int *current;
    current = list->head;
    int index = 0;
    while (current != NULL && current->data != search_value) {
        current = current->next;
        index++;
    }

    if (current == NULL) return -1;
    return index;
}
