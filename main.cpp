#include <iostream>
#include <memory>
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Animal.h"

//функция меню
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
            std::unique_ptr<Sequence<int>> arraySequence = std::make_unique<ArraySequence<int>>();
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
                std::cout << "11. Exit" << std::endl;
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
                        //выход из программы
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
            std::unique_ptr<Sequence<int>> listSequence = std::make_unique<ListSequence<int>>();
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
                std::cout << "11. Exit" << std::endl;
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

int main() {
    while (menu());
    return 0;
}
