#include "ArraySequence.h"
#include "ListSequence.h"
#include "Sequence.h"
#include "QSorter.h"
#include "PSorter.h"
#include "ISorter.h"
#include "BubbleSorter.h"
#include <fstream>
#include <type_traits>
#include "Car.h"
#include "Pet.h"

//функция для измерения времени сортировки и записи результатов в вектор
template<typename T>
void measureSortTime(ISorter<T>* sorter, Sequence<T>* sequence, std::function<bool(T, T)> comparator, const std::string& sorterName, std::vector<std::pair<std::string, int>>& results) {
    auto start = std::chrono::high_resolution_clock::now();
    sorter->sort(sequence, comparator, false);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << sorterName << " Time: " << duration << "ms\n";
    results.emplace_back(sorterName, duration);
}

//функция для печати графика времени сортировки
void printGraph(const std::vector<std::pair<std::string, int>>& results) {
    //находим максимальное время сортировки
    int maxTime = std::max_element(results.begin(), results.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    })->second;

    if (maxTime == 0) { //если все времена сортировки равны нулю, график не отображается
        std::cout << "All sorting times are zero, cannot display graph.\n";
        return;
    }

    for (const auto& result : results) { //печатаем график времени сортировки
        std::cout << result.first << ": ";
        if(result.first.size() < 10) { //если название сортировщика короткое, добавляем отступы
            std::cout << "     ";
        }
        int barLength = (result.second * 50) / maxTime; // масштабируем длину столбца
        for (int i = 0; i < barLength; ++i) { //печатаем столбец
            std::cout << "#";
        }
        std::cout << " " << result.second << "ms\n"; //печатаем время сортировки
    }
}

