//
// Created by Admin on 16.05.2024.
//

#ifndef SEQUENCES_ARRAYQUEUE_H
#define SEQUENCES_ARRAYQUEUE_H

#include "ArraySequence.h"
#include "Queue.h"
#include <stdexcept>

//Класс ArrayQueue - класс очереди, реализованный на основе динамического массива
template<class T>
class ArrayQueue: public Queue<T> {
private:
    ArraySequence<T> *arrayQueue; //Динамический массив, на основе которого реализована очередь
public:
    ArrayQueue(){
        this->arrayQueue = new ArraySequence<T>(); //Создание пустого массива
    }

    ArrayQueue(T* items, int count){
        this->arrayQueue = new ArraySequence<T>(items, count); //Создание массива на основе переданных элементов
    }

    ArrayQueue(const ArrayQueue<T> &arrayQueue){
        this->arrayQueue = new ArraySequence<T>(*arrayQueue.arrayQueue); //Копирование массива
    }

    T front() const override {
        //Если очередь пуста, то генерируется исключение
        if (this->arrayQueue->getLength() == 0) {
            throw std::out_of_range("Queue is empty");
        }
        //Иначе возвращается первый элемент
        return this->arrayQueue->getFirst();
    }

    void push(T value) override {
        this->arrayQueue->append(value); //Добавление элемента в конец массива
    }

    void pop() override {
        //Если очередь пуста, то генерируется исключение
        if (this->arrayQueue->getLength() == 0) {
            throw std::out_of_range("Queue is empty");
        }
        this->arrayQueue = this->arrayQueue->getSubsequence(1, this->arrayQueue->getLength() - 1); //Удаление первого элемента
    }

    int getLength() const override {
        return this->arrayQueue->getLength(); //Получение длины массива
    }

    void print() const override{
        this->arrayQueue->print(); //Вывод массива
    }

    //Получение подочереди
    Queue<T>* getSubQueue(int startIndex, int endIndex) const override {
        //Если индексы некорректны, то генерируется исключение
        if (startIndex < 0 || startIndex >= this->arrayQueue->getLength() || endIndex < 0 || endIndex >= this->arrayQueue->getLength() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        T *items = new T[endIndex - startIndex + 1]; //Создание массива для подочереди
        for (int i = startIndex; i <= endIndex; i++) { //Копирование элементов из массива
            items[i - startIndex] = this->arrayQueue->get(i);
        }
        return new ArrayQueue<T>(items, endIndex - startIndex + 1); //Создание подочереди
    }

    //Разделение очереди на две по предикату
    std::tuple<Queue<T>*, Queue<T>*> split(std::function<bool(T)> predicate) const override {
        //Создание двух пустых очередей
        auto* firstQueue = new ArrayQueue<T>();
        auto* secondQueue = new ArrayQueue<T>();
        //Разделение массива на два
        for (int i = 0; i < this->arrayQueue->getLength(); i++) {
            if (predicate(this->arrayQueue->get(i))) { //если элемент удовлетворяет предикату, то добавление в первую очередь
                firstQueue->push(this->arrayQueue->get(i));
            } else { //иначе добавление во вторую очередь
                secondQueue->push(this->arrayQueue->get(i));
            }
        }
        //Возврат двух очередей
        return std::make_tuple(firstQueue, secondQueue);
    }

    //Сцепление двух очередей
    Queue<T>* concat(Queue<T>* arrayQueue) const override {
        //Создание новой очереди
        auto* newQueue = new ArrayQueue<T>(*this);
        //Добавление элементов из второй очереди
        for (int i = 0; i < arrayQueue->getLength(); i++) {
            newQueue->push(arrayQueue->get(i));
        }
        return newQueue; //Возврат новой очереди
    }

    //поиск на вхождение подочереди
    int findSubQueue(Queue<T>* subQueue) const override {
        //Если длина подочереди больше длины массива или длина подочереди равна 0, то возвращается -1
        if (subQueue->getLength() == 0 || subQueue->getLength() > this->arrayQueue->getLength()) {
            return -1;
        }
        //Поиск подочереди
        for (int i = 0; i < this->arrayQueue->getLength() - subQueue->getLength() + 1; i++) { //Проход по массиву
            bool isFound = true; //Флаг, показывающий, найдена ли подочередь
            for (int j = 0; j < subQueue->getLength(); j++) { //Проход по подочереди
                if (this->arrayQueue->get(i + j) != subQueue->get(j)) { //Если элементы не совпадают, то флаг становится false
                    isFound = false;
                    break;
                }
            }
            if (isFound) { //Если флаг true, то возвращается индекс, с которого начинается подочередь
                return i;
            }
        }
        return -1; //Иначе возвращается -1
    }

    T get(int index) const override {
        return this->arrayQueue->get(index); //Получение элемента по индексу
    }

    DynamicArray<T>* getArray() const {
        return this->arrayQueue->getArray(); //Получение массива
    }

    ~ArrayQueue() override {
        delete this->arrayQueue; //Удаление массива
    }
};

#endif //SEQUENCES_ARRAYQUEUE_H
