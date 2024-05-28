//
// Created by Admin on 28.05.2024.
//

#ifndef SEQUENCES_ARRAYDEQUE_H
#define SEQUENCES_ARRAYDEQUE_H

#include "Deque.h"
#include "ArraySequence.h"
#include <stdexcept>

//Класс ArrayDeque - класс деки, реализованной на основе динамического массива
template<class T>
class ArrayDeque: public Deque<T> {
private:
    ArraySequence<T> *arrayDeque; //Динамический массив, на основе которого реализована дека
public:
    ArrayDeque(){
        this->arrayDeque = new ArraySequence<T>(); //Создание пустого массива
    }

    ArrayDeque(T* items, int count){
        this->arrayDeque = new ArraySequence<T>(items, count); //Создание массива на основе переданных элементов
    }

    ArrayDeque(const ArrayDeque<T> &arrayDeque){
        this->arrayDeque = new ArraySequence<T>(*arrayDeque.arrayDeque); //Копирование массива
    }

    T front() const override {
        //Если дека пуста, то генерируется исключение
        if (this->arrayDeque->getLength() == 0) {
            throw std::out_of_range("Deque is empty");
        }
        //Иначе возвращается первый элемент
        return this->arrayDeque->getFirst();
    }

    T back() const override {
        //Если дека пуста, то генерируется исключение
        if (this->arrayDeque->getLength() == 0) {
            throw std::out_of_range("Deque is empty");
        }
        //Иначе возвращается последний элемент
        return this->arrayDeque->getLast();
    }

    void push_front(T value) override {
        this->arrayDeque->prepend(value); //Добавление элемента в начало массива
    }

    void push_back(T value) override {
        this->arrayDeque->append(value); //Добавление элемента в конец массива
    }

    void pop_front() override {
        //Если дека пуста, то генерируется исключение
        if (this->arrayDeque->getLength() == 0) {
            throw std::out_of_range("Deque is empty");
        }
        this->arrayDeque = this->arrayDeque->getSubsequence(1, this->arrayDeque->getLength() - 1); //Удаление первого элемента
    }

    void pop_back() override {
        //Если дека пуста, то генерируется исключение
        if (this->arrayDeque->getLength() == 0) {
            throw std::out_of_range("Deque is empty");
        }
        this->arrayDeque = this->arrayDeque->getSubsequence(0, this->arrayDeque->getLength() - 2); //Удаление последнего элемента
    }

    int getLength() const override {
        return this->arrayDeque->getLength(); //Получение длины массива
    }

    void print() const override{
        this->arrayDeque->print(); //Вывод массива
    }

    //Получение пододеки
    Deque<T>* getSubDeque(int startIndex, int endIndex) const override {
        //Если индексы некорректны, то генерируется исключение
        if (startIndex < 0 || startIndex >= this->arrayDeque->getLength() || endIndex < 0 || endIndex >= this->arrayDeque->getLength() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        T *items = new T[endIndex - startIndex + 1]; //Создание массива для пододеки
        for (int i = startIndex; i <= endIndex; i++) { //Копирование элементов из массива
            items[i - startIndex] = this->arrayDeque->get(i);
        }
        return new ArrayDeque<T>(items, endIndex - startIndex + 1); //Создание пододеки
    }

    //Слияние двух дек
    Deque<T>* concat(Deque<T> *deque) const override {
        auto* newDeque = new ArrayDeque<T>(*this); //Создание копии текущей деки
        for (int i = 0; i < deque->getLength(); i++) { //Добавление всех элементов из второй деки
            newDeque->push_back(deque->front());
            deque->pop_front();
        }
        return newDeque; //Возвращение новой деки
    }

    //Поиск пододеки
    int findSubDeque(Deque<T> *deque) const override {
        for (int i = 0; i < this->arrayDeque->getLength(); i++) { //Проход по всем элементам текущей деки
            if (this->arrayDeque->get(i) == deque->front()) { //Если первый элемент пододеки равен текущему элементу
                bool flag = true; //Флаг, который показывает, равны ли все элементы
                for (int j = 1; j < deque->getLength(); j++) { //Проход по всем элементам пододеки
                    if (this->arrayDeque->get(i + j) != deque->get(j)) { //Если элементы не равны
                        flag = false; //Флаг становится ложным
                        break; //Выход из цикла
                    }
                }
                if (flag) { //Если все элементы равны
                    return i; //Возвращение индекса
                }
            }
        }
        return -1; //Если пододека не найдена
    }

    //Функция, которая возвращает элемент по индексу
    T get(int index) const override {
        return this->arrayDeque->get(index);
    }

    //Функция, которая разделяет деку на две по предикату
    std::tuple<Deque<T>*, Deque<T>*> split(std::function<bool(T)> predicate) const override {
        auto* firstDeque = new ArrayDeque<T>(); //Создание двух пустых дек
        auto* secondDeque = new ArrayDeque<T>();
        for (int i = 0; i < this->arrayDeque->getLength(); i++) { //Проход по всем элементам текущей деки
            if (predicate(this->arrayDeque->get(i))) { //Если элемент удовлетворяет предикату
                firstDeque->push_back(this->arrayDeque->get(i)); //Добавление в первую деку
            } else {
                secondDeque->push_back(this->arrayDeque->get(i)); //Иначе добавление во вторую деку
            }
        }
        return std::make_tuple(firstDeque, secondDeque); //Возвращение двух дек
    }

    ArraySequence<T>* getArrayDeque() const {
        return this->arrayDeque;
    }

    ~ArrayDeque(){
        delete this->arrayDeque; //Удаление массива
    }
};

#endif //SEQUENCES_ARRAYDEQUE_H
