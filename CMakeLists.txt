cmake_minimum_required(VERSION 3.25)
project(Sequences)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS ArrayDeque.h
        ArrayQueue.h
        ArraySequence.h
        Deque.h
        DynamicArray.h
        ImmutableArraySequence.h
        ImmutableListSequence.h
        LinkedList.h
        ListDeque.h
        ListQueue.h
        ListSequence.h
        Queue.h
        Matrix.h
        Sequence.h)

set(SOURCES Matrix.cpp)

add_executable(Sequences main.cpp ${HEADERS} ${SOURCES})
add_executable(Test main_test.cpp test.cpp test.h ${HEADERS} ${SOURCES})
