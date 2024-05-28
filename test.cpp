//
// Created by Admin on 11.05.2024.
//

#include "test.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Sequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"
#include "ArrayQueue.h"
#include "ListQueue.h"
#include "Queue.h"
#include "ArrayDeque.h"
#include "Deque.h"
#include "ListDeque.h"
#include "Matrix.h"

int tests_passed; //количество пройденных тестов
const int total_tests = 411; //общее количество тестов

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

void IMMUTABLE_ARRAY_SEQUENCE_APPEND(){
    int items[] = {1, 2, 3, 4, 5};
    ImmutableArraySequence<int> immutableArraySequence(items, 5);
    ImmutableArraySequence<int> *newImmutableArraySequence = immutableArraySequence.append(6);
    ASSERT_INT_EQ(5, immutableArraySequence.getLength());
    ASSERT_INT_EQ(6, newImmutableArraySequence->getLast());
}

void IMMUTABLE_ARRAY_SEQUENCE_PREPEND(){
    int items[] = {1, 2, 3, 4, 5};
    ImmutableArraySequence<int> immutableArraySequence(items, 5);
    ImmutableArraySequence<int> *newImmutableArraySequence = immutableArraySequence.prepend(0);
    ASSERT_INT_EQ(5, immutableArraySequence.getLength());
    ASSERT_INT_EQ(0, newImmutableArraySequence->getFirst());
}

void IMMUTABLE_ARRAY_SEQUENCE_INSERT_AT(){
    int items[] = {1, 2, 3, 4, 5};
    ImmutableArraySequence<int> immutableArraySequence(items, 5);
    ImmutableArraySequence<int> *newImmutableArraySequence = immutableArraySequence.insertAt(2, 2);
    ASSERT_INT_EQ(5, immutableArraySequence.getLength());
    ASSERT_INT_EQ(2, newImmutableArraySequence->get(2));
    ASSERT_INT_EQ(3, newImmutableArraySequence->get(3));
    ASSERT_INT_EQ(4, newImmutableArraySequence->get(4));
}

void IMMUTABLE_ARRAY_SEQUENCE_SET(){
    int items[] = {1, 2, 3, 4, 5};
    ImmutableArraySequence<int> immutableArraySequence(items, 5);
    ImmutableArraySequence<int> *newImmutableArraySequence = immutableArraySequence.set(10, 2);
    ASSERT_INT_EQ(5, immutableArraySequence.getLength());
    ASSERT_INT_EQ(10, newImmutableArraySequence->get(2));
}

void IMMUTABLE_LIST_SEQUENCE_APPEND(){
    int items[] = {1, 2, 3, 4, 5};
    ImmutableListSequence<int> immutableListSequence(items, 5);
    ImmutableListSequence<int> *newImmutableListSequence = immutableListSequence.append(6);
    ASSERT_INT_EQ(5, immutableListSequence.getLength());
    ASSERT_INT_EQ(6, newImmutableListSequence->getLast());
}

void IMMUTABLE_LIST_SEQUENCE_PREPEND(){
    int items[] = {1, 2, 3, 4, 5};
    ImmutableListSequence<int> immutableListSequence(items, 5);
    ImmutableListSequence<int> *newImmutableListSequence = immutableListSequence.prepend(0);
    ASSERT_INT_EQ(5, immutableListSequence.getLength());
    ASSERT_INT_EQ(0, newImmutableListSequence->getFirst());
}

void IMMUTABLE_LIST_SEQUENCE_INSERT_AT(){
    int items[] = {1, 2, 3, 4, 5};
    ImmutableListSequence<int> immutableListSequence(items, 5);
    ImmutableListSequence<int> *newImmutableListSequence = immutableListSequence.insertAt(2, 2);
    ASSERT_INT_EQ(5, immutableListSequence.getLength());
    ASSERT_INT_EQ(2, newImmutableListSequence->get(2));
    ASSERT_INT_EQ(3, newImmutableListSequence->get(3));
    ASSERT_INT_EQ(4, newImmutableListSequence->get(4));
}

