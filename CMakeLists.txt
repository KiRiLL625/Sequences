cmake_minimum_required(VERSION 3.25)
project(Sequences)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sequences
        Sequence.h
        ArraySequence.h
        ListSequence.h
        DynamicArray.h
        LinkedList.h
        test.h
        test.cpp
        main.cpp
        ImmutableArraySequence.h
        ImmutableListSequence.h
        #ArrayQueue.h
        #ListQueue.h
        #Queue.h
)
