#include "data_structures/linkedlist_int.h"

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