void IMMUTABLE_LIST_SEQUENCE_SET(){
    int items[] = {1, 2, 3, 4, 5};
    ImmutableListSequence<int> immutableListSequence(items, 5);
    ImmutableListSequence<int> *newImmutableListSequence = immutableListSequence.set(10, 2);
    ASSERT_INT_EQ(5, immutableListSequence.getLength());
    ASSERT_INT_EQ(10, newImmutableListSequence->get(2));
}

void CREATE_ARRAY_QUEUE(){
    ArrayQueue<int> arrayQueue;
    ASSERT_INT_EQ(0, arrayQueue.getLength());
    ASSERT_NOT_NULL(arrayQueue.getArray());
    ASSERT_INT_EQ(0, arrayQueue.getArray()->getLength());
}

void CREATE_ARRAY_QUEUE_FROM_ARRAY(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayQueue<int> arrayQueue(items, 5);
    ASSERT_INT_EQ(5, arrayQueue.getLength());
    ASSERT_NOT_NULL(arrayQueue.getArray());
    ASSERT_INT_EQ(5, arrayQueue.getArray()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], arrayQueue.getArray()->get(i));
    }
}

void COPY_ARRAY_QUEUE(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayQueue<int> arrayQueue(items, 5);
    ArrayQueue<int> arrayQueueCopy(arrayQueue);
    ASSERT_INT_EQ(5, arrayQueueCopy.getLength());
    ASSERT_NOT_NULL(arrayQueueCopy.getArray());
    ASSERT_INT_EQ(5, arrayQueueCopy.getArray()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], arrayQueueCopy.getArray()->get(i));
    }
}

void ARRAY_QUEUE_PUSH(){
    ArrayQueue<int> arrayQueue;
    arrayQueue.push(1);
    ASSERT_INT_EQ(1, arrayQueue.getLength());
    ASSERT_INT_EQ(1, arrayQueue.getArray()->get(0));
    arrayQueue.push(2);
    ASSERT_INT_EQ(2, arrayQueue.getLength());
    ASSERT_INT_EQ(2, arrayQueue.getArray()->get(1));
    arrayQueue.push(3);
    ASSERT_INT_EQ(3, arrayQueue.getLength());
    ASSERT_INT_EQ(3, arrayQueue.getArray()->get(2));
}

void ARRAY_QUEUE_FRONT(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayQueue<int> arrayQueue(items, 5);
    ASSERT_INT_EQ(1, arrayQueue.front());
}

void ARRAY_QUEUE_POP(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayQueue<int> arrayQueue(items, 5);
    arrayQueue.pop();
    ASSERT_INT_EQ(4, arrayQueue.getLength());
    ASSERT_INT_EQ(2, arrayQueue.getArray()->get(0));
    ASSERT_INT_EQ(3, arrayQueue.getArray()->get(1));
    ASSERT_INT_EQ(4, arrayQueue.getArray()->get(2));
    ASSERT_INT_EQ(5, arrayQueue.getArray()->get(3));
}

void ARRAY_QUEUE_GET_SUB_QUEUE(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayQueue<int> arrayQueue(items, 5);
    Queue<int> *subArrayQueue = arrayQueue.getSubQueue(1, 3);
    ASSERT_INT_EQ(3, subArrayQueue->getLength());
    ASSERT_INT_EQ(2, subArrayQueue->get(0));
    ASSERT_INT_EQ(3, subArrayQueue->get(1));
    ASSERT_INT_EQ(4, subArrayQueue->get(2));
}

