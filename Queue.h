//
// Created by Admin on 16.05.2024.
//

#ifndef SEQUENCES_QUEUE_H
#define SEQUENCES_QUEUE_H

#include <functional>

//Класс Queue - абстрактный класс очереди (интерфейс)
template<class T>
class Queue{
public:
    virtual T front() const = 0; //Получение первого элемента в очереди
    virtual void push(T value) = 0; //Добавление элемента в конец очереди
    virtual void pop() = 0; //Удаление первого элемента в очереди
    virtual int getLength() const = 0; //Получение длины очереди
    virtual Queue<T>* getSubQueue(int startIndex, int endIndex) const = 0; //Получение подочереди
    virtual std::tuple<Queue<T>*, Queue<T>*> split(std::function<bool(T)> predicate) const = 0; //Разделение очереди на две по предикату
    virtual Queue<T>* concat(Queue<T>* queue) const = 0; //Сцепление двух очередей
    virtual int findSubQueue(Queue<T>* queue) const = 0; //Поиск подочереди
    virtual void print() const = 0; //Вывод очереди на экран
    virtual T get(int index) const = 0; //Получение элемента по индексу
    virtual LinkedList<T>* getLinkedList() const = 0; //Получение двусвязного списка
    virtual ~Queue() = default; //Деструктор
    //map - применение функции к каждому элементу очереди
    friend void map(std::function<T(T)> f, Queue<T>* queue){
        for (int i = 0; i < queue->getLength(); i++) {
            queue->push(f(queue->front())); //Добавление в очередь результата применения функции к первому элементу
            queue->pop(); //Удаление первого элемента
        }
    }

    //where - удаление элементов, не удовлетворяющих предикату
    friend void where(std::function<bool(T)> f, Queue<T>* queue){
        for (int i = 0; i < queue->getLength(); i++) {
            if (!f(queue->front())) { //Если элемент не удовлетворяет предикату
                queue->pop(); //Удаление элемента
            } else {
                queue->push(queue->front()); //Иначе добавление элемента в конец очереди
                queue->pop(); //Удаление элемента
            }
        }
    }

    //reduce - свертка очереди (свертка - последовательное применение функции к элементам)
    friend void reduce(std::function<T(T, T)> f, T c, Queue<T>* queue){
        T result = c; //Результат - начальное значение
        for (int i = 0; i < queue->getLength(); i++) {
            result = f(result, queue->front()); //Применение функции к результату и первому элементу
            queue->pop(); //Удаление первого элемента
        }
        queue->push(result); //Добавление результата в конец очереди
    }
};

#endif //SEQUENCES_QUEUE_H