template<typename T>
bool menu(Sequence<T>* sequence) { //функция, которая выводит меню и обрабатывает выбор пользователя
    std::cout << "Choose action:" << std::endl; //выбираем действие
    std::cout << "1. Append" << std::endl;
    std::cout << "2. Prepend" << std::endl;
    std::cout << "3. Print" << std::endl;
    std::cout << "4. Sort" << std::endl;
    std::cout << "5. Read sequence from created file" << std::endl;
    std::cout << "6. Sort comparison" << std::endl;
    std::cout << "7. Exit" << std::endl;
    int choice;
    std::cin >> choice;
    switch(choice) {
        case 1: { //если выбрано добавление элемента в конец
            if constexpr (std::is_same<T, int>::value) { //если тип элементов - int
                std::cout << "Enter the value to append: ";
                int value;
                std::cin >> value;
                sequence->append(value); //добавляем элемент в конец последовательности
            }
            else if constexpr (std::is_same<T, Car>::value) { //если тип элементов - Car
                Car car;
                std::cin >> car;
                sequence->append(car);
            }
            else if constexpr (std::is_same<T, Pet>::value) { //если тип элементов - Pet
                Pet pet;
                std::cin >> pet;
                sequence->append(pet);
            }
            return true;
        }
        case 2: { //если выбрано добавление элемента в начало
            if constexpr (std::is_same<T, int>::value) {
                std::cout << "Enter the value to prepend: ";
                int value;
                std::cin >> value;
                sequence->prepend(value); //добавляем элемент в конец последовательности
            }
            else if constexpr (std::is_same<T, Car>::value) {
                Car car;
                std::cin >> car;
                sequence->prepend(car);
            }
            else if constexpr (std::is_same<T, Pet>::value) {
                Pet pet;
                std::cin >> pet;
                sequence->prepend(pet);
            }
            return true;
        }
        case 3: { //если выбрано печать последовательности
            sequence->print(); //печатаем последовательность
            return true;
        }
        case 4: { //если выбрана сортировка
            if(sequence->getLength() == 0) { //если последовательность пуста
                std::cout << "The sequence is empty\n";
                return true;
            }
            std::cout << "Choose the type of sorter:\n1. QSorter\n2. PSorter\n3. BubbleSorter\n"; //выбираем тип сортировки
            std::cin >> choice;
            ISorter<T>* sorter; //создаем указатель на сортировщик
            switch(choice) {
                case 1: //если выбран QSorter
                    sorter = new QSorter<T>();
                    break;
                case 2: //если выбран PSorter
                    sorter = new PSorter<T>();
                    break;
                case 3: //если выбран BubbleSorter
                    sorter = new BubbleSorter<T>();
                    break;
                default: //если выбран неверный вариант
                    std::cout << "Invalid choice\n";
                    return true;
            }
            std::function<bool(T, T)> comparator; //создаем функцию-компаратор
            if constexpr (std::is_same<T, int>::value) {
                std::cout << "Choose the type of comparator:\n1. Ascending\n2. Descending\n"; //выбираем тип компаратора
                std::cin >> choice;
                switch(choice) {
                    case 1: //если выбран Ascending
                        comparator = ascendingComparator<T>; //присваиваем компаратору функцию сравнения для возрастающей сортировки
                        break;
                    case 2: //если выбран Descending
                        comparator = descendingComparator<T>; //присваиваем компаратору функцию сравнения для убывающей сортировки
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                        return true;
                }
            }
            else if constexpr (std::is_same<T, Car>::value){
                std::cout << "Choose the type of comparator:\n1. By price\n2. By brand\n3. By model\n4. By year\n"; //выбираем тип компаратора
                std::cin >> choice;
                switch(choice) {
                    case 1: //если выбрано по марке
                        comparator = [](Car a, Car b) { return a.getBrand() < b.getBrand(); };
                        break;
                    case 2: //если выбрано по модели
                        comparator = [](Car a, Car b) { return a.getModel() < b.getModel(); };
                        break;
                    case 3: //если выбрано по году
                        comparator = [](Car a, Car b) { return a.getYear() < b.getYear(); };
                        break;
                    case 4: //если выбрано по cтоимости
                        comparator = [](Car a, Car b) { return a.getPrice() < b.getPrice(); };
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                        return true;
                }
            }
            else if constexpr (std::is_same<T, Pet>::value){
                std::cout << "Choose the type of comparator:\n1. By name\n2. By age\n3. By breed\n"; //выбираем тип компаратора
                std::cin >> choice;
                switch(choice) {
                    case 1: //если выбрано по имени
                        comparator = [](Pet a, Pet b) { return a.getName() < b.getName(); };
                        break;
                    case 2: //если выбрано по возрасту
                        comparator = [](Pet a, Pet b) { return a.getAge() < b.getAge(); };
                        break;
                    case 3: //если выбрано по породе
                        comparator = [](Pet a, Pet b) { return a.getBreed() < b.getBreed(); };
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                        return true;
                }
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
            if (eraseFlag == 'y') { //если флаг стирания включен
                std::remove("sequence.txt"); //удаляем файл
                sequence->clear(); //очищаем последовательность
            }
            if constexpr (std::is_same<T, int>::value) {
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
            }
            else if constexpr (std::is_same<T, Car>::value) {
                std::cout << "Enter the number of cars: "; //вводим количество машин
                int n;
                std::cin >> n;
                std::ofstream file("sequence.txt"); //создаем файл для записи
                for (int i = 0; i < n; i++) { //заполняем файл случайными машинами
                    Car car;
                    file << car << " "; //записываем машину в файл
                }
                file.close(); //закрываем файл
                std::ifstream file2("sequence.txt"); //открываем файл для чтения
                for (int i = 0; i < n; i++) { //считываем машины из файла
                    Car car;
                    file2 >> car;
                    sequence->append(car); //добавляем машины в последовательность
                }
                file2.close(); //закрываем файл
            }
            else if constexpr (std::is_same<T, Pet>::value) {
                std::cout << "Enter the number of pets: "; //вводим количество животных
                int n;
                std::cin >> n;
                std::ofstream file("sequence.txt"); //создаем файл для записи
                for (int i = 0; i < n; i++) { //заполняем файл случайными животными
                    Pet pet;
                    file << pet << " "; //записываем животное в файл
                }
                file.close(); //закрываем файл
                std::ifstream file2("sequence.txt"); //открываем файл для чтения
                for (int i = 0; i < n; i++) { //считываем животных из файла
                    Pet pet;
                    file2 >> pet;
                    sequence->append(pet); //добавляем животных в последовательность
                }
                file2.close(); //закрываем файл
            }
            return true;
        }
        case 6:{
            Sequence<T>* sequence2 = sequence->copy();
            Sequence<T>* sequence3 = sequence->copy();
            ISorter<T>* sorter1 = new QSorter<T>();
            ISorter<T>* sorter2 = new PSorter<T>();
            ISorter<T>* sorter3 = new BubbleSorter<T>();
            std::function<bool(T, T)> comparator; //создаем функцию-компаратор
            if constexpr (std::is_same<T, int>::value) {
                std::cout << "Choose the type of comparator:\n1. Ascending\n2. Descending\n"; //выбираем тип компаратора
                std::cin >> choice;
                switch(choice) {
                    case 1: //если выбран Ascending
                        comparator = ascendingComparator<T>; //присваиваем компаратору функцию сравнения для возрастающей сортировки
                        break;
                    case 2: //если выбран Descending
                        comparator = descendingComparator<T>; //присваиваем компаратору функцию сравнения для убывающей сортировки
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                        return true;
                }
            }
            else if constexpr (std::is_same<T, Car>::value){
                std::cout << "Choose the type of comparator:\n1. By price\n2. By brand\n3. By model\n4. By year\n"; //выбираем тип компаратора
                std::cin >> choice;
                switch(choice) {
                    case 1: //если выбрано по марке
                        comparator = [](Car a, Car b) { return a.getBrand() < b.getBrand(); };
                        break;
                    case 2: //если выбрано по модели
                        comparator = [](Car a, Car b) { return a.getModel() < b.getModel(); };
                        break;
                    case 3: //если выбрано по году
                        comparator = [](Car a, Car b) { return a.getYear() < b.getYear(); };
                        break;
                    case 4: //если выбрано по стоимости
                        comparator = [](Car a, Car b) { return a.getPrice() < b.getPrice(); };
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                        return true;
                }
            }
            else if constexpr (std::is_same<T, Pet>::value){
                std::cout << "Choose the type of comparator:\n1. By name\n2. By age\n3. By breed\n4. By weight\n"; //выбираем тип компаратора
                std::cin >> choice;
                switch(choice) {
                    case 1: //если выбрано по имени
                        comparator = [](Pet a, Pet b) { return a.getName() < b.getName(); };
                        break;
                    case 2: //если выбрано по возрасту
                        comparator = [](Pet a, Pet b) { return a.getAge() < b.getAge(); };
                        break;
                    case 3: //если выбрано по породе
                        comparator = [](Pet a, Pet b) { return a.getBreed() < b.getBreed(); };
                        break;
                    case 4:
                        comparator = [](Pet a, Pet b) { return a.getWeight() < b.getWeight(); };
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                        return true;
                }
            }

            std::vector<std::pair<std::string, int>> results; //вектор для хранения результатов измерения времени сортировки
            measureSortTime(sorter1, sequence, comparator, "QSorter", results); //измеряем время сортировки для каждого сортировщика
            measureSortTime(sorter2, sequence2, comparator, "PSorter", results);
            measureSortTime(sorter3, sequence3, comparator, "BubbleSorter", results);

            delete sorter1; //удаляем сортировщик
            delete sorter2;
            delete sorter3;

            delete sequence2; //удаляем копии последовательности
            delete sequence3;

            printGraph(results); //выводим график времени сортировки
            return true;
        }
        case 7: //выходим из программы
            return false;
        default: //если выбран неверный вариант
            std::cout << "Invalid choice\n";
            return true;
    }
}


int main() {
    std::cout << "What type of elements do you want to work with?\n1. Integers\n2. Cars\n3. Pets\n"; //выбор типа элементов
    int type;
    std::cin >> type;
    if(type == 1){
        Sequence<int>* sequence;
        std::cout << "Choose the type of sequence:\n1. ArraySequence\n2. ListSequence\n"; //выбор типа последовательности
        int choice;
        std::cin >> choice;
        switch(choice) {
            case 1: //если выбран ArraySequence
                sequence = new ArraySequence<int>(); //создаем указатель на ArraySequence
                break;
            case 2: //если выбран ListSequence
                sequence = new ListSequence<int>(); //создаем указатель на ListSequence
                break;
            default: //если выбран неверный вариант
                std::cout << "Invalid choice\n";
                return 0;
        }
        while(menu(sequence)); //выводим меню и обрабатываем выбор пользователя
        delete sequence; //удаляем последовательность
    }
    else if(type == 2){
        Sequence<Car>* sequence;
        std::cout << "Choose the type of sequence:\n1. ArraySequence\n2. ListSequence\n"; //выбор типа последовательности
        int choice;
        std::cin >> choice;
        switch(choice) {
            case 1: //если выбран ArraySequence
                sequence = new ArraySequence<Car>(); //создаем указатель на ArraySequence
                break;
            case 2: //если выбран ListSequence
                sequence = new ListSequence<Car>(); //создаем указатель на ListSequence
                break;
            default: //если выбран неверный вариант
                std::cout << "Invalid choice\n";
                return 0;
        }
        while(menu(sequence)); //выводим меню и обрабатываем выбор пользователя
        delete sequence; //удаляем последовательность
    }
    else if(type == 3){
        Sequence<Pet>* sequence;
        std::cout << "Choose the type of sequence:\n1. ArraySequence\n2. ListSequence\n"; //выбор типа последовательности
        int choice;
        std::cin >> choice;
        switch(choice) {
            case 1: //если выбран ArraySequence
                sequence = new ArraySequence<Pet>(); //создаем указатель на ArraySequence
                break;
            case 2: //если выбран ListSequence
                sequence = new ListSequence<Pet>(); //создаем указатель на ListSequence
                break;
            default: //если выбран неверный вариант
                std::cout << "Invalid choice\n";
                return 0;
        }
        while(menu(sequence)); //выводим меню и обрабатываем выбор пользователя
        delete sequence; //удаляем последовательность
    }
    else{
        std::cout << "Invalid choice\n";
    }
    return 0;
}