void ARRAY_QUEUE_OUT_OF_RANGE(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayQueue<int> arrayQueue(items, 5);
    try {
        arrayQueue.getSubQueue(1, 10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
}

void ARRAY_QUEUE_SPLIT(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayQueue<int> arrayQueue(items, 5);
    auto [firstQueue, secondQueue] = arrayQueue.split([](int x) { return x % 2 == 0; });
    ASSERT_INT_EQ(2, firstQueue->getLength());
    ASSERT_INT_EQ(2, firstQueue->get(0));
    ASSERT_INT_EQ(4, firstQueue->get(1));
    ASSERT_INT_EQ(3, secondQueue->getLength());
    ASSERT_INT_EQ(1, secondQueue->get(0));
    ASSERT_INT_EQ(3, secondQueue->get(1));
    ASSERT_INT_EQ(5, secondQueue->get(2));
}

void CREATE_LIST_QUEUE(){
    ListQueue<int> listQueue;
    ASSERT_INT_EQ(0, listQueue.getLength());
    ASSERT_NOT_NULL(listQueue.getLinkedList());
    ASSERT_INT_EQ(0, listQueue.getLinkedList()->getLength());
}

void CREATE_LIST_QUEUE_FROM_ARRAY(){
    int items[] = {1, 2, 3, 4, 5};
    ListQueue<int> listQueue(items, 5);
    ASSERT_INT_EQ(5, listQueue.getLength());
    ASSERT_NOT_NULL(listQueue.getLinkedList());
    ASSERT_INT_EQ(5, listQueue.getLinkedList()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], listQueue.getLinkedList()->get(i));
    }
}

void COPY_LIST_QUEUE(){
    int items[] = {1, 2, 3, 4, 5};
    ListQueue<int> listQueue(items, 5);
    ListQueue<int> listQueueCopy(listQueue);
    ASSERT_INT_EQ(5, listQueueCopy.getLength());
    ASSERT_NOT_NULL(listQueueCopy.getLinkedList());
    ASSERT_INT_EQ(5, listQueueCopy.getLinkedList()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], listQueueCopy.getLinkedList()->get(i));
    }
}

void LIST_QUEUE_PUSH(){
    ListQueue<int> listQueue;
    listQueue.push(1);
    ASSERT_INT_EQ(1, listQueue.getLength());
    ASSERT_INT_EQ(1, listQueue.getLinkedList()->get(0));
    listQueue.push(2);
    ASSERT_INT_EQ(2, listQueue.getLength());
    ASSERT_INT_EQ(2, listQueue.getLinkedList()->get(1));
    listQueue.push(3);
    ASSERT_INT_EQ(3, listQueue.getLength());
    ASSERT_INT_EQ(3, listQueue.getLinkedList()->get(2));
}

void LIST_QUEUE_FRONT(){
    int items[] = {1, 2, 3, 4, 5};
    ListQueue<int> listQueue(items, 5);
    ASSERT_INT_EQ(1, listQueue.front());
}

void LIST_QUEUE_POP(){
    int items[] = {1, 2, 3, 4, 5};
    ListQueue<int> listQueue(items, 5);
    listQueue.pop();
    ASSERT_INT_EQ(4, listQueue.getLength());
    ASSERT_INT_EQ(2, listQueue.getLinkedList()->get(0));
    ASSERT_INT_EQ(3, listQueue.getLinkedList()->get(1));
    ASSERT_INT_EQ(4, listQueue.getLinkedList()->get(2));
    ASSERT_INT_EQ(5, listQueue.getLinkedList()->get(3));
}

void LIST_QUEUE_GET_SUB_QUEUE(){
    int items[] = {1, 2, 3, 4, 5};
    ListQueue<int> listQueue(items, 5);
    Queue<int> *subListQueue = listQueue.getSubQueue(1, 3);
    ASSERT_INT_EQ(3, subListQueue->getLength());
    ASSERT_INT_EQ(2, subListQueue->get(0));
    ASSERT_INT_EQ(3, subListQueue->get(1));
    ASSERT_INT_EQ(4, subListQueue->get(2));
}

