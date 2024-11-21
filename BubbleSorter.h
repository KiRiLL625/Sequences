//
// Created by Admin on 21.11.2024.
//

#ifndef SEQUENCES_BUBBLESORTER_H
#define SEQUENCES_BUBBLESORTER_H

#include "ISorter.h"
#include <iostream>
#include <chrono>
#include <thread>

template<typename T>
class BubbleSorter : public ISorter<T> { //класс BubbleSorter, который реализует интерфейс ISorter
private:
    //функция, которая сортирует последовательность sequence с помощью пузырьковой сортировки
    void bubbleSort(Sequence<T>* sequence, std::function<bool(T, T)> comparator, bool printFlag) {
        for (int i = 0; i < sequence->getLength() - 1; i++) { //идем по массиву
            for (int j = 0; j < sequence->getLength() - i - 1; j++) { //идем по массиву (но не затрагиваем уже отсортированные элементы)
                if (comparator(sequence->get(j + 1), sequence->get(j))) { //если текущий элемент больше следующего (или меньше, в зависимости от компаратора)
                    std::swap(sequence->get(j), sequence->get(j + 1)); //меняем местами элементы
                    if (printFlag) { //если флаг печати включен
                        printSequence(sequence);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    }
                }
            }
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
        bubbleSort(sequence, comparator, printFlag); //вызываем функцию сортировки
        return sequence;
    }
};

#endif //SEQUENCES_BUBBLESORTER_H
