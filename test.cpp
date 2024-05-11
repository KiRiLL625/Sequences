//
// Created by Admin on 11.05.2024.
//

#include "test.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Sequence.h"

int tests_passed; //количество пройденных тестов
const int total_tests = 118; //общее количество тестов

//Проверка на создание пустой последовательности на основе массива
void CREATE_ARRAY_SEQUENCE(){
    ArraySequence<int> arraySequence;
    ASSERT_INT_EQ(0, arraySequence.getLength());
    ASSERT_NOT_NULL(arraySequence.getArray());
    ASSERT_INT_EQ(0, arraySequence.getArray()->getLength());
}

//Проверка на создание последовательности на основе массива
void CREATE_ARRAY_SEQUENCE_FROM_ARRAY(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    ASSERT_INT_EQ(5, arraySequence.getLength());
    ASSERT_NOT_NULL(arraySequence.getArray());
    ASSERT_INT_EQ(5, arraySequence.getArray()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], arraySequence.getArray()->get(i));
    }
}

//Проверка на создание копии последовательности
void COPY_ARRAY_SEQUENCE(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    ArraySequence<int> arraySequenceCopy(arraySequence);
    ASSERT_INT_EQ(5, arraySequenceCopy.getLength());
    ASSERT_NOT_NULL(arraySequenceCopy.getArray());
    ASSERT_INT_EQ(5, arraySequenceCopy.getArray()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], arraySequenceCopy.getArray()->get(i));
    }
}

//Проверка на добавление элементов в последовательность на основе массива
void CREATE_LIST_SEQUENCE(){
    ListSequence<int> listSequence;
    ASSERT_INT_EQ(0, listSequence.getLength());
    ASSERT_NOT_NULL(listSequence.getLinkedList());
    ASSERT_INT_EQ(0, listSequence.getLinkedList()->getLength());
}

//Проверка на создание пустой последовательности на основе двусвязного списка
void CREATE_LIST_SEQUENCE_FROM_ARRAY(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    ASSERT_INT_EQ(5, listSequence.getLength());
    ASSERT_NOT_NULL(listSequence.getLinkedList());
    ASSERT_INT_EQ(5, listSequence.getLinkedList()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], listSequence.getLinkedList()->get(i));
    }
}

//Проверка на создание копии последовательности на основе двусвязного списка
void COPY_LIST_SEQUENCE(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    ListSequence<int> listSequenceCopy(listSequence);
    ASSERT_INT_EQ(5, listSequenceCopy.getLength());
    ASSERT_NOT_NULL(listSequenceCopy.getLinkedList());
    ASSERT_INT_EQ(5, listSequenceCopy.getLinkedList()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], listSequenceCopy.getLinkedList()->get(i));
    }
}

//Проверка на добавление элементов в конец в последовательность на основе двусвязного списка
void ARRAY_SEQUENCE_APPEND(){
    ArraySequence<int> arraySequence;
    arraySequence.append(1);
    ASSERT_INT_EQ(1, arraySequence.getLength());
    ASSERT_INT_EQ(1, arraySequence.getArray()->get(0));
    arraySequence.append(2);
    ASSERT_INT_EQ(2, arraySequence.getLength());
    ASSERT_INT_EQ(2, arraySequence.getArray()->get(1));
    arraySequence.append(3);
    ASSERT_INT_EQ(3, arraySequence.getLength());
    ASSERT_INT_EQ(3, arraySequence.getArray()->get(2));
}

//Проверка на добавление элементов в конец в последовательность (копию) на основе массива
void ARRAY_SEQUENCE_APPEND_IMMUTABLE(){
    ArraySequence<int> arraySequence;
    arraySequence.append(1);
    ArraySequence<int> *new_array = arraySequence.append_immutable(2);
    ASSERT_INT_EQ(1, arraySequence.getLength());
    ASSERT_INT_EQ(1, arraySequence.getArray()->get(0));
    ASSERT_INT_EQ(2, new_array->getLength());
    ASSERT_INT_EQ(1, new_array->getArray()->get(0));
    ASSERT_INT_EQ(2, new_array->getArray()->get(1));
    new_array->append(3);
    ASSERT_INT_EQ(1, arraySequence.getLength());
    ASSERT_INT_EQ(3, new_array->getLength());
    ASSERT_INT_EQ(3, new_array->getArray()->get(2));
}

