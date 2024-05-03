#include <iostream>
#include <memory>
#include "ArraySequence.h"
#include "ListSequence.h"
int main() {
    //проверка, что всё работает
    //создаем последовательности на основе массива и списка (тип данных Sequence<int>, при
    //этом объект - ArraySequence<int> или ListSequence<int>)
    std::unique_ptr<Sequence<int>> arraySequence = std::make_unique<ArraySequence<int>>();
    //добавляем элементы в последовательности
    arraySequence->append(1);
    arraySequence->append(2);
    arraySequence->append(3);
    //выводим последовательности (благодаря перегрузке оператора <<)
    std::cout << *arraySequence << std::endl;

    //получаем подпоследовательность
    auto subsequence = arraySequence->getSubsequence(1, 2);
    //выводим подпоследовательность
    std::cout << *subsequence << std::endl;

    //аналогично для списка
    std::unique_ptr<Sequence<int>> listSequence = std::make_unique<ListSequence<int>>();
    listSequence->append(10);
    listSequence->append(20);
    listSequence->append(30);
    std::cout << *listSequence << std::endl;

    subsequence = listSequence->getSubsequence(1, 2);
    std::cout << *subsequence << std::endl;
    return 0;
}
