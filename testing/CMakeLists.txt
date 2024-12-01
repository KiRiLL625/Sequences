cmake_minimum_required(VERSION 3.25)
project(test)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

set(HEADERS
        ../ArraySequence.h
        ../DynamicArray.h
        ../LinkedList.h
        ../ListSequence.h
        ../Sequence.h
        ../ISorter.h
        ../QSorter.h
        ../PSorter.h
        ../BubbleSorter.h
        ../Car.h
        ../Pet.h)

add_executable(test test.cpp ${HEADERS})
target_link_libraries(test gtest gtest_main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include(GoogleTest)