void LIST_QUEUE_OUT_OF_RANGE(){
    int items[] = {1, 2, 3, 4, 5};
    ListQueue<int> listQueue(items, 5);
    try {
        listQueue.getSubQueue(1, 10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
}

void LIST_QUEUE_SPLIT(){
    int items[] = {1, 2, 3, 4, 5};
    ListQueue<int> listQueue(items, 5);
    auto [firstQueue, secondQueue] = listQueue.split([](int x) { return x % 2 == 0; });
    ASSERT_INT_EQ(2, firstQueue->getLength());
    ASSERT_INT_EQ(2, firstQueue->get(0));
    ASSERT_INT_EQ(4, firstQueue->get(1));
    ASSERT_INT_EQ(3, secondQueue->getLength());
    ASSERT_INT_EQ(1, secondQueue->get(0));
    ASSERT_INT_EQ(3, secondQueue->get(1));
    ASSERT_INT_EQ(5, secondQueue->get(2));
}

void CREATE_ARRAY_DEQUE(){
    ArrayDeque<int> arrayDeque;
    ASSERT_INT_EQ(0, arrayDeque.getLength());
    ASSERT_NOT_NULL(arrayDeque.getArrayDeque()->getArray());
    ASSERT_INT_EQ(0, arrayDeque.getLength());
}

void CREATE_ARRAY_DEQUE_FROM_ARRAY(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayDeque<int> arrayDeque(items, 5);
    ASSERT_INT_EQ(5, arrayDeque.getLength());
    ASSERT_NOT_NULL(arrayDeque.getArrayDeque()->getArray());
    ASSERT_INT_EQ(5, arrayDeque.getArrayDeque()->getArray()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], arrayDeque.getArrayDeque()->getArray()->get(i));
    }
}

void COPY_ARRAY_DEQUE(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayDeque<int> arrayDeque(items, 5);
    ArrayDeque<int> arrayDequeCopy(arrayDeque);
    ASSERT_INT_EQ(5, arrayDequeCopy.getLength());
    ASSERT_NOT_NULL(arrayDequeCopy.getArrayDeque()->getArray());
    ASSERT_INT_EQ(5, arrayDequeCopy.getArrayDeque()->getArray()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], arrayDequeCopy.getArrayDeque()->getArray()->get(i));
    }
}

void ARRAY_DEQUE_PUSH_FRONT(){
    ArrayDeque<int> arrayDeque;
    arrayDeque.push_front(1);
    ASSERT_INT_EQ(1, arrayDeque.getLength());
    ASSERT_INT_EQ(1, arrayDeque.getArrayDeque()->getArray()->get(0));
    arrayDeque.push_front(2);
    ASSERT_INT_EQ(2, arrayDeque.getLength());
    ASSERT_INT_EQ(2, arrayDeque.getArrayDeque()->getArray()->get(0));
    ASSERT_INT_EQ(1, arrayDeque.getArrayDeque()->getArray()->get(1));
    arrayDeque.push_front(3);
    ASSERT_INT_EQ(3, arrayDeque.getLength());
    ASSERT_INT_EQ(3, arrayDeque.getArrayDeque()->getArray()->get(0));
    ASSERT_INT_EQ(2, arrayDeque.getArrayDeque()->getArray()->get(1));
    ASSERT_INT_EQ(1, arrayDeque.getArrayDeque()->getArray()->get(2));
}

void ARRAY_DEQUE_PUSH_BACK(){
    ArrayDeque<int> arrayDeque;
    arrayDeque.push_back(1);
    ASSERT_INT_EQ(1, arrayDeque.getLength());
    ASSERT_INT_EQ(1, arrayDeque.getArrayDeque()->getArray()->get(0));
    arrayDeque.push_back(2);
    ASSERT_INT_EQ(2, arrayDeque.getLength());
    ASSERT_INT_EQ(1, arrayDeque.getArrayDeque()->getArray()->get(0));
    ASSERT_INT_EQ(2, arrayDeque.getArrayDeque()->getArray()->get(1));
    arrayDeque.push_back(3);
    ASSERT_INT_EQ(3, arrayDeque.getLength());
    ASSERT_INT_EQ(1, arrayDeque.getArrayDeque()->getArray()->get(0));
    ASSERT_INT_EQ(2, arrayDeque.getArrayDeque()->getArray()->get(1));
    ASSERT_INT_EQ(3, arrayDeque.getArrayDeque()->getArray()->get(2));
}

void ARRAY_DEQUE_FRONT(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayDeque<int> arrayDeque(items, 5);
    ASSERT_INT_EQ(1, arrayDeque.front());
}

