//
// Created by Admin on 11.05.2024.
//

#include "test.h"

int main(){
    //запуск тестов и счётчика
    tests_passed = 0;
    RUN_TEST(CREATE_ARRAY_SEQUENCE);
    RUN_TEST(CREATE_ARRAY_SEQUENCE_FROM_ARRAY);
    RUN_TEST(COPY_ARRAY_SEQUENCE);
    RUN_TEST(CREATE_LIST_SEQUENCE);
    RUN_TEST(CREATE_LIST_SEQUENCE_FROM_ARRAY);
    RUN_TEST(COPY_LIST_SEQUENCE);
    RUN_TEST(ARRAY_SEQUENCE_APPEND);
    RUN_TEST(ARRAY_SEQUENCE_GET_FIRST);
    RUN_TEST(ARRAY_SEQUENCE_GET_LAST);
    RUN_TEST(ARRAY_SEQUENCE_GET);
    RUN_TEST(ARRAY_SEQUENCE_GET_SUBSEQUENCE);
    RUN_TEST(ARRAY_SEQUENCE_INSERT_AT);
    RUN_TEST(ARRAY_SEQUENCE_OUT_OF_RANGE);
    RUN_TEST(LIST_SEQUENCE_APPEND);
    RUN_TEST(LIST_SEQUENCE_GET_FIRST);
    RUN_TEST(LIST_SEQUENCE_GET_LAST);
    RUN_TEST(LIST_SEQUENCE_GET);
    RUN_TEST(LIST_SEQUENCE_GET_SUBSEQUENCE);
    RUN_TEST(LIST_SEQUENCE_INSERT_AT);
    RUN_TEST(LIST_SEQUENCE_OUT_OF_RANGE);
    RUN_TEST(ARRAY_SEQUENCE_MAP);
    RUN_TEST(LIST_SEQUENCE_MAP);
    RUN_TEST(ARRAY_SEQUENCE_REDUCE);
    RUN_TEST(LIST_SEQUENCE_REDUCE);
    RUN_TEST(IMMUTABLE_ARRAY_SEQUENCE_APPEND);
    RUN_TEST(IMMUTABLE_ARRAY_SEQUENCE_PREPEND);
    RUN_TEST(IMMUTABLE_ARRAY_SEQUENCE_INSERT_AT);
    RUN_TEST(IMMUTABLE_ARRAY_SEQUENCE_SET);
    RUN_TEST(IMMUTABLE_LIST_SEQUENCE_APPEND);
    RUN_TEST(IMMUTABLE_LIST_SEQUENCE_PREPEND);
    RUN_TEST(IMMUTABLE_LIST_SEQUENCE_INSERT_AT);
    RUN_TEST(IMMUTABLE_LIST_SEQUENCE_SET);
    printf("===================================[TESTS PASSED: %d/%d (%d%%)]===================================\n", tests_passed, total_tests, (tests_passed * 100) / total_tests);
    return 0;
}
