//
// Created by Admin on 28.05.2024.
//

#ifndef SEQUENCES_LISTDEQUE_H
#define SEQUENCES_LISTDEQUE_H

#include "Deque.h"
#include "ListSequence.h"
#include <stdexcept>

//Класс ListDeque - класс деки, реализованной на основе списка
template<class T>
class ListDeque: public Deque<T> {
private:
    ListSequence<T> *listDeque;
public:
    ListDeque(){
        this->listDeque = new ListSequence<T>();
    }

    ListDeque(T* items, int count){
        this->listDeque = new ListSequence<T>(items, count);
    }

    ListDeque(const ListDeque<T> &listDeque){
        this->listDeque = new ListSequence<T>(*listDeque.listDeque);
    }

    T front() const override {
        if (this->listDeque->getLength() == 0) {
            throw std::out_of_range("Deque is empty");
        }
        return this->listDeque->getFirst();
    }

    T back() const override {
        if (this->listDeque->getLength() == 0) {
            throw std::out_of_range("Deque is empty");
        }
        return this->listDeque->getLast();
    }

    void push_front(T value) override {
        this->listDeque->prepend(value);
    }

    void push_back(T value) override {
        this->listDeque->append(value);
    }

    void pop_front() override {
        if (this->listDeque->getLength() == 0) {
            throw std::out_of_range("Deque is empty");
        }
        this->listDeque = this->listDeque->getSubsequence(1, this->listDeque->getLength() - 1);
    }

    void pop_back() override {
        if (this->listDeque->getLength() == 0) {
            throw std::out_of_range("Deque is empty");
        }
        this->listDeque = this->listDeque->getSubsequence(0, this->listDeque->getLength() - 2);
    }

    int getLength() const override {
        return this->listDeque->getLength();
    }

    Deque<T>* getSubDeque(int startIndex, int endIndex) const override {
        if (startIndex < 0 || startIndex >= this->listDeque->getLength() || endIndex < 0 || endIndex >= this->listDeque->getLength() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        T *items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            items[i - startIndex] = this->listDeque->get(i);
        }
        return new ListDeque<T>(items, endIndex - startIndex + 1);
    }

    Deque<T>* concat(Deque<T>* listDeque) const override {
        T *items = new T[this->getLength() + listDeque->getLength()];
        for (int i = 0; i < this->getLength(); i++) {
            items[i] = this->get(i);
        }
        for (int i = 0; i < listDeque->getLength(); i++) {
            items[i + this->getLength()] = listDeque->get(i);
        }
        return new ListDeque<T>(items, this->getLength() + listDeque->getLength());
    }

    int findSubDeque(Deque<T>* deque) const override {
        for (int i = 0; i < this->getLength() - deque->getLength() + 1; i++) {
            bool flag = true;
            for (int j = 0; j < deque->getLength(); j++) {
                if (this->get(i + j) != deque->get(j)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }

    std::tuple<Deque<T>*, Deque<T>*> split(std::function<bool(T)> predicate) const override {
        auto* firstDeque = new ListDeque<T>();
        auto* secondDeque = new ListDeque<T>();
        for (int i = 0; i < this->getLength(); i++) {
            if (predicate(this->get(i))) {
                firstDeque->push_back(this->get(i));
            } else {
                secondDeque->push_back(this->get(i));
            }
        }
        return std::make_tuple(firstDeque, secondDeque);
    }

    T get(int index) const override {
        return this->listDeque->get(index);
    }

    void print() const override {
        this->listDeque->print();
    }

    ListSequence<T>* getListDeque() const {
        return this->listDeque;
    }

    ~ListDeque(){
        delete this->listDeque;
    }
};

#endif //SEQUENCES_LISTDEQUE_H
