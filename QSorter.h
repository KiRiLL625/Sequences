#ifndef SEQUENCES_QSORTER_H
#define SEQUENCES_QSORTER_H

#include "ISorter.h"

#include <iostream>
#include <algorithm> //подключаем библиотеку для использования std::swap
#include <chrono> //подключаем библиотеку для использования std::chrono (для работы с временем)
#include <thread> //подключаем библиотеку для использования std::this_thread (для работы с текущим потоком)

template<typename T>
class QSorter : public ISorter<T> {
private: //здесь находятся все вспомогательные функции для сортировки
    //функция, которая делит массив на две части (low - индекс первого элемента, high - индекс последнего элемента)
    void quicksort(Sequence<T>* sequence, int low, int high, std::function<bool(T, T)> comparator, bool printFlag) {
        if (low < high) { //если low < high, то массив еще не отсортирован
            int pi = partition(sequence, low, high, comparator, printFlag); //получаем индекс опорного элемента
            quicksort(sequence, low, pi - 1, comparator, printFlag); //рекурсивно сортируем элементы до опорного элемента
            quicksort(sequence, pi + 1, high, comparator, printFlag); //рекурсивно сортируем элементы после опорного элемента
        }
    }

    //функция, которая находит опорный элемент и разделяет массив на две части
    int partition(Sequence<T>* sequence, int low, int high, std::function<bool(T, T)> comparator, bool printFlag) {
        T pivot = sequence->get(high); //опорный элемент - последний элемент массива
        int i = (low - 1); //индекс меньшего элемента

        for (int j = low; j <= high - 1; j++) { //проходим по массиву
            if (comparator(sequence->get(j), pivot)) { //если текущий элемент меньше опорного (или больше, в зависимости от компаратора)
                i++; //увеличиваем индекс меньшего элемента
                std::swap(sequence->get(i), sequence->get(j)); //меняем местами элементы
                if (printFlag) { //если флаг печати включен
                    printSequence(sequence); //печатаем массив
                    std::this_thread::sleep_for(std::chrono::milliseconds(500)); //задержка вывода в 500 миллисекунд
                }
            }
        }
        std::swap(sequence->get(i + 1), sequence->get(high)); //меняем местами элементы (в конце цикла)
        if (printFlag) { //если флаг печати включен
            printSequence(sequence);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        return (i + 1); //возвращаем индекс опорного элемента (теперь он на своем месте)
    }

    void printSequence(Sequence<T>* sequence) { //функция, которая печатает массив
        std::cout << "\r["; //перемещаем курсор в начало строки и печатаем [
        for (int i = 0; i < sequence->getLength(); i++) { //проходим по массиву
            std::cout << sequence->get(i); //печатаем текущий элемент
            if (i < sequence->getLength() - 1) { //если элемент не последний
                std::cout << " "; //печатаем пробел
            }
        }
        std::cout << "]";
        std::cout.flush(); //очищаем буфер вывода
    }

public:
    //основная функция сортировки (переопределение виртуальной функции из ISorter)
    Sequence<T>* sort(Sequence<T>* sequence, std::function<bool(T, T)> comparator, bool printFlag) override {
        quicksort(sequence, 0, sequence->getLength() - 1, comparator, printFlag); //вызываем функцию сортировки из private
        return sequence; //возвращаем отсортированную последовательность
    }
};

#endif //SEQUENCES_QSORTER_H
