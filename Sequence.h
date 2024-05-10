//
// Created by Admin on 28.04.2024.
//

#ifndef SEQUENCES_SEQUENCE_H
#define SEQUENCES_SEQUENCE_H

//чисто виртуальный класс (абстрактный класс) - класс, который содержит хотя бы одну чисто виртуальную функцию
//Он нужен нам для того, чтобы создать интерфейс, который будут реализовывать другие классы
//Простыми словами он просто показывает, какие функции нужно реализовать в классе, который будет наследоваться от него
//T - любой тип данных, будь то числа, строки и т.д.
template<class T>
class Sequence {
public:
    Sequence() = default; //конструктор по умолчанию

    virtual ~Sequence() = default; //деструктор по умолчанию

    //чисто виртуальная функция - функция, которая не имеет реализации в этом классе
    virtual T getFirst() const = 0; //функция, которая возвращает первый элемент последовательности

    virtual T getLast() const = 0; //функция, которая возвращает последний элемент последовательности

    virtual T get(int index) const = 0; //функция, которая возвращает элемент последовательности по индексу

    virtual int getLength() const = 0; //функция, которая возвращает длину последовательности

    virtual Sequence<T> *getSubsequence(int startIndex, int endIndex) const = 0; //функция, которая возвращает подпоследовательность

    virtual void append(T value) = 0; //функция, которая добавляет элемент в конец последовательности

    virtual Sequence<T>* append_immutable(T value) const = 0; //функция, которая добавляет элемент в конец последовательности (не изменяя текущую)

    virtual void prepend(T value) = 0; //функция, которая добавляет элемент в начало последовательности

    virtual Sequence<T>* prepend_immutable(T value) const = 0; //функция, которая добавляет элемент в начало последовательности (не изменяя текущую)

    virtual void insertAt(T value, int index) = 0; //функция, которая добавляет элемент в последовательность по индексу

    virtual Sequence<T>* insertAt_immutable(T value, int index) const = 0; //функция, которая добавляет элемент в последовательность по индексу (не изменяя текущую)

    virtual void set(T value, int index) = 0; //функция, которая изменяет элемент в последовательности по индексу

    virtual Sequence<T>* set_immutable(T value, int index) const = 0; //функция, которая изменяет элемент в последовательности по индексу (не изменяя текущую)

    virtual Sequence<T> *concat(Sequence<T> *sequence) const = 0; //функция, которая объединяет две последовательности

    virtual void print() const = 0; //функция, которая выводит последовательность на экран
};


#endif //SEQUENCES_SEQUENCE_H
