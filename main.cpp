#include <iostream>
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Sequence.h"
#include "ArrayQueue.h"
#include "ListQueue.h"

//функция меню
/*
bool menu(){
    std::cout << "Choose sequence type" << std::endl;
    std::cout << "1. ArraySequence" << std::endl;
    std::cout << "2. ListSequence" << std::endl;
    std::cout << "3. Exit" << std::endl;
    //выбор типа последовательности
    int choice;
    std::cin >> choice;
    switch (choice) {
        //работа с ArraySequence
        case 1: {
            //создание указателя на объект класса ArraySequence через родительский класс Sequence
            Sequence<int>* arraySequence = new ArraySequence<int>();
            int choice;
            do {
                //меню
                std::cout << "1. Append" << std::endl;
                std::cout << "2. Get" << std::endl;
                std::cout << "3. GetFirst" << std::endl;
                std::cout << "4. GetLast" << std::endl;
                std::cout << "5. GetSubsequence" << std::endl;
                std::cout << "6. GetLength" << std::endl;
                std::cout << "7. Print" << std::endl;
                std::cout << "8. InsertAt" << std::endl;
                std::cout << "9. Prepend" << std::endl;
                std::cout << "10. Set" << std::endl;
                std::cout << "11. Square all (2-power)" << std::endl;
                std::cout << "12. Multiply all by 2" << std::endl;
                std::cout << "13. Exit" << std::endl;
                std::cin >> choice;
                switch (choice) {
                    //добавление элемента в конец последовательности
                    case 1: {
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        arraySequence->append(value);
                        std::cout << "Now sequence is: ";
                        //вывод последовательности
                        arraySequence->print();
                        //выход из switch
                        break;
                    }
                    //получение элемента по индексу
                    case 2: {
                        //ввод индекса
                        int index;
                        std::cout << "Enter index: ";
                        std::cin >> index;
                        //try-catch на случай выхода за границы последовательности
                        try {
                            std::cout << "Value is: " << arraySequence->get(index) << std::endl;
                        }
                        catch (std::out_of_range &e) {
                            //если возникла ошибка, выводим сообщение
                            std::cout << "invalid index or sequence is empty" << std::endl;
                        }
                        break;
                    }

                    case 3: {
                        //try-catch на случай выхода за границы последовательности
                        try {
                            std::cout << "First value is: " << arraySequence->getFirst() << std::endl;
                        }

                        catch (std::out_of_range &e) {
                            //если возникла ошибка, выводим сообщение
                            std::cout << "invalid index or sequence is empty" << std::endl;
                        }
                        break;
                    }

                    case 4: {
                        //try-catch на случай выхода за границы последовательности
                        try {
                            std::cout << "Last value is: " << arraySequence->getLast() << std::endl;
                        }
                        catch (std::out_of_range &e) {
                            //если возникла ошибка, выводим сообщение
                            std::cout << "invalid index or sequence is empty" << std::endl;
                        }
                        break;
                    }

                    case 5: {
                        //для подпоследовательности вводим начальный и конечный индексы
                        int startIndex, endIndex;
                        std::cout << "Enter start index: ";
                        std::cin >> startIndex;
                        std::cout << "Enter end index: ";
                        std::cin >> endIndex;
                        //try-catch на случай выхода за границы последовательности
                        try {
                            //получаем подпоследовательность
                            auto subsequence = arraySequence->getSubsequence(startIndex, endIndex);
                            std::cout << "Subsequence is: ";
                            subsequence->print(); //выводим подпоследовательность
                        }
                        catch (std::out_of_range &e) {
                            //если возникла ошибка, выводим сообщение
                            std::cout << "invalid index or sequence is empty" << std::endl;
                        }
                        break;
                    }

                    case 6: {
                        //выводим длину последовательности
                        std::cout << "Length is: " << arraySequence->getLength() << std::endl;
                        break;
                    }

                    case 7: {
                        //выводим последовательность
                        arraySequence->print();
                        break;
                    }

                    case 8: {
                        //вводим индекс и значение
                        int index, value;
                        std::cout << "Enter index: ";
                        std::cin >> index;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        //вставляем значение по индексу
                        arraySequence->insertAt(value, index);
                        std::cout << "Now sequence is: ";
                        //выводим последовательность
                        arraySequence->print();
                        break;
                    }

                    case 9: {
                        //вводим значение
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        //добавляем значение в начало последовательности
                        arraySequence->prepend(value);
                        std::cout << "Now sequence is: ";
                        //выводим последовательность
                        arraySequence->print();
                        break;
                    }

                    case 10: {
                        //вводим индекс и значение
                        int index, value;
                        std::cout << "Enter index: ";
                        std::cin >> index;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        //изменяем значение по индексу
                        arraySequence->set(value, index);
                        std::cout << "Now sequence is: ";
                        //выводим последовательность
                        arraySequence->print();
                        break;
                    }

                    case 11: {
                        //возводим все элементы в квадрат
                        map([](int x) { return x * x; }, arraySequence);
                        std::cout << "Now sequence is: ";
                        //выводим последовательность
                        arraySequence->print();
                        break;
                    }

                    case 12: {
                        //умножаем все элементы на 2
                        map([](int x) { return x * 2; }, arraySequence);
                        std::cout << "Now sequence is: ";
                        //выводим последовательность
                        arraySequence->print();
                        break;
                    }

                    case 13: {
                        return true;
                    }

                    default: {
                        //если введен неверный пункт меню, выводим сообщение
                        std::cout << "Wrong choice" << std::endl;
                        break;
                    }
                }
            } while (true); //цикл будет повторяться, пока не будет введен пункт меню "Exit"
        }

        case 2: {
            //создание указателя на объект класса ListSequence через родительский класс Sequence
            //дальше то же самое, что и с ArraySequence
            Sequence<int>* listSequence = new ListSequence<int>();
            int choice;
            do {
                std::cout << "1. Append" << std::endl;
                std::cout << "2. Get" << std::endl;
                std::cout << "3. GetFirst" << std::endl;
                std::cout << "4. GetLast" << std::endl;
                std::cout << "5. GetSubsequence" << std::endl;
                std::cout << "6. GetLength" << std::endl;
                std::cout << "7. Print" << std::endl;
                std::cout << "8. InsertAt" << std::endl;
                std::cout << "9. Prepend" << std::endl;
                std::cout << "10. Set" << std::endl;
                std::cout << "11. Square all (2-power)" << std::endl;
                std::cout << "12. Multiply all by 2" << std::endl;
                std::cout << "13. Exit" << std::endl;
                std::cin >> choice;
                switch (choice) {
                    case 1: {
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        listSequence->append(value);
                        std::cout << "Now sequence is: ";
                        listSequence->print();
                        break;
                    }

                    case 2: {
                        int index;
                        std::cout << "Enter index: ";
                        std::cin >> index;
                        try {
                            std::cout << "Value is: " << listSequence->get(index) << std::endl;
                        }
                        catch (std::out_of_range &e) {
                            std::cout << "invalid index or sequence is empty" << std::endl;
                        }
                        break;
                    }

                    case 3: {
                        try {
                            std::cout << "First value is: " << listSequence->getFirst() << std::endl;
                        }
                        catch (std::out_of_range &e) {
                            std::cout << "invalid index or sequence is empty" << std::endl;
                        }
                        break;
                    }

                    case 4: {
                        try {
                            std::cout << "Last value is: " << listSequence->getLast() << std::endl;
                        }
                        catch (std::out_of_range &e) {
                            std::cout << "invalid index or sequence is empty" << std::endl;
                        }
                        break;
                    }

                    case 5: {
                        int startIndex, endIndex;
                        std::cout << "Enter start index: ";
                        std::cin >> startIndex;
                        std::cout << "Enter end index: ";
                        std::cin >> endIndex;
                        try {
                            auto subsequence = listSequence->getSubsequence(startIndex, endIndex);
                            std::cout << "Subsequence is: ";
                            subsequence->print();
                        }
                        catch (std::out_of_range &e) {
                            std::cout << "invalid index or sequence is empty" << std::endl;
                        }
                        break;
                    }

                    case 6: {
                        std::cout << "Length is: " << listSequence->getLength() << std::endl;
                        break;
                    }

                    case 7: {
                        listSequence->print();
                        break;
                    }

                    case 8: {
                        int index, value;
                        std::cout << "Enter index: ";
                        std::cin >> index;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        listSequence->insertAt(value, index);
                        std::cout << "Now sequence is: ";
                        listSequence->print();
                        break;
                    }

                    case 9: {
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        listSequence->prepend(value);
                        std::cout << "Now sequence is: ";
                        listSequence->print();
                        break;
                    }

                    case 10: {
                        int index, value;
                        std::cout << "Enter index: ";
                        std::cin >> index;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        listSequence->set(value, index);
                        std::cout << "Now sequence is: ";
                        listSequence->print();
                        break;
                    }

                    case 11: {
                        map([](int x) { return x * x; }, listSequence);
                        std::cout << "Now sequence is: ";
                        listSequence->print();
                        break;
                    }

                    case 12: {
                        map([](int x) { return x * 2; }, listSequence);
                        std::cout << "Now sequence is: ";
                        listSequence->print();
                        break;
                    }

                    case 13: {
                        return true;
                    }

                    default: {
                        std::cout << "Wrong choice" << std::endl;
                        break;
                    }
                }
            } while (true);
        }
        //выход из программы
        case 3:
            return false;
        //если введен неверный пункт меню, выводим сообщение
        default:
            std::cout << "Wrong choice" << std::endl;
            break;
    }
    //возвращаем true, чтобы цикл в main продолжался
    return true;
}
*/

