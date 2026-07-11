#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stddef.h>

#define array_len(array) (sizeof(array) / sizeof(array[0]));
void print_array_int(int array[], size_t array_length);
void print_array_float(float array[], size_t array_length);
void print_array_str(char *array[], size_t array_length);

#endif // !ARRAY_UTILS_H
