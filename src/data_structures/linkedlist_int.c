#include "data_structures/linkedlist_int.h"
#include <stdlib.h>

struct Node_int {
    int data;
    struct Node_int *next;
    struct Node_int *prev;
};

struct LinkedList_int {
    struct Node_int *head;
    struct Node_int *tail;
    int length;
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
    while (list->head != NULL) {
        list->head = list->head->next;
        free(list->head->prev);
    }
    list->tail = NULL;
    free(list);
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
