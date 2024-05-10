//
// Created by Admin on 28.04.2024.
//

#ifndef SEQUENCES_ARRAYSEQUENCE_H
#define SEQUENCES_ARRAYSEQUENCE_H

#include "Sequence.h"
#include <stdexcept>
#include "DynamicArray.h"
#include <memory>

//класс ArraySequence - класс, который реализует последовательность на основе обычного массива
//Наследует класс Sequence, то есть мы должны реализовать все методы, которые в нем объявлен
//Класс использует функции из класса DynamicArray для работы с массивом для скрытия реализации
template<class T>
class ArraySequence : public Sequence<T> {
protected:
    std::unique_ptr<DynamicArray<T>> arrayList; //список элементов последовательности
public:
    //Конструктор, который создает последовательность из массива
    ArraySequence(T* items, int count){
        //просто используем конструктор DynamicArray, чтобы создать массив из элементов
        this->arrayList = std::make_unique<DynamicArray<T>>(items, count);
    }

    //Конструктор по умолчанию - создает пустую последовательность
    ArraySequence(){
        //просто используем конструктор DynamicArray, чтобы создать пустой массив
        this->arrayList = std::make_unique<DynamicArray<T>>();
    }

    //Конструктор копирования - создает копию последовательности
    ArraySequence(const ArraySequence<T> &arraySequence){
        //просто используем конструктор DynamicArray, чтобы создать копию массива
        this->arrayList = std::make_unique<DynamicArray<T>>(*arraySequence.arrayList);
    }

    //Функция, которая возвращает первый элемент последовательности
    T getFirst() const override {
        return this->arrayList->get(0); //просто возвращаем первый элемент массива
    }

    //Функция, которая возвращает последний элемент последовательности
    T getLast() const override {
        return this->arrayList->get(this->arrayList->getLength() - 1);
    }

    //Функция, которая возвращает элемент последовательности по индексу index
    T get(int index) const override {
        return this->arrayList->get(index);
    }

    //Функция, которая возвращает подпоследовательность от startIndex до endIndex
    ArraySequence<T> *getSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || startIndex >= this->arrayList->getLength() || endIndex < 0 || endIndex >= this->arrayList->getLength() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        T *items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            items[i - startIndex] = this->arrayList->get(i);
        }
        return new ArraySequence<T>(items, endIndex - startIndex + 1);
    }

    //Функция, которая возвращает длину последовательности
    int getLength() const override {
        return this->arrayList->getLength();
    }

    //Функция, которая добавляет элемент в конец последовательности
    void append(T value) override {
        this->arrayList->append(value);
    }

    //Функция, которая добавляет элемент в конец последовательности (не изменяя текущую)
    ArraySequence<T>* append_immutable(T value) const override {
        //создаем новую последовательность, которая является копией текущей
        ArraySequence<T> *new_array = new ArraySequence<T>(*this);
        //добавляем элемент в конец новой последовательности
        new_array->append(value);
        //возвращаем новую последовательность
        return new_array;
    }

    //Функция, которая добавляет элемент в начало последовательности
    void prepend(T value) override {
        this->arrayList->prepend(value);
    }

    //Функция, которая добавляет элемент в начало последовательности (не изменяя текущую)
    ArraySequence<T>* prepend_immutable(T value) const override {
        //создаем новую последовательность, которая является копией текущей
        ArraySequence<T> *new_array = new ArraySequence<T>(*this);
        //добавляем элемент в начало новой последовательности
        new_array->prepend(value);
        //возвращаем новую последовательность
        return new_array;
    }

    //Функция, которая добавляет элемент в последовательность по индексу
    void insertAt(T value, int index) override {
        this->arrayList->insertAt(value, index);
    }

    //Функция, которая добавляет элемент в последовательность по индексу (не изменяя текущую)
    //работает по аналогии с предыдущими immutable-функциями
    ArraySequence<T>* insertAt_immutable(T value, int index) const override {
        ArraySequence<T> *new_array = new ArraySequence<T>(*this);
        new_array->insertAt(value, index);
        return new_array;
    }

    //Функция, которая изменяет элемент в последовательности по индексу
    void set(T value, int index) override {
        this->arrayList->set(index, value);
    }

    //Функция, которая изменяет элемент в последовательности по индексу (не изменяя текущую)
    ArraySequence<T>* set_immutable(T value, int index) const override {
        ArraySequence<T> *new_array = new ArraySequence<T>(*this);
        new_array->set(value, index);
        return new_array;
    }

    //Функция, которая объединяет две последовательности
    ArraySequence<T> *concat(Sequence<T> *sequence) const override {
        //создаем новую последовательность, которая является копией текущей
        ArraySequence<T> *new_array = new ArraySequence<T>(*this);
        //добавляем все элементы из второй последовательности в новую последовательность
        for (int i = 0; i < sequence->getLength(); i++) {
            new_array->append(sequence->get(i));
        }
        return new_array;
    }

    //Функция, которая выводит последовательность на экран
    void print() const override {
        std::cout << "[";
        for (int i = 0; i < this->arrayList->getLength(); i++) {
            std::cout << this->arrayList->get(i);
            if (i != this->arrayList->getLength() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    ~ArraySequence() override = default; //деструктор по умолчанию (default, так как здесь используется умный указатель
};

#endif //SEQUENCES_ARRAYSEQUENCE_H
