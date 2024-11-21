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
    int capacity; //емкость массива
public:
    //Конструктор по умолчанию - создает пустой массив
    DynamicArray(){
        this->length = 0;
        this->capacity = 10;
        this->array = new T[this->capacity];
    }

    //Конструктор, который создает массив из массива items длины count
    DynamicArray(T* items, int count){
        this->length = count;
        this->capacity = count;
        this->array = new T[this->capacity];
        for (int i = 0; i < count; i++) {
            this->array[i] = items[i];
        }
    }

    //Конструктор копирования - создает копию массива
    DynamicArray(const DynamicArray<T> &dynamicArray){
        this->length = dynamicArray.length;
        this->capacity = dynamicArray.capacity;
        this->array = new T[this->capacity];
        for (int i = 0; i < this->length; i++) {
            this->array[i] = dynamicArray.array[i];
        }
    }

    //Функция, которая возвращает элемент массива по индексу index
    T& get(int index) const {
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        return this->array[index];
    }

    //Функция, которая возвращает длину массива
    int getLength() const {
        return this->length;
    }

    //Функция, которая добавляет элемент value в конец массива
    void append(T value){
        if (this->length == this->capacity) {
            this->resize();
        }
        this->array[this->length] = value;
        this->length++;
    }

    //Функция, которая добавляет элемент value в начало массива
    void prepend(T value){
        if (this->length == this->capacity) {
            this->resize();
        }
        for (int i = this->length; i > 0; i--) {
            this->array[i] = this->array[i - 1];
        }
        this->array[0] = value;
        this->length++;
    }

    //Функция, которая добавляет элемент value в массив по индексу index
    void insertAt(T value, int index){
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        if (this->length == this->capacity) {
            this->resize();
        }
        for (int i = this->length; i > index; i--) {
            this->array[i] = this->array[i - 1];
        }
        this->array[index] = value;
        this->length++;
    }

    //Функция, которая изменяет элемент массива по индексу index
    void set(int index, T value){
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        this->array[index] = value;
    }

    //Функция, которая меняет размер массива
    void resize(){
        this->capacity *= 2; //увеличиваем емкость в два раза
        T *newArray = new T[this->capacity]; //создаем новый массив
        for (int i = 0; i < this->length; i++) { //копируем элементы в новый массив
            newArray[i] = this->array[i];
        }
        delete[] this->array;
        this->array = newArray;
    }

    //Функция, которая очищает массив
    void clear(){
        this->length = 0;
        this->capacity = 10;
        delete[] this->array;
        this->array = new T[this->capacity];
    }

    ~DynamicArray(){
        delete[] this->array; //удаляем массив
    }
};

#endif //SEQUENCES_DYNAMICARRAY_H