//Проверка на получение первого элемента последовательности на основе массива
void ARRAY_SEQUENCE_GET_FIRST(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    ASSERT_INT_EQ(1, arraySequence.getFirst());
}

//Проверка на получение последнего элемента последовательности на основе массива
void ARRAY_SEQUENCE_GET_LAST(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    ASSERT_INT_EQ(5, arraySequence.getLast());
}

//Проверка на получение элемента последовательности на основе массива
void ARRAY_SEQUENCE_GET(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    ASSERT_INT_EQ(3, arraySequence.get(2));
}

//Проверка на получение подпоследовательности последовательности на основе массива
void ARRAY_SEQUENCE_GET_SUBSEQUENCE(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    ArraySequence<int> *subArray = arraySequence.getSubsequence(1, 3);
    ASSERT_INT_EQ(3, subArray->getLength());
    ASSERT_INT_EQ(2, subArray->get(0));
    ASSERT_INT_EQ(3, subArray->get(1));
    ASSERT_INT_EQ(4, subArray->get(2));
}

//Проверка на добавление элемента в последовательность на основе массива
void ARRAY_SEQUENCE_INSERT_AT(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    arraySequence.insertAt(2, 2);
    ASSERT_INT_EQ(6, arraySequence.getLength());
    ASSERT_INT_EQ(2, arraySequence.get(2));
    ASSERT_INT_EQ(3, arraySequence.get(3));
    ASSERT_INT_EQ(4, arraySequence.get(4));
}

