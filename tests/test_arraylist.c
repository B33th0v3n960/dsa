#include "data_structures/arraylist.h"

#include "unity.h"
#include "unity_internals.h"

#include <stddef.h>

static int test_count = 0;
ArrayList list;

int comp_int(const void *a, const void *b) {
    const int value_a = *(int *)a;
    const int value_b = *(int *)b;
    return (value_a > value_b) - (value_a < value_b);
}

void setUp(void) {
    ++test_count;
    printf("\n");
    printf("==== Test No.%d ====\n", test_count);
    list = arraylist_create(sizeof(int));
}

void tearDown(void) {
    arraylist_free(list);
    list = NULL;
}

void test_append_int_value(void) {
    int actual, expected;
    expected = 0;
    int push_value = 5;
    actual = arraylist_append(list, &push_value);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_append_to_null(void) {
    int actual, expected;
    expected = -1;
    int push_value = 5;
    actual = arraylist_append(NULL, &push_value);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_append_ten_values(void) {
    int actual, expected;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = arraylist_append(list, &i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_prepend_int_value(void) {
    int actual, expected;
    expected = 0;
    int prepend_value = 5;
    actual = arraylist_prepend(list, &prepend_value);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_prepend_to_null(void) {
    int actual, expected;
    expected = -1;
    int prepend_value = 5;
    actual = arraylist_prepend(NULL, &prepend_value);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_prepend_ten_values(void) {
    int actual, expected;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = arraylist_prepend(list, &i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_append_int_value_and_pop(void) {
    int actual, expected, append_value, actual_pop_value, expected_pop_value;
    expected = 0;
    append_value = 5;

    actual = arraylist_append(list, &append_value);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected_pop_value = append_value;
    arraylist_pop(list, &actual_pop_value);
    printf("Actual Pop value: %d\n", actual_pop_value);
    printf("Expected Pop value: %d\n", expected_pop_value);
    TEST_ASSERT_EQUAL_INT(expected_pop_value, actual_pop_value);

    size_t expected_len, actual_len;
    expected_len = 0;
    actual_len = arraylist_len(list);
    printf("Actual list length: %lu\n", actual_len);
    printf("Expected list length: %lu\n", expected_len);
    TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
}

void test_append_ten_values_and_pop(void) {
    int actual, expected, actual_pop_value, expected_pop_value;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = arraylist_append(list, &i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected_pop_value = 9;
    arraylist_pop(list, &actual_pop_value);
    printf("Actual Pop value: %d\n", actual_pop_value);
    printf("Expected Pop value: %d\n", expected_pop_value);
    TEST_ASSERT_EQUAL_INT(expected_pop_value, actual_pop_value);

    size_t expected_len, actual_len;
    expected_len = 9;
    actual_len = arraylist_len(list);
    printf("Actual list length: %lu\n", actual_len);
    printf("Expected list length: %lu\n", expected_len);
    TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
}

void test_prepend_int_value_and_shift(void) {
    int actual, expected, shift_value, actual_shift_value, expected_shift_value;
    expected = 0;
    shift_value = 5;

    actual = arraylist_prepend(list, &shift_value);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected_shift_value = shift_value;
    arraylist_shift(list, &actual_shift_value);
    printf("Actual shift value: %d\n", actual_shift_value);
    printf("Expected shift value: %d\n", expected_shift_value);
    TEST_ASSERT_EQUAL_INT(expected_shift_value, actual_shift_value);

    size_t expected_len, actual_len;
    expected_len = 0;
    actual_len = arraylist_len(list);
    printf("Actual list length: %lu\n", actual_len);
    printf("Expected list length: %lu\n", expected_len);
    TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
}

void test_prepend_ten_values_and_shift(void) {
    int actual, expected, actual_shift_value, expected_shift_value;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = arraylist_prepend(list, &i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected_shift_value = 9;
    arraylist_shift(list, &actual_shift_value);
    printf("Actual shift value: %d\n", actual_shift_value);
    printf("Expected shift value: %d\n", expected_shift_value);
    TEST_ASSERT_EQUAL_INT(expected_shift_value, actual_shift_value);

    size_t expected_len, actual_len;
    expected_len = 9;
    actual_len = arraylist_len(list);
    printf("Actual list length: %lu\n", actual_len);
    printf("Expected list length: %lu\n", expected_len);
    TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
}

void test_get_and_search(void) {
    int actual, expected, expected_index, actual_index;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = arraylist_prepend(list, &i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected_index = 9;
    int search_value = 0;
    actual_index = arraylist_search(list, &search_value, comp_int);
    printf("Actual index: %d\n", actual_index);
    printf("Expected index: %d\n", expected_index);
    TEST_ASSERT_EQUAL_INT(expected_index, actual_index);
}

void test_get_and_search_empty_list(void) {
    int expected_index, actual_index;
    expected_index = -1;
    int search_value = 0;
    actual_index = arraylist_search(list, &search_value, comp_int);
    printf("Actual index: %d\n", actual_index);
    printf("Expected index: %d\n", expected_index);

    TEST_ASSERT_EQUAL_INT(expected_index, actual_index);
}

void test_insert_and_get(void) {
    int actual, expected, expected_index, actual_index;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = arraylist_prepend(list, &i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected_index = 5;
    int new_value = 0;
    arraylist_insert(list, (size_t)expected_index, &new_value);

    int search_value = 0;
    actual_index = arraylist_search(list, &search_value, comp_int);
    printf("Actual index: %d\n", actual_index);
    printf("Expected index: %d\n", expected_index);
    TEST_ASSERT_EQUAL_INT(expected_index, actual_index);
}

void test_linkedlist_len(void) {
    size_t actual;
    int expected;
    expected = 10;

    for (int i = 0; i < expected; i++)
        arraylist_prepend(list, &i);
    actual = arraylist_len(list);
    printf("Actual: %lu\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_append_int_value);
    RUN_TEST(test_append_to_null);
    RUN_TEST(test_append_ten_values);
    RUN_TEST(test_prepend_int_value);
    RUN_TEST(test_prepend_to_null);
    RUN_TEST(test_prepend_ten_values);
    RUN_TEST(test_append_int_value_and_pop);
    RUN_TEST(test_append_ten_values_and_pop);
    RUN_TEST(test_prepend_int_value_and_shift);
    RUN_TEST(test_prepend_ten_values_and_shift);
    RUN_TEST(test_get_and_search);
    RUN_TEST(test_insert_and_get);
    RUN_TEST(test_get_and_search_empty_list);
    RUN_TEST(test_linkedlist_len);
    return UNITY_END();
}
