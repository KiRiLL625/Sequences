//
// Created by Admin on 16.05.2024.
//

#ifndef SEQUENCES_IMMUTABLELISTSEQUENCE_H
#define SEQUENCES_IMMUTABLELISTSEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"
#include <iostream>

//Класс ImmutableListSequence - класс неизменяемой последовательности, реализованный на основе связного списка
template<class T>
class ImmutableListSequence: public Sequence<T> {
private:
    LinkedList<T> *linkedList_immutable; //Связный список, на основе которого реализована последовательность
public:
    //Конструкторы (аналогично ListSequence)
    ImmutableListSequence(T* items, int count){
        this->linkedList_immutable = new LinkedList<T>(items, count);
    }

    ImmutableListSequence(){
        this->linkedList_immutable = new LinkedList<T>();
    }

    ImmutableListSequence(const ImmutableListSequence<T> &immutableListSequence){
        this->linkedList_immutable = new LinkedList<T>(*immutableListSequence.linkedList_immutable);
    }

    T getFirst() const override {
        return this->linkedList_immutable->getFirst();
    }

    T getLast() const override {
        return this->linkedList_immutable->getLast();
    }

    T get(int index) const override {
        return this->linkedList_immutable->get(index);
    }

    //Остальные функции аналогичны функциям класса ImmutableArraySequence
    ImmutableListSequence<T> *getSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || startIndex >= this->linkedList_immutable->getLength() || endIndex < 0 || endIndex >= this->linkedList_immutable->getLength() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        T *items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            items[i - startIndex] = this->linkedList_immutable->get(i);
        }
        return new ImmutableListSequence<T>(items, endIndex - startIndex + 1);
    }

    int getLength() const override {
        return this->linkedList_immutable->getLength();
    }

    ImmutableListSequence<T>* append(T value) override {
        ImmutableListSequence<T>* newImmutableListSequence = new ImmutableListSequence<T>(*this);
        newImmutableListSequence->linkedList_immutable->append(value);
        return newImmutableListSequence;
    }

    ImmutableListSequence<T>* prepend(T value) override {
        ImmutableListSequence<T>* newImmutableListSequence = new ImmutableListSequence<T>(*this);
        newImmutableListSequence->linkedList_immutable->prepend(value);
        return newImmutableListSequence;
    }

    ImmutableListSequence<T>* insertAt(T value, int index) override {
        ImmutableListSequence<T>* newImmutableListSequence = new ImmutableListSequence<T>(*this);
        newImmutableListSequence->linkedList_immutable->insertAt(value, index);
        return newImmutableListSequence;
    }

    ImmutableListSequence<T>* set(T value, int index) override {
        ImmutableListSequence<T>* newImmutableListSequence = new ImmutableListSequence<T>(*this);
        newImmutableListSequence->linkedList_immutable->set(value, index);
        return newImmutableListSequence;
    }

    ImmutableListSequence<T>* concat(Sequence<T>* list) const override {
        ImmutableListSequence<T>* newImmutableListSequence = new ImmutableListSequence<T>(*this);
        for (int i = 0; i < list->getLength(); i++) {
            newImmutableListSequence->linkedList_immutable->append(list->get(i));
        }
        return newImmutableListSequence;
    }

    ~ImmutableListSequence(){
        delete this->linkedList_immutable;
    }

    void print() const override {
        std::cout << "[";
        for (int i = 0; i < this->linkedList_immutable->getLength(); i++) {
            std::cout << this->linkedList_immutable->get(i);
            if (i != this->linkedList_immutable->getLength() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }

    LinkedList<T>* getLinkedList() const {
        return this->linkedList_immutable;
    }

    T operator[](int index) const override {
        return this->linkedList_immutable->get(index);
    }
};

#endif //SEQUENCES_IMMUTABLELISTSEQUENCE_H