void ARRAY_DEQUE_BACK(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayDeque<int> arrayDeque(items, 5);
    ASSERT_INT_EQ(5, arrayDeque.back());
}

void ARRAY_DEQUE_POP_FRONT(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayDeque<int> arrayDeque(items, 5);
    arrayDeque.pop_front();
    ASSERT_INT_EQ(4, arrayDeque.getLength());
    ASSERT_INT_EQ(2, arrayDeque.getArrayDeque()->getArray()->get(0));
    ASSERT_INT_EQ(3, arrayDeque.getArrayDeque()->getArray()->get(1));
    ASSERT_INT_EQ(4, arrayDeque.getArrayDeque()->getArray()->get(2));
    ASSERT_INT_EQ(5, arrayDeque.getArrayDeque()->getArray()->get(3));
}

void ARRAY_DEQUE_POP_BACK(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayDeque<int> arrayDeque(items, 5);
    arrayDeque.pop_back();
    ASSERT_INT_EQ(4, arrayDeque.getLength());
    ASSERT_INT_EQ(1, arrayDeque.getArrayDeque()->getArray()->get(0));
    ASSERT_INT_EQ(2, arrayDeque.getArrayDeque()->getArray()->get(1));
    ASSERT_INT_EQ(3, arrayDeque.getArrayDeque()->getArray()->get(2));
    ASSERT_INT_EQ(4, arrayDeque.getArrayDeque()->getArray()->get(3));
}

void ARRAY_DEQUE_GET_SUB_DEQUE(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayDeque<int> arrayDeque(items, 5);
    Deque<int> *subArrayDeque = arrayDeque.getSubDeque(1, 3);
    ASSERT_INT_EQ(3, subArrayDeque->getLength());
    ASSERT_INT_EQ(2, subArrayDeque->get(0));
    ASSERT_INT_EQ(3, subArrayDeque->get(1));
    ASSERT_INT_EQ(4, subArrayDeque->get(2));
}

void ARRAY_DEQUE_OUT_OF_RANGE(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayDeque<int> arrayDeque(items, 5);
    try {
        arrayDeque.getSubDeque(1, 10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
}

void ARRAY_DEQUE_SPLIT(){
    int items[] = {1, 2, 3, 4, 5};
    ArrayDeque<int> arrayDeque(items, 5);
    auto [firstDeque, secondDeque] = arrayDeque.split([](int x) { return x % 2 == 0; });
    ASSERT_INT_EQ(2, firstDeque->getLength());
    ASSERT_INT_EQ(2, firstDeque->get(0));
    ASSERT_INT_EQ(4, firstDeque->get(1));
    ASSERT_INT_EQ(3, secondDeque->getLength());
    ASSERT_INT_EQ(1, secondDeque->get(0));
    ASSERT_INT_EQ(3, secondDeque->get(1));
    ASSERT_INT_EQ(5, secondDeque->get(2));
}

void CREATE_LIST_DEQUE(){
    ListDeque<int> listDeque;
    ASSERT_INT_EQ(0, listDeque.getLength());
    ASSERT_NOT_NULL(listDeque.getListDeque());
    ASSERT_INT_EQ(0, listDeque.getListDeque()->getLength());
}

void CREATE_LIST_DEQUE_FROM_ARRAY(){
    int items[] = {1, 2, 3, 4, 5};
    ListDeque<int> listDeque(items, 5);
    ASSERT_INT_EQ(5, listDeque.getLength());
    ASSERT_NOT_NULL(listDeque.getListDeque());
    ASSERT_INT_EQ(5, listDeque.getListDeque()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], listDeque.getListDeque()->get(i));
    }
}

void COPY_LIST_DEQUE(){
    int items[] = {1, 2, 3, 4, 5};
    ListDeque<int> listDeque(items, 5);
    ListDeque<int> listDequeCopy(listDeque);
    ASSERT_INT_EQ(5, listDequeCopy.getLength());
    ASSERT_NOT_NULL(listDequeCopy.getListDeque());
    ASSERT_INT_EQ(5, listDequeCopy.getListDeque()->getLength());
    for (int i = 0; i < 5; i++) {
        ASSERT_INT_EQ(items[i], listDequeCopy.getListDeque()->get(i));
    }
}

