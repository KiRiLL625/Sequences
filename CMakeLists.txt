cmake_minimum_required(VERSION 3.25)
project(Sequences)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sequences main.cpp
        Sequence.h
        ArraySequence.h
        ListSequence.h
        Animal.cpp
        Animal.h
        DynamicArray.h
        LinkedList.h
)
