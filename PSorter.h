//
// Created by Admin on 20.11.2024.
//

#ifndef SEQUENCES_PSORTER_H
#define SEQUENCES_PSORTER_H

#include "ISorter.h"

#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>

template<typename T>
class PSorter : public ISorter<T> {
private: //здесь находятся все вспомогательные функции для сортировки
    //функция, которая создает кучу (heap) из поддерева с корнем i
    //sequence - последовательность, n - длина последовательности, i - индекс, comparator - компаратор, printFlag - флаг печати
    void heapify(Sequence<T>* sequence, int n, int i, std::function<bool(T, T)> comparator, bool printFlag) {
        int largest = i; //индекс наибольшего элемента (по умолчанию - i)
        int left = 2 * i + 1; //левый потомок (left = 2*i + 1)
        int right = 2 * i + 2; //правый потомок (right = 2*i + 2)

        if (left < n && !comparator(sequence->get(left), sequence->get(largest))) //если левый потомок больше родителя
            largest = left; //то наибольший элемент - левый потомок

        if (right < n && !comparator(sequence->get(right), sequence->get(largest))) //если правый потомок больше родителя
            largest = right; //то наибольший элемент - правый потомок

        if (largest != i) { //если наибольший элемент не родитель
            std::swap(sequence->get(i), sequence->get(largest)); //меняем местами элементы
            if (printFlag) { //если флаг печати включен
                printSequence(sequence);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            heapify(sequence, n, largest, comparator, printFlag); //рекурсивно вызываем heapify для поддерева
        }
    }

    //функция, которая сортирует массив с помощью кучи
    void heapsort(Sequence<T>* sequence, int n, std::function<bool(T, T)> comparator, bool printFlag) {
        for (int i = n / 2 - 1; i >= 0; i--) //строим кучу (первый проход) (n/2-1 - последний элемент, у которого есть потомки)
            heapify(sequence, n, i, comparator, printFlag); //вызываем heapify для каждого элемента

        for (int i = n - 1; i > 0; i--) { //извлекаем элементы из кучи по одному
            std::swap(sequence->get(0), sequence->get(i)); //меняем местами первый и последний элементы
            if (printFlag) { //если флаг печати включен
                printSequence(sequence);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            heapify(sequence, i, 0, comparator, printFlag); //вызываем heapify для уменьшенной кучи
        }
    }

    void printSequence(Sequence<T>* sequence) { //функция, которая печатает массив
        std::cout << "\r[";
        for (int i = 0; i < sequence->getLength(); i++) {
            std::cout << sequence->get(i);
            if (i < sequence->getLength() - 1) {
                std::cout << " ";
            }
        }
        std::cout << "]";
        std::cout.flush();
    }

public:
    //основная функция сортировки (переопределение виртуальной функции из ISorter)
    Sequence<T>* sort(Sequence<T>* sequence, std::function<bool(T, T)> comparator, bool printFlag) override {
        heapsort(sequence, sequence->getLength(), comparator, printFlag); //вызываем функцию сортировки из private
        return sequence;
    }
};

#endif //SEQUENCES_PSORTER_H
