#include "data_structures/linkedlist_int.h"
#include "unity.h"
#include "unity_internals.h"

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_append_int_value);
    RUN_TEST(test_append_to_null);
    return UNITY_END();
}
