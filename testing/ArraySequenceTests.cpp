// Тесты класса ArraySequence

#include "gtest/gtest.h"
#include "../ArraySequence.h"

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

TEST(ArraySequence, Clear){
    ArraySequence<int> arraySequence;
    for (int i = 0; i < 5; i++) {
        arraySequence.append(i);
    }
    arraySequence.clear();
    EXPECT_EQ(arraySequence.getLength(), 0);
}