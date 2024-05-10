//
// Created by Admin on 28.04.2024.
//

#ifndef SEQUENCES_LISTSEQUENCE_H
#define SEQUENCES_LISTSEQUENCE_H

#include "Sequence.h"
#include <memory>
#include <stdexcept>
#include <ostream>
#include "LinkedList.h"

//класс ListSequence - класс, который реализует последовательность на основе двусвязного списка
template<class T>
class ListSequence : public Sequence<T> {
private:
    std::unique_ptr<LinkedList<T>> linkedList; //список элементов последовательности (точнее указатель)
public:
    //Конструктор, который создает последовательность из массива
    ListSequence(T* items, int count){
        this->linkedList = std::make_unique<LinkedList<T>>(items, count);
    }

    //Конструктор по умолчанию - создает пустую последовательность (использует конструктор LinkedList)
    ListSequence(){
        this->linkedList = std::make_unique<LinkedList<T>>();
    }

    //Конструктор копирования - создает копию последовательности (использует конструктор LinkedList)
    ListSequence(const ListSequence<T> &listSequence){
        this->linkedList = std::make_unique<LinkedList<T>>(*listSequence.linkedList);
    }

    //Функция, которая возвращает первый элемент последовательности
    T getFirst() const override {
        return this->linkedList->getFirst();
    }

    //Функция, которая возвращает последний элемент последовательности
    T getLast() const override {
        return this->linkedList->getLast();
    }

    //Функция, которая возвращает элемент последовательности по индексу index
    T get(int index) const override {
        return this->linkedList->get(index);
    }

    //Функция, которая возвращает подпоследовательность от startIndex до endIndex
    ListSequence<T> *getSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || startIndex >= this->linkedList->getLength() || endIndex < 0 || endIndex >= this->linkedList->getLength() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        T *items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            items[i - startIndex] = this->linkedList->get(i);
        }
        return new ListSequence<T>(items, endIndex - startIndex + 1);
    }

    //Функция, которая возвращает длину последовательности
    int getLength() const override {
        return this->linkedList->getLength();
    }

    //Функция, которая добавляет элемент в конец последовательности
    void append(T value) override {
        this->linkedList->append(value);
    }

    //Функция, которая добавляет элемент в конец последовательности (не изменяя текущую)
    ListSequence<T> *append_immutable(T value) const override {
        //создаем новый список на основе текущего
        auto *newList = new ListSequence<T>(*this);
        //добавляем элемент в конец нового списка
        newList->linkedList->append(value);
        //возвращаем новый список
        return newList;
    }

    //Функция, которая добавляет элемент в начало последовательности
    void prepend(T value) override {
        this->linkedList->prepend(value);
    }

    //Функция, которая добавляет элемент в начало последовательности (не изменяя текущую)
    ListSequence<T> *prepend_immutable(T value) const override {
        auto *newList = new ListSequence<T>(*this);
        newList->linkedList->prepend(value);
        return newList;
    }

    //Функция, которая добавляет элемент в последовательность по индексу index
    void insertAt(T value, int index) override {
        this->linkedList->insertAt(value, index);
    }

    //Функция, которая добавляет элемент в последовательность по индексу index (не изменяя текущую)
    ListSequence<T> *insertAt_immutable(T value, int index) const override {
        auto *newList = new ListSequence<T>(*this);
        newList->linkedList->insertAt(value, index);
        return newList;
    }

    //Функция, которая изменяет элемент в последовательности по индексу
    void set(T value, int index) override {
        this->linkedList->set(index, value);
    }

    //Функция, которая объединяет две последовательности
    ListSequence<T> *concat(Sequence<T> *sequence) const override {
        auto *newList = new ListSequence<T>(*this);
        for (int i = 0; i < sequence->getLength(); i++) {
            newList->append(sequence->get(i));
        }
        return newList;
    }

    //Функция, которая изменяет элемент в последовательности по индексу (не изменяя текущую)
    ListSequence<T> *set_immutable(T value, int index) const override {
        auto *newList = new ListSequence<T>(*this);
        newList->linkedList->set(index, value);
        return newList;
    }

    //Функция, которая выводит последовательность на экран
    void print() const override {
        std::cout << "[";
        for (int i = 0; i < this->linkedList->getLength(); i++) {
            std::cout << this->linkedList->get(i);
            if (i != this->linkedList->getLength() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    ~ListSequence() override = default; //деструктор по умолчанию (default, так как используем умные указатели)
};

#endif //SEQUENCES_LISTSEQUENCE_H