void LIST_DEQUE_PUSH_FRONT(){
    ListDeque<int> listDeque;
    listDeque.push_front(1);
    ASSERT_INT_EQ(1, listDeque.getLength());
    ASSERT_INT_EQ(1, listDeque.getListDeque()->get(0));
    listDeque.push_front(2);
    ASSERT_INT_EQ(2, listDeque.getLength());
    ASSERT_INT_EQ(2, listDeque.getListDeque()->get(0));
    ASSERT_INT_EQ(1, listDeque.getListDeque()->get(1));
    listDeque.push_front(3);
    ASSERT_INT_EQ(3, listDeque.getLength());
    ASSERT_INT_EQ(3, listDeque.getListDeque()->get(0));
    ASSERT_INT_EQ(2, listDeque.getListDeque()->get(1));
    ASSERT_INT_EQ(1, listDeque.getListDeque()->get(2));
}

void LIST_DEQUE_PUSH_BACK(){
    ListDeque<int> listDeque;
    listDeque.push_back(1);
    ASSERT_INT_EQ(1, listDeque.getLength());
    ASSERT_INT_EQ(1, listDeque.getListDeque()->get(0));
    listDeque.push_back(2);
    ASSERT_INT_EQ(2, listDeque.getLength());
    ASSERT_INT_EQ(1, listDeque.getListDeque()->get(0));
    ASSERT_INT_EQ(2, listDeque.getListDeque()->get(1));
    listDeque.push_back(3);
    ASSERT_INT_EQ(3, listDeque.getLength());
    ASSERT_INT_EQ(1, listDeque.getListDeque()->get(0));
    ASSERT_INT_EQ(2, listDeque.getListDeque()->get(1));
    ASSERT_INT_EQ(3, listDeque.getListDeque()->get(2));
}

void LIST_DEQUE_FRONT(){
    int items[] = {1, 2, 3, 4, 5};
    ListDeque<int> listDeque(items, 5);
    ASSERT_INT_EQ(1, listDeque.front());
}

void LIST_DEQUE_BACK(){
    int items[] = {1, 2, 3, 4, 5};
    ListDeque<int> listDeque(items, 5);
    ASSERT_INT_EQ(5, listDeque.back());
}

void LIST_DEQUE_POP_FRONT(){
    int items[] = {1, 2, 3, 4, 5};
    ListDeque<int> listDeque(items, 5);
    listDeque.pop_front();
    ASSERT_INT_EQ(4, listDeque.getLength());
    ASSERT_INT_EQ(2, listDeque.getListDeque()->get(0));
    ASSERT_INT_EQ(3, listDeque.getListDeque()->get(1));
    ASSERT_INT_EQ(4, listDeque.getListDeque()->get(2));
    ASSERT_INT_EQ(5, listDeque.getListDeque()->get(3));
}

void LIST_DEQUE_POP_BACK(){
    int items[] = {1, 2, 3, 4, 5};
    ListDeque<int> listDeque(items, 5);
    listDeque.pop_back();
    ASSERT_INT_EQ(4, listDeque.getLength());
    ASSERT_INT_EQ(1, listDeque.getListDeque()->get(0));
    ASSERT_INT_EQ(2, listDeque.getListDeque()->get(1));
    ASSERT_INT_EQ(3, listDeque.getListDeque()->get(2));
    ASSERT_INT_EQ(4, listDeque.getListDeque()->get(3));
}

void LIST_DEQUE_GET_SUB_DEQUE(){
    int items[] = {1, 2, 3, 4, 5};
    ListDeque<int> listDeque(items, 5);
    Deque<int> *subListDeque = listDeque.getSubDeque(1, 3);
    ASSERT_INT_EQ(3, subListDeque->getLength());
    ASSERT_INT_EQ(2, subListDeque->get(0));
    ASSERT_INT_EQ(3, subListDeque->get(1));
    ASSERT_INT_EQ(4, subListDeque->get(2));
}

