#include "utils/array_utils.h"
#include <stddef.h>
#include <stdio.h>

/** A utility function to print int array of size n */
void print_array_int(int array[], size_t array_length) {
    for (size_t i = 0; i < array_length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/** A utility function to print float array of size n */
void print_array_float(float array[], size_t array_length) {
    for (size_t i = 0; i < array_length; i++)
        printf("%f ", array[i]);
    printf("\n");
}

/** A utility function to print char pointer array of size n */
void print_array_str(char *array[], size_t array_length) {
    for (size_t i = 0; i < array_length; i++)
        printf("%s ", array[i]);
    printf("\n");
}
