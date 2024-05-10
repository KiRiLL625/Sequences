//
// Created by Admin on 09.05.2024.
//

#ifndef SEQUENCES_DYNAMICARRAY_H
#define SEQUENCES_DYNAMICARRAY_H

#include <stdexcept>

//класс DynamicArray - класс, который реализует динамический массив
template<class T>
class DynamicArray{
private:
    T *array; //массив элементов
    int length; //длина массива
public:
    //Конструктор по умолчанию - создает пустой массив
    DynamicArray(){
        this->length = 0;
        this->array = new T[0];
    }

    //Конструктор, который создает массив из другого массива
    DynamicArray(T* items, int count){
        this->length = count;
        this->array = new T[count];
        for (int i = 0; i < count; i++) {
            this->array[i] = items[i];
        }
    }

    //Конструктор, который создает массив заданной длины
    explicit DynamicArray(int size){
        this->length = size;
        this->array = new T[size];
    }

    //Конструктор копирования - создает копию массива
    DynamicArray(const DynamicArray<T> &arrayList){
        this->length = arrayList.length;
        this->array = new T[arrayList.length];
        for (int i = 0; i < arrayList.length; i++) {
            this->array[i] = arrayList.array[i];
        }
    }

    //Деструктор - удаляет массив
    ~DynamicArray(){
        delete[] this->array;
    }

    //Функция, которая возвращает элемент массива по индексу
    T get(int index) const {
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        return this->array[index];
    }

    //Функция, которая возвращает длину массива
    int getLength() const {
        return this->length;
    }

    //Функция, которая изменяет элемент массива по индексу
    void set(int index, T value) {
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        this->array[index] = value;
    }

    //Функция, которая меняет размер массива
    void resize(int newSize) {
        T *newArray = new T[newSize];
        for (int i = 0; i < this->length; i++) {
            newArray[i] = this->array[i];
        }
        delete[] this->array;
        this->array = newArray;
        this->length = newSize;
    }

    //Функция, которая добавляет элемент в конец массива
    void append(T value) {
        this->resize(this->length + 1);
        this->array[this->length - 1] = value;
    }

    //Функция, которая добавляет элемент в начало массива
    void prepend(T value) {
        this->resize(this->length + 1);
        for (int i = this->length - 1; i > 0; i--) {
            this->array[i] = this->array[i - 1];
        }
        this->array[0] = value;
    }

    //Функция, которая добавляет элемент в массив по индексу
    void insertAt(T value, int index) {
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        this->resize(this->length + 1);
        for (int i = this->length - 1; i > index; i--) {
            this->array[i] = this->array[i - 1];
        }
        this->array[index] = value;
    }
};

#endif //SEQUENCES_DYNAMICARRAY_H
