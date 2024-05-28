//
// Created by Admin on 28.05.2024.
//

#ifndef SEQUENCES_DEQUE_H
#define SEQUENCES_DEQUE_H

template<class T>
class Deque {
public:
    Deque() = default;
    virtual ~Deque() = default;
    virtual T front() const = 0; //Получение первого элемента в деке
    virtual T back() const = 0; //Получение последнего элемента в деке
    virtual void push_front(T value) = 0; //Добавление элемента в начало дека
    virtual void push_back(T value) = 0; //Добавление элемента в конец дека
    virtual void pop_front() = 0; //Удаление первого элемента в деке
    virtual void pop_back() = 0; //Удаление последнего элемента в деке
    virtual int getLength() const = 0; //Получение длины дека
    virtual Deque<T>* getSubDeque(int startIndex, int endIndex) const = 0; //Получение поддека
    virtual Deque<T>* concat(Deque<T>* deque) const = 0; //Сцепление двух деков
    virtual int findSubDeque(Deque<T>* deque) const = 0; //Поиск поддека
    virtual void print() const = 0; //Вывод дека на экран
    virtual T get(int index) const = 0; //Получение элемента по индексу
    virtual std::tuple<Deque<T>*, Deque<T>*> split(std::function<bool(T)> predicate) const = 0; //Разделение дека на два по предикату

    friend void map(std::function<T(T)> f, Deque<T>* deque){
        for (int i = 0; i < deque->getLength(); i++) {
            deque->push_back(f(deque->front())); //Добавление в дек результат применения функции к первому элементу
            deque->pop_front(); //Удаление первого элемента
        }
    }

    friend void where(std::function<bool(T)> f, Deque<T>* deque){
        for (int i = 0; i < deque->getLength(); i++) {
            if (!f(deque->front())) { //Если элемент не удовлетворяет предикату
                deque->pop_front(); //Удаление элемента
            } else {
                deque->push_back(deque->front()); //Иначе добавление элемента в конец дека
                deque->pop_front(); //Удаление элемента
            }
        }
    }

    friend void reduce(std::function<T(T, T)> f, T c, Deque<T>* deque){
        T result = c; //Результат - начальное значение
        for (int i = 0; i < deque->getLength(); i++) {
            result = f(result, deque->front()); //Применение функции к результату и первому элементу
            deque->pop_front(); //Удаление первого элемента
        }
        deque->push_back(result); //Добавление результата в конец дека
    }
};

#endif //SEQUENCES_DEQUE_H
