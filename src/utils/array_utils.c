#include "utils/array_utils.h"
#include <stdio.h>

/* A utility function to print array of size n */
void print_array_int(int array[], int array_length) {
    for (int i = 0; i < array_length; ++i)
        printf("%d ", array[i]);
    printf("\n");
}
