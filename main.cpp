#include <iostream>
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Sequence.h"
#include "QSorter.h"
#include "PSorter.h"
#include "ISorter.h"
#include "BubbleSorter.h"
#include <fstream>

bool menu(Sequence<int>* sequence) { //функция, которая выводит меню и обрабатывает выбор пользователя
    std::cout << "Choose action:" << std::endl; //выбираем действие
    std::cout << "1. Append" << std::endl;
    std::cout << "2. Prepend" << std::endl;
    std::cout << "3. Print" << std::endl;
    std::cout << "4. Sort" << std::endl;
    std::cout << "5. Read sequence from created file" << std::endl;
    std::cout << "6. Exit" << std::endl;
    int choice;
    std::cin >> choice;
    switch(choice) {
        case 1: { //если выбрано добавление элемента
            std::cout << "Enter the value to append: ";
            int value;
            std::cin >> value;
            sequence->append(value); //добавляем элемент в конец последовательности
            return true;
        }
        case 2: { //если выбрано добавление элемента в начало
            std::cout << "Enter the value to prepend: ";
            int value;
            std::cin >> value;
            sequence->prepend(value); //добавляем элемент в начало последовательности
            return true;
        }
        case 3: { //если выбрано печать последовательности
            sequence->print(); //печатаем последовательность
            return true;
        }
        case 4: { //если выбрана сортировка
            std::cout << "Choose the type of sorter:\n1. QSorter\n2. PSorter\n3. BubbleSorter\n"; //выбираем тип сортировки
            std::cin >> choice;
            ISorter<int>* sorter; //создаем указатель на сортировщик
            switch(choice) {
                case 1: //если выбран QSorter
                    sorter = new QSorter<int>();
                    break;
                case 2: //если выбран PSorter
                    sorter = new PSorter<int>();
                    break;
                case 3: //если выбран BubbleSorter
                    sorter = new BubbleSorter<int>();
                    break;
                default: //если выбран неверный вариант
                    std::cout << "Invalid choice\n";
                    return true;
            }
            std::cout << "Choose the type of comparator:\n1. Ascending\n2. Descending\n"; //выбираем тип компаратора
            std::cin >> choice;
            std::function<bool(int, int)> comparator; //создаем функцию-компаратор
            switch(choice) {
                case 1: //если выбран Ascending
                    comparator = ascendingComparator<int>; //присваиваем компаратору функцию сравнения для возрастающей сортировки
                    break;
                case 2: //если выбран Descending
                    comparator = descendingComparator<int>; //присваиваем компаратору функцию сравнения для убывающей сортировки
                    break;
                default:
                    std::cout << "Invalid choice\n";
                    return true;
            }
            std::cout << "Print the sorting process? (y/n)\n"; //выводить процесс сортировки?
            char printFlag; //флаг печати последовательности
            std::cin >> printFlag;
            std::cout << "Measure the time? (y/n)\n"; //измерять время сортировки?
            char timeFlag; //флаг измерения времени (время измеряется в любом случае, но выводится только если флаг включен)
            std::cin >> timeFlag;
            auto start = std::chrono::high_resolution_clock::now(); //засекаем время начала сортировки
            sequence = sorter->sort(sequence, comparator, printFlag == 'y'); //сортируем последовательность
            auto end = std::chrono::high_resolution_clock::now(); //засекаем время конца сортировки
            std::cout << std::endl; //перевод строки (чтобы меню не слиплось с последним выводом)
            if(timeFlag == 'y') { //если флаг измерения времени включен
                //выводим время сортировки (разницу между временем конца и временем начала в миллисекундах)
                std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
            }
            return true;
        }
        case 5: { //если выбрано чтение последовательности из файла
            std::cout << "Erase previous file? (y/n)\n"; //стереть предыдущие данные?
            char eraseFlag; //флаг стирания данных
            std::cin >> eraseFlag;
            if(eraseFlag == 'y') { //если флаг стирания включен
                std::remove("sequence.txt"); //удаляем файл
                sequence->clear(); //очищаем последовательность
            }
            std::cout << "Enter the number of elements: "; //вводим количество элементов
            int n;
            std::cin >> n;
            std::ofstream file("sequence.txt"); //создаем файл для записи
            for (int i = 0; i < n; i++) { //заполняем файл случайными числами
                int value = rand() % n; //генерируем случайное число от 0 до n
                file << value << " "; //записываем число в файл
            }
            file.close(); //закрываем файл
            std::ifstream file2("sequence.txt"); //открываем файл для чтения
            for (int i = 0; i < n; i++) { //считываем числа из файла
                int value;
                file2 >> value;
                sequence->append(value); //добавляем числа в последовательность
            }
            file2.close(); //закрываем файл
            return true;
        }
        case 6: //выходим из программы
            return false;
        default: //если выбран неверный вариант
            std::cout << "Invalid choice\n";
            return true;
    }
}

int main() {
    Sequence<int>* sequence; //создаем указатель на последовательность
    std::cout << "Choose the type of sequence:\n1. ArraySequence\n2. ListSequence\n"; //выбор типа последовательности
    int choice;
    std::cin >> choice;
    switch(choice) {
        case 1: //если выбран ArraySequence
            sequence = new ArraySequence<int>(); //создаем объект класса ArraySequence
            break;
        case 2: //если выбран ListSequence
            sequence = new ListSequence<int>(); //создаем объект класса ListSequence
            break;
        default: //если выбран неверный вариант
            std::cout << "Invalid choice\n";
            return 1;
    }
    while(menu(sequence)); //вызываем меню
    delete sequence; //удаляем последовательность
    return 0;
}