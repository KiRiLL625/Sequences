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
    virtual T getFirst() const = 0; //получить первый элемент последовательности

    virtual T getLast() const = 0; //получить последний элемент последовательности

    virtual T get(int index) const = 0; //получить элемент по индексу

    virtual T operator[](int index) const = 0; //перегрузка оператора [] (то же самое, что и get)

    virtual Sequence<T> *getSubsequence(int startIndex, int endIndex) const = 0; //получить подпоследовательность

    virtual int getLength() const = 0; //получить длину последовательности

    virtual void append(T value) = 0; //добавить элемент в конец последовательности

    virtual void prepend(T value) = 0; //добавить элемент в начало последовательности

    virtual void insertAt(T value, int index) = 0; //вставить элемент по индексу

    virtual void set(int index, T value) = 0; //установить значение элемента по индексу

    virtual Sequence<T> *concat(Sequence<T> *sequence) const = 0; //объединить две последовательности

    virtual ~Sequence() = default; //виртуальный деструктор

    //перегрузка оператора вывода в поток
    friend std::ostream &operator<<(std::ostream &out, const Sequence<T> &sequence) {
        //выводим все элементы последовательности в квадратных скобках через запятую
        out << "[";
        for (int i = 0; i < sequence.getLength(); i++) {
            out << sequence[i];
            if (i != sequence.getLength() - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};


#endif //SEQUENCES_SEQUENCE_H
