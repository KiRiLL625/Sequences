//
// Created by Admin on 11.05.2024.
//

#ifndef SEQUENCES_TEST_H
#define SEQUENCES_TEST_H

#include <cstdio> //для printf
#include <cstdlib> //для exit
#include <cstring> //для strcmp
//Описание функций (макросов) для тестирования

extern int tests_passed; //количество пройденных тестов
extern const int total_tests; //общее количество тестов

//Макрос для создания теста (внутри содержит функцию test_name) (не используется)
//#define TEST(test_name) void test_name()
//Макрос для запуска теста по его имени (вызывает функцию test_name, которая описана внутри TEST)
#define RUN_TEST(test_name) printf("================[RUNNING TEST: %s]================\n", #test_name); test_name()
//Макрос для проверки равенства двух целых чисел
#define EXPECT_INT_EQ(expected, actual) if(expected != actual){ printf("[TEST FAILED]: %d != %d\n", expected, actual);} else {printf("[TEST PASSED]\n"); tests_passed++;}
//Макрос для проверки равенства двух целых чисел с завершением программы в случае неудачи (выводит количество пройденных тестов и процент пройденных тестов)
#define ASSERT_INT_EQ(expected, actual) if(expected != actual){ printf("[TEST FAILED]: %d != %d\n===================================[TESTS PASSED: %d/%d (%d%%)]===================================\n", expected, actual, tests_passed, total_tests, (tests_passed * 100) / total_tests); exit(0);} else {printf("[TEST PASSED]\n"); tests_passed++;}
//Макрос для проверки равенства двух вещественных чисел
#define EXPECT_DOUBLE_EQ(expected, actual) if(expected != actual){ printf("[TEST FAILED]: %f != %f\n", expected, actual);} else {printf("[TEST PASSED]\n"); tests_passed++;}
//Макрос для проверки равенства двух вещественных чисел с завершением программы в случае неудачи (выводит количество пройденных тестов и процент пройденных тестов)
#define ASSERT_DOUBLE_EQ(expected, actual) if(expected != actual){ printf("[TEST FAILED]: %f != %f\n===================================[TESTS PASSED: %d/%d (%d%%)]===================================\n", expected, actual, tests_passed, total_tests, (tests_passed * 100) / total_tests); exit(0);} else {printf("[TEST PASSED]\n"); tests_passed++;}
//Макрос для проверки равенства двух строк
#define EXPECT_STRING_EQ(expected, actual) if(strcmp(expected, actual) != 0){ printf("[TEST FAILED]: %s != %s\n", expected, actual);} else {printf("[TEST PASSED]\n"); tests_passed++;}
//Макрос для проверки равенства двух строк с завершением программы в случае неудачи (выводит количество пройденных тестов и процент пройденных тестов)
#define ASSERT_STRING_EQ(expected, actual) if(strcmp(expected, actual) != 0){ printf("[TEST FAILED]: %s != %s\n===================================[TESTS PASSED: %d/%d (%d%%)]===================================\n", expected, actual, tests_passed, total_tests, (tests_passed * 100) / total_tests); exit(0);} else {printf("[TEST PASSED]\n"); tests_passed++;}
//Макрос для проверки равенства объекта NULL
#define EXPECT_NULL(actual) if(actual != NULL){ printf("[TEST FAILED]: %s != NULL\n", #actual);} else {printf("[TEST PASSED]\n"); tests_passed++;}
//Макрос для проверки равенства объекта NULL с завершением программы в случае неудачи (выводит количество пройденных тестов и процент пройденных тестов)
#define ASSERT_NULL(actual) if(actual != NULL){ printf("[TEST FAILED]: %s != NULL\n===================================[TESTS PASSED: %d/%d (%d%%)]===================================\n", #actual, tests_passed, total_tests, (tests_passed * 100) / total_tests); exit(0);} else {printf("[TEST PASSED]\n"); tests_passed++;}
//Макрос для проверки неравенства объекта NULL
#define ASSERT_NOT_NULL(actual) if(actual == NULL){ printf("[TEST FAILED]: %s == NULL\n===================================[TESTS PASSED: %d/%d (%d%%)]===================================\n", #actual, tests_passed, total_tests, (tests_passed * 100) / total_tests); exit(0);} else {printf("[TEST PASSED]\n"); tests_passed++;}
//Макрос для проверки неравенства объекта NULL с завершением программы в случае неудачи (выводит количество пройденных тестов и процент пройденных тестов)
#define EXPECT_NOT_NULL(actual) if(actual == NULL) printf("[TEST FAILED]: %s == NULL\n", #actual); else {printf("[TEST PASSED]\n"); tests_passed++;}

/*
 Синтаксис для макросов такой же, как и в обычном Си, только пишется всё в одну строку (без переносов),
 и если мы хотим вывести строку в printf, то перед названием переменной ставится #.
 */

void CREATE_ARRAY_SEQUENCE();
void CREATE_ARRAY_SEQUENCE_FROM_ARRAY();
void COPY_ARRAY_SEQUENCE();
void CREATE_LIST_SEQUENCE();
void CREATE_LIST_SEQUENCE_FROM_ARRAY();
void COPY_LIST_SEQUENCE();
void ARRAY_SEQUENCE_APPEND();
void ARRAY_SEQUENCE_GET_FIRST();
void ARRAY_SEQUENCE_GET_LAST();
void ARRAY_SEQUENCE_GET();
void ARRAY_SEQUENCE_GET_SUBSEQUENCE();
void ARRAY_SEQUENCE_INSERT_AT();
void ARRAY_SEQUENCE_OUT_OF_RANGE();
void LIST_SEQUENCE_APPEND();
void LIST_SEQUENCE_GET_FIRST();
void LIST_SEQUENCE_GET_LAST();
void LIST_SEQUENCE_GET();
void LIST_SEQUENCE_GET_SUBSEQUENCE();
void LIST_SEQUENCE_INSERT_AT();
void LIST_SEQUENCE_OUT_OF_RANGE();
void ARRAY_SEQUENCE_MAP();
void LIST_SEQUENCE_MAP();
void ARRAY_SEQUENCE_REDUCE();
void LIST_SEQUENCE_REDUCE();
void IMMUTABLE_ARRAY_SEQUENCE_APPEND();
void IMMUTABLE_ARRAY_SEQUENCE_PREPEND();
void IMMUTABLE_ARRAY_SEQUENCE_INSERT_AT();
void IMMUTABLE_ARRAY_SEQUENCE_SET();
void IMMUTABLE_LIST_SEQUENCE_APPEND();
void IMMUTABLE_LIST_SEQUENCE_PREPEND();
void IMMUTABLE_LIST_SEQUENCE_INSERT_AT();
void IMMUTABLE_LIST_SEQUENCE_SET();

#endif //SEQUENCES_TEST_H