bool menu(){
    std::cout << "Choose sequence type" << std::endl;
    std::cout << "1. ArrayQueue" << std::endl;
    std::cout << "2. ListQueue" << std::endl;
    std::cout << "3. Exit" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            Queue<int>* arrayQueue = new ArrayQueue<int>();
            int choice;
            do {
                std::cout << "1. Push" << std::endl;
                std::cout << "2. Pop" << std::endl;
                std::cout << "3. GetLength" << std::endl;
                std::cout << "4. GetSubQueue" << std::endl;
                std::cout << "5. Split" << std::endl;
                std::cout << "6. Concat" << std::endl;
                std::cout << "7. FindSubQueue" << std::endl;
                std::cout << "8. Exit" << std::endl;
                std::cin >> choice;
                switch (choice) {
                    case 1: {
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        arrayQueue->push(value);
                        std::cout << "Now queue is: ";
                        arrayQueue->print();
                        break;
                    }

                    case 2: {
                        try {
                            arrayQueue->pop();
                            std::cout << "Now queue is: ";
                            arrayQueue->print();
                        }
                        catch (std::out_of_range &e) {
                            std::cout << "Queue is empty" << std::endl;
                        }
                        break;
                    }

                    case 3: {
                        std::cout << "Length is: " << arrayQueue->getLength() << std::endl;
                        break;
                    }

                    case 4: {
                        int startIndex, endIndex;
                        std::cout << "Enter start index: ";
                        std::cin >> startIndex;
                        std::cout << "Enter end index: ";
                        std::cin >> endIndex;
                        try {
                            auto subQueue = arrayQueue->getSubQueue(startIndex, endIndex);
                            std::cout << "Subqueue is: ";
                            subQueue->print();
                        }
                        catch (std::out_of_range &e) {
                            std::cout << "Index out of range" << std::endl;
                        }
                        break;
                    }

                    case 5: {
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        auto [firstQueue, secondQueue] = arrayQueue->split(
                                [value](int x) { return x < value ? true : false; });
                        std::cout << "First queue is: ";
                        firstQueue->print();
                        std::cout << "Second queue is: ";
                        secondQueue->print();
                        break;
                    }

                    case 6: {
                        Queue<int> *newQueue = new ArrayQueue<int>();
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        newQueue->push(value);
                        auto concatedQueue = arrayQueue->concat(newQueue);
                        std::cout << "Concatenated queue is: ";
                        concatedQueue->print();
                        break;
                    }

                    case 7: {
                        Queue<int> *subQueue = new ArrayQueue<int>();
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        subQueue->push(value);
                        std::cout << "Index is: " << arrayQueue->findSubQueue(subQueue) << std::endl;
                        break;
                    }

                    case 8: {
                        return true;
                    }

                    default: {
                        std::cout << "Wrong choice" << std::endl;
                        break;
                    }
                }
            } while (true);
            delete arrayQueue;
            break;
        }

        case 2: {
            Queue<int> *listQueue = new ListQueue<int>();
            int choice;
            do {
                std::cout << "1. Push" << std::endl;
                std::cout << "2. Pop" << std::endl;
                std::cout << "3. GetLength" << std::endl;
                std::cout << "4. GetSubQueue" << std::endl;
                std::cout << "5. Split" << std::endl;
                std::cout << "6. Concat" << std::endl;
                std::cout << "7. FindSubQueue" << std::endl;
                std::cout << "8. Exit" << std::endl;
                std::cin >> choice;
                switch (choice) {
                    case 1: {
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        listQueue->push(value);
                        std::cout << "Now queue is: ";
                        listQueue->print();
                        break;
                    }

                    case 2: {
                        try {
                            listQueue->pop();
                            std::cout << "Now queue is: ";
                            listQueue->print();
                        }
                        catch (std::out_of_range &e) {
                            std::cout << "Queue is empty" << std::endl;
                        }
                        break;
                    }

                    case 3: {
                        std::cout << "Length is: " << listQueue->getLength() << std::endl;
                        break;
                    }

                    case 4: {
                        int startIndex, endIndex;
                        std::cout << "Enter start index: ";
                        std::cin >> startIndex;
                        std::cout << "Enter end index: ";
                        std::cin >> endIndex;
                        try {
                            auto subQueue = listQueue->getSubQueue(startIndex, endIndex);
                            std::cout << "Subqueue is: ";
                            subQueue->print();
                        }
                        catch (std::out_of_range &e) {
                            std::cout << "Index out of range" << std::endl;
                        }
                        break;
                    }

                    case 5: {
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        auto [firstQueue, secondQueue] = listQueue->split(
                                [value](int x) { return x < value ? true : false; });
                        std::cout << "First queue is: ";
                        firstQueue->print();
                        std::cout << "Second queue is: ";
                        secondQueue->print();
                        break;
                    }

                    case 6: {
                        Queue<int> *newQueue = new ListQueue<int>();
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        newQueue->push(value);
                        auto concatedQueue = listQueue->concat(newQueue);
                        std::cout << "Concatenated queue is: ";
                        concatedQueue->print();
                        break;
                    }

                    case 7: {
                        Queue<int> *subQueue = new ListQueue<int>();
                        int value;
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        subQueue->push(value);
                        std::cout << "Index is: " << listQueue->findSubQueue(subQueue) << std::endl;
                        break;
                    }

                    case 8: {
                        return true;
                    }

                    default: {
                        std::cout << "Wrong choice" << std::endl;
                        break;
                    }
                }
            } while (true);
            delete listQueue;
            break;
        }

        case 3:
            return false;

        default:
            std::cout << "Wrong choice" << std::endl;
            break;

        return true;
    }
}

int main() {
    while (menu());
    return 0;
}
