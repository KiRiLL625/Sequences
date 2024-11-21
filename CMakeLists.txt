cmake_minimum_required(VERSION 3.25)
project(Sequences)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS
        ArraySequence.h
        DynamicArray.h
        LinkedList.h
        ListSequence.h
        Sequence.h
        ISorter.h
        QSorter.h
        PSorter.h
        BubbleSorter.h)

set(SOURCES main.cpp)

add_subdirectory(testing)
add_subdirectory(googletest)

add_executable(Sequences ${HEADERS} ${SOURCES})
#add_executable(Test main_test.cpp test.cpp test.h ${HEADERS} ${SOURCES})
