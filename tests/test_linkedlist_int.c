#include "data_structures/linkedlist_int.h"
#include "unity.h"
#include "unity_internals.h"
#include <stddef.h>

static int test_count = 0;
LinkedList_int list;

void setUp(void) {
    ++test_count;
    printf("\n");
    printf("==== Test No.%d ====\n", test_count);
    list = linkedlist_create_int();
}

void tearDown(void) {
    linkedlist_free_int(list);
    list = NULL;
}

void test_append_int_value(void) {
    int actual, expected;
    expected = 0;
    actual = linkedlist_append_int(list, 5);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_append_to_null(void) {
    int actual, expected;
    expected = -1;
    actual = linkedlist_append_int(NULL, 5);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_append_ten_values(void) {
    int actual, expected;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = linkedlist_append_int(list, i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_prepend_int_value(void) {
    int actual, expected;
    expected = 0;
    actual = linkedlist_prepend_int(list, 5);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_prepend_to_null(void) {
    int actual, expected;
    expected = -1;
    actual = linkedlist_prepend_int(NULL, 5);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_prepend_ten_values(void) {
    int actual, expected;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = linkedlist_prepend_int(list, i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);

    TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_append_int_value_and_pop(void) {
    int actual, expected, append_value, actual_pop_value, expected_pop_value;
    expected = 0;
    append_value = 5;

    actual = linkedlist_append_int(list, append_value);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected = 0;
    expected_pop_value = append_value;
    actual = linkedlist_pop_int(list, &actual_pop_value);
    printf("Actual Pop value: %d\n", actual_pop_value);
    printf("Expected Pop value: %d\n", expected_pop_value);
    TEST_ASSERT_EQUAL_INT(expected_pop_value, actual_pop_value);

    size_t expected_len, actual_len;
    expected_len = 0;
    actual_len = linkedlist_len_int(list);
    printf("Actual list length: %lu\n", actual_len);
    printf("Expected list length: %lu\n", expected_len);
    TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
}

void test_append_ten_values_and_pop(void) {
    int actual, expected, actual_pop_value, expected_pop_value;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = linkedlist_append_int(list, i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected = 0;
    expected_pop_value = 9;
    actual = linkedlist_pop_int(list, &actual_pop_value);
    printf("Actual Pop value: %d\n", actual_pop_value);
    printf("Expected Pop value: %d\n", expected_pop_value);
    TEST_ASSERT_EQUAL_INT(expected_pop_value, actual_pop_value);

    size_t expected_len, actual_len;
    expected_len = 9;
    actual_len = linkedlist_len_int(list);
    printf("Actual list length: %lu\n", actual_len);
    printf("Expected list length: %lu\n", expected_len);
    TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
}

void test_prepend_int_value_and_shift(void) {
    int actual, expected, shift_value, actual_shift_value, expected_shift_value;
    expected = 0;
    shift_value = 5;

    actual = linkedlist_prepend_int(list, shift_value);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected = 0;
    expected_shift_value = shift_value;
    actual = linkedlist_shift_int(list, &actual_shift_value);
    printf("Actual shift value: %d\n", actual_shift_value);
    printf("Expected shift value: %d\n", expected_shift_value);
    TEST_ASSERT_EQUAL_INT(expected_shift_value, actual_shift_value);

    size_t expected_len, actual_len;
    expected_len = 0;
    actual_len = linkedlist_len_int(list);
    printf("Actual list length: %lu\n", actual_len);
    printf("Expected list length: %lu\n", expected_len);
    TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
}

void test_prepend_ten_values_and_shift(void) {
    int actual, expected, actual_shift_value, expected_shift_value;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = linkedlist_prepend_int(list, i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected = 0;
    expected_shift_value = 9;
    actual = linkedlist_shift_int(list, &actual_shift_value);
    printf("Actual shift value: %d\n", actual_shift_value);
    printf("Expected shift value: %d\n", expected_shift_value);
    TEST_ASSERT_EQUAL_INT(expected_shift_value, actual_shift_value);

    size_t expected_len, actual_len;
    expected_len = 9;
    actual_len = linkedlist_len_int(list);
    printf("Actual list length: %lu\n", actual_len);
    printf("Expected list length: %lu\n", expected_len);
    TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
}

void test_get_and_search(void) {
    int actual, expected, expected_index, actual_index;
    expected = 0;

    for (int i = 0; i < 10; i++)
        actual = linkedlist_prepend_int(list, i);
    printf("Actual: %d\n", actual);
    printf("Expected: %d\n", expected);
    TEST_ASSERT_EQUAL_INT(expected, actual);

    expected_index = 9;
    int search_value = 0;
    actual_index = linkedlist_search_int(list, search_value);
    printf("Actual index: %d\n", actual_index);
    printf("Expected index: %d\n", expected_index);
    TEST_ASSERT_EQUAL_INT(expected_index, actual_index);
}

void test_get_and_search_empty_list(void) {
    int expected_index, actual_index;
    expected_index = -1;
    int search_value = 0;
    actual_index = linkedlist_search_int(list, search_value);
    printf("Actual index: %d\n", actual_index);
    printf("Expected index: %d\n", expected_index);

    TEST_ASSERT_EQUAL_INT(expected_index, actual_index);
}

void test_linkedlist_len(void) {
    size_t actual;
    int expected;
    expected = 10;

    for (int i = 0; i < expected; i++)
        linkedlist_prepend_int(list, i);
    actual = linkedlist_len_int(list);
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
    RUN_TEST(test_get_and_search_empty_list);
    RUN_TEST(test_linkedlist_len);
    return UNITY_END();
}