void LIST_DEQUE_OUT_OF_RANGE(){
    int items[] = {1, 2, 3, 4, 5};
    ListDeque<int> listDeque(items, 5);
    try {
        listDeque.getSubDeque(1, 10);
    } catch (std::out_of_range &e) {
        ASSERT_STRING_EQ("Index out of range", e.what());
    }
}

void LIST_DEQUE_SPLIT(){
    int items[] = {1, 2, 3, 4, 5};
    ListDeque<int> listDeque(items, 5);
    auto [firstDeque, secondDeque] = listDeque.split([](int x) { return x % 2 == 0; });
    ASSERT_INT_EQ(2, firstDeque->getLength());
    ASSERT_INT_EQ(2, firstDeque->get(0));
    ASSERT_INT_EQ(4, firstDeque->get(1));
    ASSERT_INT_EQ(3, secondDeque->getLength());
    ASSERT_INT_EQ(1, secondDeque->get(0));
    ASSERT_INT_EQ(3, secondDeque->get(1));
    ASSERT_INT_EQ(5, secondDeque->get(2));
}

void CREATE_MATRIX(){
    Matrix matrix(3, 3);
    ASSERT_INT_EQ(3, matrix.getRows());
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_INT_EQ(0, matrix[i][j]);
        }
    }
}

void CREATE_MATRIX_FROM_VECTOR(){
    std::vector<std::vector<double>> items = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix(items);
    ASSERT_INT_EQ(3, matrix.getRows());
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_INT_EQ(items[i][j], matrix[i][j]);
        }
    }
}

void COPY_MATRIX(){
    std::vector<std::vector<double>> items = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix(items);
    Matrix matrixCopy(matrix);
    ASSERT_INT_EQ(3, matrixCopy.getRows());
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_INT_EQ(items[i][j], matrixCopy[i][j]);
        }
    }
}

void MATRIX_SUM(){
    std::vector<std::vector<double>> items1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix1(items1);
    std::vector<std::vector<double>> items2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    Matrix matrix2(items2);
    Matrix matrixSum = matrix1 + matrix2;
    ASSERT_INT_EQ(3, matrixSum.getRows());
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_INT_EQ(items1[i][j] + items2[i][j], matrixSum[i][j]);
        }
    }
}

void MATRIX_DIFFERENCE(){
    std::vector<std::vector<double>> items1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix1(items1);
    std::vector<std::vector<double>> items2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    Matrix matrix2(items2);
    Matrix matrixDifference = matrix1 - matrix2;
    ASSERT_INT_EQ(3, matrixDifference.getRows());
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_INT_EQ(items1[i][j] - items2[i][j], matrixDifference[i][j]);
        }
    }
}

void MATRIX_MULTIPLICATION(){
    std::vector<std::vector<double>> items1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix1(items1);
    std::vector<std::vector<double>> items2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    Matrix matrix2(items2);
    Matrix matrixMultiplication = matrix1 * matrix2;
    ASSERT_INT_EQ(3, matrixMultiplication.getRows());
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_INT_EQ(items1[i][0] * items2[0][j] + items1[i][1] * items2[1][j] + items1[i][2] * items2[2][j], matrixMultiplication[i][j]);
        }
    }
}

void MATRIX_MULTIPLICATION_BY_NUMBER(){
    std::vector<std::vector<double>> items = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix(items);
    Matrix matrixMultiplication = matrix * 2;
    ASSERT_INT_EQ(3, matrixMultiplication.getRows());
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_INT_EQ(items[i][j] * 2, matrixMultiplication[i][j]);
        }
    }
}

void MATRIX_DETERMINANT(){
    std::vector<std::vector<double>> items = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix(items);
    ASSERT_INT_EQ(0, matrix.determinant());
}

void MATRIX_TRANSPOSE(){
    std::vector<std::vector<double>> items = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix(items);
    Matrix matrixTranspose = matrix.transpose();
    ASSERT_INT_EQ(3, matrixTranspose.getRows());
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_INT_EQ(items[j][i], matrixTranspose[i][j]);
        }
    }
}
