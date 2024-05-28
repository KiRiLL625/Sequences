//
// Created by Admin on 16.05.2024.
//

#ifndef SEQUENCES_LISTQUEUE_H
#define SEQUENCES_LISTQUEUE_H

#include "ListSequence.h"
#include "Queue.h"
#include <stdexcept>

//Класс ListQueue - класс очереди, реализованный на основе списка
//Все функции аналогичны функциям класса ArrayQueue
template<class T>
class ListQueue: public Queue<T> {
private:
    ListSequence<T> *listQueue;
public:
    ListQueue(){
        this->listQueue = new ListSequence<T>();
    }

    ListQueue(T* items, int count){
        this->listQueue = new ListSequence<T>(items, count);
    }

    ListQueue(const ListQueue<T> &listQueue){
        this->listQueue = new ListSequence<T>(*listQueue.listQueue);
    }

    T front() const override {
        if (this->listQueue->getLength() == 0) {
            throw std::out_of_range("Queue is empty");
        }
        return this->listQueue->getFirst();
    }

    void push(T value) override {
        this->listQueue->append(value);
    }

    void pop() override {
        if (this->listQueue->getLength() == 0) {
            throw std::out_of_range("Queue is empty");
        }
        this->listQueue = this->listQueue->getSubsequence(1, this->listQueue->getLength() - 1);
    }

    int getLength() const override {
        return this->listQueue->getLength();
    }

    Queue<T>* getSubQueue(int startIndex, int endIndex) const override {
        if (startIndex < 0 || startIndex >= this->listQueue->getLength() || endIndex < 0 || endIndex >= this->listQueue->getLength() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        T *items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            items[i - startIndex] = this->listQueue->get(i);
        }
        return new ListQueue<T>(items, endIndex - startIndex + 1);
    }

    std::tuple<Queue<T>*, Queue<T>*> split(std::function<bool(T)> predicate) const override {
        auto* firstQueue = new ListQueue<T>();
        auto* secondQueue = new ListQueue<T>();
        for (int i = 0; i < this->listQueue->getLength(); i++) {
            if (predicate(this->listQueue->get(i))) {
                firstQueue->push(this->listQueue->get(i));
            } else {
                secondQueue->push(this->listQueue->get(i));
            }
        }
        return std::make_tuple(firstQueue, secondQueue);
    }

    Queue<T>* concat(Queue<T>* listQueue) const override {
        auto* newQueue = new ListQueue<T>(*this);
        for (int i = 0; i < listQueue->getLength(); i++) {
            newQueue->push(listQueue->get(i));
        }
        return newQueue;
    }

    int findSubQueue(Queue<T>* subQueue) const override {
        if (subQueue->getLength() == 0 || subQueue->getLength() > this->listQueue->getLength()) {
            return -1;
        }
        for (int i = 0; i < this->listQueue->getLength() - subQueue->getLength() + 1; i++) {
            bool isFound = true;
            for (int j = 0; j < subQueue->getLength(); j++) {
                if (this->listQueue->get(i + j) != subQueue->get(j)) {
                    isFound = false;
                    break;
                }
            }
            if (isFound) {
                return i;
            }
        }
        return -1;
    }

    void print() const override{
        this->listQueue->print();
    }

    T get(int index) const override {
        return this->listQueue->get(index);
    }

    LinkedList<T>* getLinkedList() const {
        return this->listQueue->getLinkedList();
    }

    ~ListQueue() override {
        delete this->listQueue;
    }

};


#endif //SEQUENCES_LISTQUEUE_H
