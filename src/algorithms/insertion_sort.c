#include "algorithms/insertion_sort.h"

void insertion_sort(int array[], int array_length) {
    for (int i = 1; i < array_length; i++) {
        int current = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}
