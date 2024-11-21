#ifndef SEQUENCES_ISORTER_H
#define SEQUENCES_ISORTER_H

#ifndef ISORTER_H
#define ISORTER_H

#include <functional> //подключаем библиотеку для использования std::function
#include "Sequence.h"

//класс ISorter - интерфейс (абстрактный класс), который реализуют классы-сортировщики
template<typename T>
class ISorter {
public:
    //Функция сортировки последовательности sequence с помощью компаратора comparator-сравнивателя (передаём в качестве параметра функцию сравнения)
    virtual Sequence<T>* sort(Sequence<T>* sequence, std::function<bool(T, T)> comparator, bool printFlag) = 0;
    virtual ~ISorter() = default; //виртуальный деструктор
};

template<typename T>
bool ascendingComparator(T a, T b) { //функция сравнения для возрастающей сортировки
    return a < b;
}

template<typename T>
bool descendingComparator(T a, T b) { //функция сравнения для убывающей сортировки
    return a > b;
}

#endif // ISORTER_H

#endif //SEQUENCES_ISORTER_H
