//
// Created by Admin on 28.04.2024.
//

#ifndef SEQUENCES_ARRAYSEQUENCE_H
#define SEQUENCES_ARRAYSEQUENCE_H

#include "Sequence.h"
#include <ostream>
#include <stdexcept>

//класс ArraySequence - класс, который реализует последовательность на основе обычного массива
//Наследует класс Sequence, то есть мы должны реализовать все методы, которые в нем объявлены
template<class T>
class ArraySequence : public Sequence<T> {
private:
    T *array; //массив элементов
    int length; //длина массива
public:
    //Конструктор по умолчанию - создает пустой массив
    ArraySequence() {
        this->length = 0;
        this->array = new T[0];
    }

    //Конструктор, который принимает массив элементов и их количество и
    //последовательность ArraySequence создается на основе этого массива
    ArraySequence(T *items, int count) {
        this->length = count;
        this->array = new T[count];
        for (int i = 0; i < count; i++) {
            this->array[i] = items[i];
        }
    }

    //Конструктор копирования - создает копию последовательности ArraySequence
    //При этом старый объект не изменяется
    ArraySequence(const ArraySequence<T> &arraySequence) {
        this->length = arraySequence.length;
        this->array = new T[arraySequence.length];
        for (int i = 0; i < arraySequence.length; i++) {
            this->array[i] = arraySequence.array[i];
        }
    }

    //Методы, которые мы должны реализовать из класса Sequence
    T getFirst() const override { //получить первый элемент последовательности
        return this->array[0];
    }

    T getLast() const override { //получить последний элемент последовательности
        return this->array[this->length - 1];
    }

    T get(int index) const override { //получить элемент по индексу
        return this->array[index];
    }

    T operator[](int index) const override { //перегрузка оператора [] (то же самое, что и get)
        return this->array[index];
    }

    //Получить подпоследовательность
    ArraySequence<T> *getSubsequence(int startIndex, int endIndex) const override {
        //Если индексы выходят за границы массива, то бросаем исключение (по условию задачи)
        if (startIndex < 0 || startIndex >= this->length || endIndex < 0 || endIndex >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        if (startIndex > endIndex) {
            throw std::invalid_argument("Start index is greater than end index");
        }
        //Создаем новый массив, в который будем копировать элементы (auto - автоматический тип данных)
        //нужен для того, чтобы не писать длинное название типа данных (в данном случае не длинное, но все равно)
        auto *subArray = new T[endIndex - startIndex + 1];
        //Копируем элементы из старого массива в новый
        for (int i = startIndex; i <= endIndex; i++) {
            subArray[i - startIndex] = this->array[i];
        }
        //Создаем новую последовательность на основе нового массива и возвращаем ее
        return new ArraySequence(subArray, endIndex - startIndex + 1);
    }

    //Получить длину последовательности
    int getLength() const override {
        return this->length;
    }

    //Добавить элемент в конец последовательности
    void append(T value) override {
        //Создаем новый массив, который на 1 больше старого
        T *newArray = new T[this->length + 1];
        //Копируем все элементы из старого массива в новый
        for (int i = 0; i < this->length; i++) {
            newArray[i] = this->array[i];
        }
        //Добавляем новый элемент в конец нового массива
        newArray[this->length] = value;
        //Удаляем старый массив и присваиваем новый
        delete[] this->array;
        this->array = newArray;
        //Увеличиваем длину на 1
        this->length++;
    }

    //Добавить элемент в начало последовательности
    void prepend(T value) override {
        //Создаем новый массив, который на 1 больше старого
        T *newArray = new T[this->length + 1];
        //Добавляем новый элемент в начало нового массива
        newArray[0] = value;
        //Копируем все элементы из старого массива в новый
        for (int i = 0; i < this->length; i++) {
            newArray[i + 1] = this->array[i];
        }
        //Удаляем старый массив и присваиваем новый
        delete[] this->array;
        this->array = newArray;
        //Увеличиваем длину на 1
        this->length++;
    }

    //Вставить элемент по индексу
    void insertAt(T value, int index) override {
        //Если индекс выходит за границы массива, то бросаем исключение (по условию задачи)
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        //Создаем новый массив, который на 1 больше старого (тут тоже можно писать auto)
        T *newArray = new T[this->length + 1];
        //Копируем все элементы до индекса из старого массива в новый
        for (int i = 0; i < index; i++) {
            newArray[i] = this->array[i];
        }
        //Добавляем новый элемент в новый массив
        newArray[index] = value;
        //Копируем все элементы после индекса из старого массива в новый
        for (int i = index; i < this->length; i++) {
            newArray[i + 1] = this->array[i];
        }
        //Удаляем старый массив и присваиваем новый
        delete[] this->array;
        this->array = newArray;
        //Увеличиваем длину на 1
        this->length++;
    }

    //Установить значение элемента по индексу
    void set(int index, T value) override {
        //Если индекс выходит за границы массива, то бросаем исключение (по условию задачи)
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        //Устанавливаем значение элемента по индексу
        this->array[index] = value;
    }

    //Объединить две последовательности
    ArraySequence<T> *concat(Sequence<T> *sequence) const override {
        //Если sequence не является ArraySequence, то бросаем исключение
        auto *arraySequence = dynamic_cast<ArraySequence<T> *>(sequence);
        if (arraySequence == nullptr) {
            throw std::invalid_argument("Sequence is not ArraySequence");
        }
        //Создаем новый массив, который на сумму длин двух массивов
        auto *newArray = new T[this->length + arraySequence->length];
        //Копируем все элементы из первого массива в новый
        for (int i = 0; i < this->length; i++) {
            newArray[i] = this->array[i];
        }
        //Копируем все элементы из второго массива в новый
        for (int i = 0; i < arraySequence->length; i++) {
            newArray[this->length + i] = arraySequence->array[i];
        }
        //Создаем новую последовательность на основе нового массива и возвращаем ее
        return new ArraySequence(newArray, this->length + arraySequence->length);
    }

    //Деструктор - удаляет массив
    ~ArraySequence() override {
        delete[] this->array;
    }
};

#endif //SEQUENCES_ARRAYSEQUENCE_H
