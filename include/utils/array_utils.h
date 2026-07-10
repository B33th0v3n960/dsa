#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#define array_len(array) (sizeof(array) / sizeof(array[0]));

void print_array_int(int array[], int array_length);

#endif // !ARRAY_UTILS_H