//Проверка на выход за границы последовательности на основе массива
void ARRAY_SEQUENCE_OUT_OF_RANGE(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    try {
        arraySequence.get(10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
    try {
        arraySequence.insertAt(2, 10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
    try {
        arraySequence.getSubsequence(1, 10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
}

//Проверка на добавление элементов в последовательность на основе двусвязного списка
void LIST_SEQUENCE_APPEND(){
    ListSequence<int> listSequence;
    listSequence.append(1);
    ASSERT_INT_EQ(1, listSequence.getLength());
    ASSERT_INT_EQ(1, listSequence.getLinkedList()->get(0));
    listSequence.append(2);
    ASSERT_INT_EQ(2, listSequence.getLength());
    ASSERT_INT_EQ(2, listSequence.getLinkedList()->get(1));
    listSequence.append(3);
    ASSERT_INT_EQ(3, listSequence.getLength());
    ASSERT_INT_EQ(3, listSequence.getLinkedList()->get(2));
}

//Проверка на добавление элементов в последовательность (копию) на основе двусвязного списка
void LIST_SEQUENCE_APPEND_IMMUTABLE(){
    ListSequence<int> listSequence;
    listSequence.append(1);
    ListSequence<int> *new_list = listSequence.append_immutable(2);
    ASSERT_INT_EQ(1, listSequence.getLength());
    ASSERT_INT_EQ(1, listSequence.getLinkedList()->get(0));
    ASSERT_INT_EQ(2, new_list->getLength());
    ASSERT_INT_EQ(1, new_list->getLinkedList()->get(0));
    ASSERT_INT_EQ(2, new_list->getLinkedList()->get(1));
    new_list->append(3);
    ASSERT_INT_EQ(1, listSequence.getLength());
    ASSERT_INT_EQ(3, new_list->getLength());
    ASSERT_INT_EQ(3, new_list->getLinkedList()->get(2));
}

//Проверка на получение первого элемента последовательности на основе двусвязного списка
void LIST_SEQUENCE_GET_FIRST(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    ASSERT_INT_EQ(1, listSequence.getFirst());
}

//Проверка на получение последнего элемента последовательности на основе двусвязного списка
void LIST_SEQUENCE_GET_LAST(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    ASSERT_INT_EQ(5, listSequence.getLast());
}

//Проверка на получение элемента последовательности на основе двусвязного списка
void LIST_SEQUENCE_GET(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    ASSERT_INT_EQ(3, listSequence.get(2));
}

//Проверка на получение подпоследовательности последовательности на основе двусвязного списка
void LIST_SEQUENCE_GET_SUBSEQUENCE(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    ListSequence<int> *subList = listSequence.getSubsequence(1, 3);
    ASSERT_INT_EQ(3, subList->getLength());
    ASSERT_INT_EQ(2, subList->get(0));
    ASSERT_INT_EQ(3, subList->get(1));
    ASSERT_INT_EQ(4, subList->get(2));
}

//Проверка на добавление элемента в последовательность на основе двусвязного списка
void LIST_SEQUENCE_INSERT_AT(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    listSequence.insertAt(2, 2);
    ASSERT_INT_EQ(6, listSequence.getLength());
    ASSERT_INT_EQ(2, listSequence.get(2));
    ASSERT_INT_EQ(3, listSequence.get(3));
    ASSERT_INT_EQ(4, listSequence.get(4));
}

//Проверка на выход за границы последовательности на основе двусвязного списка
void LIST_SEQUENCE_OUT_OF_RANGE(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    try {
        listSequence.get(10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
    try {
        listSequence.insertAt(2, 10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
    try {
        listSequence.getSubsequence(1, 10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
}

//Проверка на применение функции к последовательности на основе массива
void ARRAY_SEQUENCE_MAP(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    map([](int x) { return x * 2; }, &arraySequence);
    ASSERT_INT_EQ(5, arraySequence.getLength());
    ASSERT_INT_EQ(2, arraySequence.get(0));
    ASSERT_INT_EQ(4, arraySequence.get(1));
    ASSERT_INT_EQ(6, arraySequence.get(2));
    ASSERT_INT_EQ(8, arraySequence.get(3));
    ASSERT_INT_EQ(10, arraySequence.get(4));
}

//Проверка на применение функции к последовательности на основе двусвязного списка
void LIST_SEQUENCE_MAP(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    map([](int x) { return x * 2; }, &listSequence);
    ASSERT_INT_EQ(5, listSequence.getLength());
    ASSERT_INT_EQ(2, listSequence.get(0));
    ASSERT_INT_EQ(4, listSequence.get(1));
    ASSERT_INT_EQ(6, listSequence.get(2));
    ASSERT_INT_EQ(8, listSequence.get(3));
    ASSERT_INT_EQ(10, listSequence.get(4));
}

//Проверка на применение функции к последовательности на основе массива
void ARRAY_SEQUENCE_REDUCE(){
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arraySequence(items, 5);
    reduce([](int x, int y) { return x + y; }, &arraySequence, 0);
    ASSERT_INT_EQ(5, arraySequence.getLength());
    ASSERT_INT_EQ(1, arraySequence.get(0));
    ASSERT_INT_EQ(2, arraySequence.get(1));
    ASSERT_INT_EQ(3, arraySequence.get(2));
    ASSERT_INT_EQ(4, arraySequence.get(3));
    ASSERT_INT_EQ(5, arraySequence.get(4));
}

//Проверка на применение функции к последовательности на основе двусвязного списка
void LIST_SEQUENCE_REDUCE(){
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> listSequence(items, 5);
    reduce([](int x, int y) { return x + y; }, &listSequence, 0);
    ASSERT_INT_EQ(5, listSequence.getLength());
    ASSERT_INT_EQ(1, listSequence.get(0));
    ASSERT_INT_EQ(2, listSequence.get(1));
    ASSERT_INT_EQ(3, listSequence.get(2));
    ASSERT_INT_EQ(4, listSequence.get(3));
    ASSERT_INT_EQ(5, listSequence.get(4));
}
