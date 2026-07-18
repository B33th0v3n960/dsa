#ifndef LINKEDLIST_INT_H
#define LINKEDLIST_INT_H

#include <stdbool.h>

typedef struct LinkedList_int *LinkedList_int;

LinkedList_int linkedlist_create_int(void);
void linkedlist_free_int(LinkedList_int list);

int linkedlist_len_int(LinkedList_int list);
bool linkedlist_is_empty_int(LinkedList_int list);

int linkedlist_append_int(LinkedList_int list, int new_value);
int linkedlist_prepend_int(LinkedList_int list, int new_value);
int linkedlist_insert_int(LinkedList_int list, int insert_index, int new_value);
int linkedlist_pop_int(LinkedList_int list, int *out_value);
int linkedlist_shift_int(LinkedList_int list, int *out_value);
int linkedlist_get_int(LinkedList_int *list, int index, int *out_value);
int linkedlist_search_int(LinkedList_int *list, int search_value);
int linkedlist_reverse_int(LinkedList_int *list);

#endif // !LINKEDLIST_INT_H
