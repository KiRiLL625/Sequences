//
// Created by Admin on 16.05.2024.
//

#ifndef SEQUENCES_IMMUTABLEARRAYSEQUENCE_H
#define SEQUENCES_IMMUTABLEARRAYSEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"
#include <iostream>

// ImmutableArraySequence class - класс неизменяемой последовательности, реализованный на основе динамического массива
template<class T>
class ImmutableArraySequence: public Sequence<T> {
private:
    DynamicArray<T> *arrayList_immutable; // Динамический массив элементов последовательности
public:
    // Конструкторы класса ImmutableArraySequence (аналогично ArraySequence)
    ImmutableArraySequence(T* items, int count){
        this->arrayList_immutable = new DynamicArray<T>(items, count);
    }

    ImmutableArraySequence(){
        this->arrayList_immutable = new DynamicArray<T>();
    }

    ImmutableArraySequence(const ImmutableArraySequence<T> &immutableArraySequence){
        this->arrayList_immutable = new DynamicArray<T>(*immutableArraySequence.arrayList_immutable);
    }

    T getFirst() const override {
        return this->arrayList_immutable->get(0);
    }

    T getLast() const override {
        return this->arrayList_immutable->get(this->arrayList_immutable->getLength() - 1);
    }

    T get(int index) const override {
        return this->arrayList_immutable->get(index);
    }

    // Методы класса ImmutableArraySequence (аналогично ArraySequence)
    // Метод getSubsequence - получение подпоследовательности из последовательности
    ImmutableArraySequence<T> *getSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || startIndex >= this->arrayList_immutable->getLength() || endIndex < 0 || endIndex >= this->arrayList_immutable->getLength() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        T *items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            items[i - startIndex] = this->arrayList_immutable->get(i);
        }
        return new ImmutableArraySequence<T>(items, endIndex - startIndex + 1);
    }

    //Функция getLength - получение длины последовательности
    int getLength() const override {
        return this->arrayList_immutable->getLength();
    }

    //Append - добавление элемента в конец последовательности
    //Но он не изменяет текущий объект, а возвращает новый объект с добавленным элементом
    ImmutableArraySequence<T>* append(T value) override {
        ImmutableArraySequence<T>* newImmutableArraySequence = new ImmutableArraySequence<T>(*this);
        newImmutableArraySequence->arrayList_immutable->append(value);
        return newImmutableArraySequence;
    }

    //Prepend - добавление элемента в начало последовательности (аналогично append)
    ImmutableArraySequence<T>* prepend(T value) override {
        ImmutableArraySequence<T>* newImmutableArraySequence = new ImmutableArraySequence<T>(*this);
        newImmutableArraySequence->arrayList_immutable->prepend(value);
        return newImmutableArraySequence;
    }

    //InsertAt - вставка элемента в последовательность по индексу (аналогично append)
    ImmutableArraySequence<T>* insertAt(T value, int index) override {
        if (index < 0 || index >= this->arrayList_immutable->getLength()) {
            throw std::out_of_range("Index out of range");
        }
        ImmutableArraySequence<T>* newImmutableArraySequence = new ImmutableArraySequence<T>(*this);
        newImmutableArraySequence->arrayList_immutable->insertAt(value, index);
        return newImmutableArraySequence;
    }

    //Set - установка значения элемента по индексу (аналогично append)
    ImmutableArraySequence<T>* set(T value, int index) override {
        if (index < 0 || index >= this->arrayList_immutable->getLength()) {
            throw std::out_of_range("Index out of range");
        }
        ImmutableArraySequence<T>* newImmutableArraySequence = new ImmutableArraySequence<T>(*this);
        newImmutableArraySequence->arrayList_immutable->set(index, value);
        return newImmutableArraySequence;
    }

    //Concat - конкатенация двух последовательностей
    ImmutableArraySequence<T>* concat(Sequence<T> *sequence) const override {
        ImmutableArraySequence<T>* newImmutableArraySequence = new ImmutableArraySequence<T>(*this);
        for (int i = 0; i < sequence->getLength(); i++) {
            newImmutableArraySequence->arrayList_immutable->append(sequence->get(i));
        }
        return newImmutableArraySequence;
    }

    //Print - вывод последовательности на экран
    void print() const override{
        std::cout << "[";
        for (int i = 0; i < this->arrayList_immutable->getLength(); i++) {
            std::cout << this->arrayList_immutable->get(i);
            if (i != this->arrayList_immutable->getLength() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    //getArray - получение динамического массива элементов последовательности
    DynamicArray<T>* getArray() const {
        return this->arrayList_immutable;
    }

    //Оператор [] - получение элемента последовательности по индексу
    T operator[](int index) const override {
        return this->arrayList_immutable->get(index);
    }

    //Деструктор класса ImmutableArraySequence
    ~ImmutableArraySequence(){
        delete this->arrayList_immutable;
    }
};

#endif //SEQUENCES_IMMUTABLEARRAYSEQUENCE_H
