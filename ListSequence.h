//
// Created by Admin on 28.04.2024.
//

#ifndef SEQUENCES_LISTSEQUENCE_H
#define SEQUENCES_LISTSEQUENCE_H

#include "Sequence.h"
#include <memory>
#include <stdexcept>
#include <ostream>

//класс ListSequence - класс, который реализует последовательность на основе двусвязного списка
template<class T>
class ListSequence : public Sequence<T> {
private:
    //Структура Node - узел списка (1 элемент списка)
    struct Node {
        T value; //значение элемента
        std::shared_ptr<Node> next; //указатель на следующий элемент (shared_ptr используется для автоматического удаления памяти)
        std::shared_ptr<Node> prev; //указатель на предыдущий элемент

        explicit Node(T value) : value(value), next(nullptr), prev(nullptr) {} //конструктор узла (по умолчанию всё по нулям)
    };

    std::shared_ptr<Node> head; //указатель на начало списка
    std::shared_ptr<Node> tail; //указатель на конец списка
    int length; //длина списка

public:
    //Конструктор по умолчанию - создает пустой список
    ListSequence() {
        this->length = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    //Конструктор, который принимает массив элементов и их количество и создает последовательность ListSequence на основе этого массива
    ListSequence(T *items, int count) {
        this->length = count;
        this->head = nullptr;
        this->tail = nullptr;
        //добавляем все элементы массива в список
        for (int i = 0; i < count; i++) {
            this->append(items[i]);
        }
    }

    //Конструктор копирования - создает копию последовательности ListSequence
    ListSequence(const ListSequence<T> &listSequence) {
        this->length = listSequence.length;
        this->head = nullptr;
        this->tail = nullptr;
        std::shared_ptr<Node> current = listSequence.head;
        //добавляем все элементы списка в новый список (пока не дойдем до конца)
        while (current != nullptr) {
            this->append(current->value);
            current = current->next;
        }
    }

    //Методы, которые мы должны реализовать из класса Sequence
    //получить первый элемент последовательности
    T getFirst() const override {
        //если список пустой, то бросаем исключение
        if (this->length == 0) {
            throw std::out_of_range("List is empty");
        }
        //возвращаем значение первого элемента
        return this->head->value;
    }

    //получить последний элемент последовательности
    T getLast() const override {
        //если список пустой, то бросаем исключение
        if (this->length == 0) {
            throw std::out_of_range("List is empty");
        }
        //возвращаем значение последнего элемента
        return this->tail->value;
    }

    //получить элемент по индексу
    T get(int index) const override {
        //если индекс выходит за границы списка, то бросаем исключение
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        std::shared_ptr<Node> current = this->head; //начинаем с начала списка
        //проходим по списку до нужного индекса
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        //возвращаем значение элемента
        return current->value;
    }

    //перегрузка оператора [] (то же самое, что и get)
    T operator[](int index) const override {
        return this->get(index); //вызываем метод get как раз
    }

    //получить подпоследовательность
    ListSequence<T> *getSubsequence(int startIndex, int endIndex) const override {
        //если индексы выходят за границы списка, то бросаем исключение (по условию задачи)
        if (startIndex < 0 || startIndex >= this->length || endIndex < 0 || endIndex >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        if (startIndex > endIndex) {
            throw std::invalid_argument("Start index is greater than end index");
        }
        //создаем новый список, в который будем добавлять элементы
        auto *subsequence = new ListSequence<T>();
        //начинаем с начала списка
        std::shared_ptr<Node> current = this->head;
        //проходим по списку до начального индекса
        for (int i = 0; i < startIndex; i++) {
            current = current->next;
        }
        //добавляем все элементы в новый список
        for (int i = startIndex; i <= endIndex; i++) {
            subsequence->append(current->value);
            current = current->next;
        }
        //возвращаем новый список
        return subsequence;
    }

    //получить длину последовательности
    int getLength() const override {
        return this->length;
    }

    //добавить элемент в конец последовательности
    void append(T value) override {
        //создаем новый узел
        auto newNode = std::make_shared<Node>(value);
        //если список пустой, то новый узел и будет началом и концом списка
        if (this->length == 0) {
            this->head = newNode;
            this->tail = newNode;
        } else { //иначе добавляем новый узел в конец списка
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        //увеличиваем длину на 1
        this->length++;
    }

    //добавить элемент в начало последовательности
    void prepend(T value) override {
        //создаем новый узел
        auto newNode = std::make_shared<Node>(value);
        //если список пустой, то новый узел и будет началом и концом списка
        if (this->length == 0) {
            this->head = newNode;
            this->tail = newNode;
        } else { //иначе добавляем новый узел в начало списка
            this->head->prev = newNode;
            newNode->next = this->head;
            this->head = newNode;
        }
        //увеличиваем длину на 1
        this->length++;
    }

    //вставить элемент по индексу
    void insertAt(T value, int index) override {
        //если индекс выходит за границы списка, то бросаем исключение (по условию задачи)
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        //создаем новый узел
        auto newNode = std::make_shared<Node>(value);
        //начинаем с начала списка
        std::shared_ptr<Node> current = this->head;
        //проходим по списку до нужного индекса
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        //если индекс не равен 0, то вставляем новый узел между текущим и предыдущим
        if (current->prev != nullptr) {
            current->prev->next = newNode;
            newNode->prev = current->prev;
        } else { //иначе новый узел становится началом списка
            this->head = newNode;
        }
        //вставляем новый узел между текущим и предыдущим
        newNode->next = current;
        current->prev = newNode;
        //увеличиваем длину на 1
        this->length++;
    }

    //установить значение элемента по индексу
    void set(int index, T value) override {
        //если индекс выходит за границы списка, то бросаем исключение (по условию задачи)
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        //начинаем с начала списка
        std::shared_ptr<Node> current = this->head;
        //проходим по списку до нужного индекса
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        //устанавливаем новое значение
        current->value = value;
    }

    //объединить две последовательности
    ListSequence<T> *concat(Sequence<T> *sequence) const override {
        //проверяем, что sequence - это ListSequence
        auto *listSequence = dynamic_cast<ListSequence<T> *>(sequence);
        //если нет, то бросаем исключение
        if (listSequence == nullptr) {
            throw std::invalid_argument("Sequence is not ListSequence");
        }
        //создаем новый список, который будет объединением двух списков
        auto *newListSequence = new ListSequence<T>(*this);
        //начинаем с начала второго списка
        std::shared_ptr<Node> current = listSequence->head;
        //добавляем все элементы в новый список
        while (current != nullptr) {
            newListSequence->append(current->value); //добавляем элемент в конец списка
            current = current->next; //переходим к следующему элементу
        }
        //возвращаем новый список
        return newListSequence;
    }

    //деструктор - удаляет все узлы списка (default, так как shared_ptr сам удаляет память)
    ~ListSequence() override = default;
};

#endif //SEQUENCES_LISTSEQUENCE_H
