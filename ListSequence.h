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
    std::unique_ptr<LinkedList<T>> linkedList;
public:
    ListSequence(T* items, int count){
        this->linkedList = std::make_unique<LinkedList<T>>(items, count);
    }

    ListSequence(){
        this->linkedList = std::make_unique<LinkedList<T>>();
    }

    ListSequence(const ListSequence<T> &listSequence){
        this->linkedList = std::make_unique<LinkedList<T>>(*listSequence.linkedList);
    }

    T getFirst() const override {
        return this->linkedList->getFirst();
    }

    T getLast() const override {
        return this->linkedList->getLast();
    }

    T get(int index) const override {
        return this->linkedList->get(index);
    }

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

    int getLength() const override {
        return this->linkedList->getLength();
    }

    void append(T value) override {
        this->linkedList->append(value);
    }

    ListSequence<T> *append_immutable(T value) const override {
        auto *newList = new ListSequence<T>(*this);
        newList->linkedList->append(value);
        return newList;
    }

    void prepend(T value) override {
        this->linkedList->prepend(value);
    }

    ListSequence<T> *prepend_immutable(T value) const override {
        auto *newList = new ListSequence<T>(*this);
        newList->linkedList->prepend(value);
        return newList;
    }

    void insertAt(T value, int index) override {
        this->linkedList->insertAt(value, index);
    }

    ListSequence<T> *insertAt_immutable(T value, int index) const override {
        auto *newList = new ListSequence<T>(*this);
        newList->linkedList->insertAt(value, index);
        return newList;
    }

    void set(T value, int index) override {
        this->linkedList->set(index, value);
    }

    ListSequence<T> *concat(Sequence<T> *sequence) const override {
        auto *newList = new ListSequence<T>(*this);
        for (int i = 0; i < sequence->getLength(); i++) {
            newList->append(sequence->get(i));
        }
        return newList;
    }

    ListSequence<T> *set_immutable(T value, int index) const override {
        auto *newList = new ListSequence<T>(*this);
        newList->linkedList->set(index, value);
        return newList;
    }

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

    ~ListSequence() override = default;
};

#endif //SEQUENCES_LISTSEQUENCE_H
