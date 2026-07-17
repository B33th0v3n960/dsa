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
 * @brief Creates a LinkedList on the heap
 *
 * @retval `LinkedList_int`   on success
 * @retval NULL             if allocation fails
 */
LinkedList_int linkedlist_create_int(void) {
    LinkedList_int list = calloc(1, sizeof(struct LinkedList_int));
    return list;
}

/**
 * @brief Free the `LinkedList_int` from memory including each list items
 *
 * @param [list] The `LinkedList_int` to free
 */
void linkedlist_free_int(LinkedList_int list) {
    while (list->head != NULL) {
        list->head = list->head->next;
        free(list->head->prev);
    }
    list->tail = NULL;
    free(list);
}
