#include "gtest/gtest.h"
#include "../QSorter.h"
#include "../PSorter.h"
#include "../BubbleSorter.h"
#include "../ArraySequence.h"
#include "../ListSequence.h"
#include "../Car.h"
#include "../Pet.h"

TEST(QSorter, Sort) {
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *arraySequence = new ArraySequence<int>(items, 5);
    QSorter<int> qSorter;
    qSorter.sort(arraySequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence->get(i), i + 1);
    }
    delete arraySequence;
}

TEST(PSorter, Sort) {
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *arraySequence = new ArraySequence<int>(items, 5);
    PSorter<int> pSorter;
    pSorter.sort(arraySequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence->get(i), i + 1);
    }
    delete arraySequence;
}

TEST(QSorter, SortList){
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *listSequence = new ListSequence<int>(items, 5);
    QSorter<int> qSorter;
    qSorter.sort(listSequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence->get(i), i + 1);
    }
    delete listSequence;
}

TEST(PSorter, SortList){
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *listSequence = new ListSequence<int>(items, 5);
    PSorter<int> pSorter;
    pSorter.sort(listSequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence->get(i), i + 1);
    }
    delete listSequence;
}

TEST(BubbleSorter, Sort){
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *arraySequence = new ArraySequence<int>(items, 5);
    BubbleSorter<int> bubbleSorter;
    bubbleSorter.sort(arraySequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraySequence->get(i), i + 1);
    }
    delete arraySequence;
}

TEST(BubbleSorter, SortList){
    int* items = new int[5];
    items[0] = 5;
    items[1] = 4;
    items[2] = 3;
    items[3] = 2;
    items[4] = 1;
    Sequence<int> *listSequence = new ListSequence<int>(items, 5);
    BubbleSorter<int> bubbleSorter;
    bubbleSorter.sort(listSequence, ascendingComparator<int>, 0);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(listSequence->get(i), i + 1);
    }
    delete listSequence;
}

TEST(QSorter, SortEmpty){
    Sequence<int> *arraySequence = new ArraySequence<int>();
    QSorter<int> qSorter;
    qSorter.sort(arraySequence, ascendingComparator<int>, 0);
    EXPECT_EQ(arraySequence->getLength(), 0);
    delete arraySequence;
}

TEST(PSorter, SortEmpty){
    Sequence<int> *arraySequence = new ArraySequence<int>();
    PSorter<int> pSorter;
    pSorter.sort(arraySequence, ascendingComparator<int>, 0);
    EXPECT_EQ(arraySequence->getLength(), 0);
    delete arraySequence;
}

TEST(BubbleSorter, SortEmpty){
    Sequence<int> *arraySequence = new ArraySequence<int>();
    BubbleSorter<int> bubbleSorter;
    bubbleSorter.sort(arraySequence, ascendingComparator<int>, 0);
    EXPECT_EQ(arraySequence->getLength(), 0);
    delete arraySequence;
}

TEST(QSorter, SortListEmpty){
    Sequence<int> *listSequence = new ListSequence<int>();
    QSorter<int> qSorter;
    qSorter.sort(listSequence, ascendingComparator<int>, 0);
    EXPECT_EQ(listSequence->getLength(), 0);
    delete listSequence;
}

TEST(PSorter, SortListEmpty){
    Sequence<int> *listSequence = new ListSequence<int>();
    PSorter<int> pSorter;
    pSorter.sort(listSequence, ascendingComparator<int>, 0);
    EXPECT_EQ(listSequence->getLength(), 0);
    delete listSequence;
}

TEST(BubbleSorter, SortListEmpty){
    Sequence<int> *listSequence = new ListSequence<int>();
    BubbleSorter<int> bubbleSorter;
    bubbleSorter.sort(listSequence, ascendingComparator<int>, 0);
    EXPECT_EQ(listSequence->getLength(), 0);
    delete listSequence;
}

TEST(QSorter, SortCars){
    Sequence<Car> *arraySequence = new ArraySequence<Car>();
    Car car1("Audi", "A4", 2000, 10000);
    Car car2("BMW", "X5", 2010, 20000);
    Car car3("Mercedes", "E-class", 2015, 30000);
    Car car4("Toyota", "Camry", 2018, 15000);
    Car car5("Volkswagen", "Passat", 2019, 18000);
    arraySequence->append(car1);
    arraySequence->append(car2);
    arraySequence->append(car3);
    arraySequence->append(car4);
    arraySequence->append(car5);

    QSorter<Car> qSorter;
    qSorter.sort(arraySequence, [](Car a, Car b) { return a.getPrice() < b.getPrice(); }, 0);
    EXPECT_EQ(arraySequence->get(0).getPrice(), 10000);
    EXPECT_EQ(arraySequence->get(1).getPrice(), 15000);
    EXPECT_EQ(arraySequence->get(2).getPrice(), 18000);
    EXPECT_EQ(arraySequence->get(3).getPrice(), 20000);
    EXPECT_EQ(arraySequence->get(4).getPrice(), 30000);
    delete arraySequence;
}

