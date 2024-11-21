#include "gtest/gtest.h"
#include "../ListSequence.h"
#include "../ArraySequence.h"
#include "../Sequence.h"
#include "../QSorter.h"
#include "../PSorter.h"
#include "../ISorter.h"
#include "../BubbleSorter.h"

// Тесты

TEST(ArraySequence, Constructor) {
    int* items = new int[5];
    for (int i = 0; i < 5; i++) {
        items[i] = i;
    }
    ArraySequence<int> arraySequence(items, 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence.get(i), i);
    }
}

TEST(ArraySequence, CopyConstructor) {
    int* items = new int[5];
    for (int i = 0; i < 5; i++) {
        items[i] = i;
    }
    ArraySequence<int> arraySequence(items, 5);
    ArraySequence<int> arraySequenceCopy(arraySequence);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequenceCopy.get(i), i);
    }
}

TEST(ArraySequence, Get) {
    int* items = new int[5];
    for (int i = 0; i < 5; i++) {
        items[i] = i;
    }
    ArraySequence<int> arraySequence(items, 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence.get(i), i);
    }
}

TEST(ArraySequence, GetLength) {
    int* items = new int[5];
    for (int i = 0; i < 5; i++) {
        items[i] = i;
    }
    ArraySequence<int> arraySequence(items, 5);
    EXPECT_EQ(arraySequence.getLength(), 5);
}

TEST(ArraySequence, Append) {
    ArraySequence<int> arraySequence;
    for (int i = 0; i < 5; i++) {
        arraySequence.append(i);
    }
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence.get(i), i);
    }
}

TEST(ArraySequence, Prepend) {
    ArraySequence<int> arraySequence;
    for (int i = 0; i < 5; i++) {
        arraySequence.prepend(i);
    }
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence.get(i), 4 - i);
    }
}

TEST(ArraySequence, InsertAt) {
    ArraySequence<int> arraySequence;
    for (int i = 0; i < 5; i++) {
        arraySequence.append(i);
    }
    arraySequence.insertAt(10, 2);
    EXPECT_EQ(arraySequence.get(2), 10);
}

TEST(ArraySequence, Set) {
    ArraySequence<int> arraySequence;
    for (int i = 0; i < 5; i++) {
        arraySequence.append(i);
    }
    arraySequence.set(10, 2);
    EXPECT_EQ(arraySequence.get(2), 10);
}

TEST(ListSequence, Constructor) {
    int* items = new int[5];
    for (int i = 0; i < 5; i++) {
        items[i] = i;
    }
    ListSequence<int> listSequence(items, 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence.get(i), i);
    }
}

TEST(ListSequence, CopyConstructor) {
    int* items = new int[5];
    for (int i = 0; i < 5; i++) {
        items[i] = i;
    }
    ListSequence<int> listSequence(items, 5);
    ListSequence<int> listSequenceCopy(listSequence);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequenceCopy.get(i), i);
    }
}

TEST(ListSequence, Get) {
    int* items = new int[5];
    for (int i = 0; i < 5; i++) {
        items[i] = i;
    }
    ListSequence<int> listSequence(items, 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence.get(i), i);
    }
}

TEST(ListSequence, GetLength) {
    int* items = new int[5];
    for (int i = 0; i < 5; i++) {
        items[i] = i;
    }
    ListSequence<int> listSequence(items, 5);
    EXPECT_EQ(listSequence.getLength(), 5);
}

TEST(ListSequence, Append) {
    ListSequence<int> listSequence;
    for (int i = 0; i < 5; i++) {
        listSequence.append(i);
    }
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence.get(i), i);
    }
}

TEST(ListSequence, Prepend) {
    ListSequence<int> listSequence;
    for (int i = 0; i < 5; i++) {
        listSequence.prepend(i);
    }
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence.get(i), 4 - i);
    }
}

TEST(ListSequence, InsertAt) {
    ListSequence<int> listSequence;
    for (int i = 0; i < 5; i++) {
        listSequence.append(i);
    }
    listSequence.insertAt(10, 2);
    EXPECT_EQ(listSequence.get(2), 10);
}

TEST(ListSequence, Set) {
    ListSequence<int> listSequence;
    for (int i = 0; i < 5; i++) {
        listSequence.append(i);
    }
    listSequence.set(10, 2);
    EXPECT_EQ(listSequence.get(2), 10);
}

TEST(ArraySequence, Clear){
    ArraySequence<int> arraySequence;
    for (int i = 0; i < 5; i++) {
        arraySequence.append(i);
    }
    arraySequence.clear();
    EXPECT_EQ(arraySequence.getLength(), 0);
}

TEST(ListSequence, Clear){
    ListSequence<int> listSequence;
    for (int i = 0; i < 5; i++) {
        listSequence.append(i);
    }
    listSequence.clear();
    EXPECT_EQ(listSequence.getLength(), 0);
}

TEST(QSorter, Sort) {
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *arraySequence = new ArraySequence<int>(items, 5);
    QSorter<int> qSorter;
    qSorter.sort(arraySequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence->get(i), i + 1);
    }
    delete arraySequence;
}

TEST(PSorter, Sort) {
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *arraySequence = new ArraySequence<int>(items, 5);
    PSorter<int> pSorter;
    pSorter.sort(arraySequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence->get(i), i + 1);
    }
    delete arraySequence;
}

TEST(QSorter, SortList){
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *listSequence = new ListSequence<int>(items, 5);
    QSorter<int> qSorter;
    qSorter.sort(listSequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence->get(i), i + 1);
    }
    delete listSequence;
}

TEST(PSorter, SortList){
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *listSequence = new ListSequence<int>(items, 5);
    PSorter<int> pSorter;
    pSorter.sort(listSequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence->get(i), i + 1);
    }
    delete listSequence;
}

TEST(BubbleSorter, Sort){
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *arraySequence = new ArraySequence<int>(items, 5);
    BubbleSorter<int> bubbleSorter;
    bubbleSorter.sort(arraySequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence->get(i), i + 1);
    }
    delete arraySequence;
}

TEST(BubbleSorter, SortList){
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *listSequence = new ListSequence<int>(items, 5);
    BubbleSorter<int> bubbleSorter;
    bubbleSorter.sort(listSequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence->get(i), i + 1);
    }
    delete listSequence;
}