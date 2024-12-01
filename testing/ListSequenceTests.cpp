#include "gtest/gtest.h"
#include "../ListSequence.h"

//Тесты класса ListSequence

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

TEST(ListSequence, Clear){
    ListSequence<int> listSequence;
    for (int i = 0; i < 5; i++) {
        listSequence.append(i);
    }
    listSequence.clear();
    EXPECT_EQ(listSequence.getLength(), 0);
}