TEST(PSorter, SortCars){
    Sequence<Car> *arraySequence = new ArraySequence<Car>();
    Car car1("Audi", "A4", 2000, 10000);
    Car car2("BMW", "X5", 2010, 20000);
    Car car3("Mercedes", "E-class", 2015, 30000);
    Car car4("Toyota", "Camry", 2018, 15000);
    Car car5("Volkswagen", "Passat", 2019, 18000);
    arraySequence->append(car1);
    arraySequence->append(car2);
    arraySequence->append(car3);
    arraySequence->append(car4);
    arraySequence->append(car5);

    PSorter<Car> pSorter;
    pSorter.sort(arraySequence, [](Car a, Car b) { return a.getPrice() < b.getPrice(); }, 0);
    EXPECT_EQ(arraySequence->get(0).getPrice(), 10000);
    EXPECT_EQ(arraySequence->get(1).getPrice(), 15000);
    EXPECT_EQ(arraySequence->get(2).getPrice(), 18000);
    EXPECT_EQ(arraySequence->get(3).getPrice(), 20000);
    EXPECT_EQ(arraySequence->get(4).getPrice(), 30000);
    delete arraySequence;
}

TEST(BubbleSorter, SortCars){
    Sequence<Car> *arraySequence = new ArraySequence<Car>();
    Car car1("Audi", "A4", 2000, 10000);
    Car car2("BMW", "X5", 2010, 20000);
    Car car3("Mercedes", "E-class", 2015, 30000);
    Car car4("Toyota", "Camry", 2018, 15000);
    Car car5("Volkswagen", "Passat", 2019, 18000);
    arraySequence->append(car1);
    arraySequence->append(car2);
    arraySequence->append(car3);
    arraySequence->append(car4);
    arraySequence->append(car5);

    BubbleSorter<Car> bubbleSorter;
    bubbleSorter.sort(arraySequence, [](Car a, Car b) { return a.getPrice() < b.getPrice(); }, 0);
    EXPECT_EQ(arraySequence->get(0).getPrice(), 10000);
    EXPECT_EQ(arraySequence->get(1).getPrice(), 15000);
    EXPECT_EQ(arraySequence->get(2).getPrice(), 18000);
    EXPECT_EQ(arraySequence->get(3).getPrice(), 20000);
    EXPECT_EQ(arraySequence->get(4).getPrice(), 30000);
    delete arraySequence;
}

TEST(QSorter, SortPets){
    Sequence<Pet> *arraySequence = new ArraySequence<Pet>();
    Pet pet1("Cat", "Barsik", 5, 100);
    Pet pet2("Dog", "Rex", 3, 200);
    Pet pet3("Parrot", "Kesha", 2, 300);
    Pet pet4("Turtle", "Tortilla", 1, 150);
    Pet pet5("Rabbit", "Bunny", 4, 180);
    arraySequence->append(pet1);
    arraySequence->append(pet2);
    arraySequence->append(pet3);
    arraySequence->append(pet4);
    arraySequence->append(pet5);

    QSorter<Pet> qSorter;
    qSorter.sort(arraySequence, [](Pet a, Pet b) { return a.getWeight() < b.getWeight(); }, 0);
    EXPECT_EQ(arraySequence->get(0).getWeight(), 100);
    EXPECT_EQ(arraySequence->get(1).getWeight(), 150);
    EXPECT_EQ(arraySequence->get(2).getWeight(), 180);
    EXPECT_EQ(arraySequence->get(3).getWeight(), 200);
    EXPECT_EQ(arraySequence->get(4).getWeight(), 300);
    delete arraySequence;
}

TEST(PSorter, SortPets){
    Sequence<Pet> *arraySequence = new ArraySequence<Pet>();
    Pet pet1("Cat", "Barsik", 5, 100);
    Pet pet2("Dog", "Rex", 3, 200);
    Pet pet3("Parrot", "Kesha", 2, 300);
    Pet pet4("Turtle", "Tortilla", 1, 150);
    Pet pet5("Rabbit", "Bunny", 4, 180);
    arraySequence->append(pet1);
    arraySequence->append(pet2);
    arraySequence->append(pet3);
    arraySequence->append(pet4);
    arraySequence->append(pet5);

    PSorter<Pet> pSorter;
    pSorter.sort(arraySequence, [](Pet a, Pet b) { return a.getWeight() < b.getWeight(); }, 0);
    EXPECT_EQ(arraySequence->get(0).getWeight(), 100);
    EXPECT_EQ(arraySequence->get(1).getWeight(), 150);
    EXPECT_EQ(arraySequence->get(2).getWeight(), 180);
    EXPECT_EQ(arraySequence->get(3).getWeight(), 200);
    EXPECT_EQ(arraySequence->get(4).getWeight(), 300);
    delete arraySequence;
}

TEST(BubbleSorter, SortPets){
    Sequence<Pet> *arraySequence = new ArraySequence<Pet>();
    Pet pet1("Cat", "Barsik", 5, 100);
    Pet pet2("Dog", "Rex", 3, 200);
    Pet pet3("Parrot", "Kesha", 2, 300);
    Pet pet4("Turtle", "Tortilla", 1, 150);
    Pet pet5("Rabbit", "Bunny", 4, 180);
    arraySequence->append(pet1);
    arraySequence->append(pet2);
    arraySequence->append(pet3);
    arraySequence->append(pet4);
    arraySequence->append(pet5);

    BubbleSorter<Pet> bubbleSorter;
    bubbleSorter.sort(arraySequence, [](Pet a, Pet b) { return a.getWeight() < b.getWeight(); }, 0);
    EXPECT_EQ(arraySequence->get(0).getWeight(), 100);
    EXPECT_EQ(arraySequence->get(1).getWeight(), 150);
    EXPECT_EQ(arraySequence->get(2).getWeight(), 180);
    EXPECT_EQ(arraySequence->get(3).getWeight(), 200);
    EXPECT_EQ(arraySequence->get(4).getWeight(), 300);
    delete arraySequence;
}