#ifndef SEQUENCES_PET_H
#define SEQUENCES_PET_H

#include <string>
#include <ostream>

class Pet {
private:
    std::string name;
    std::string breed;
    int age;
    double weight;

public:
    Pet(){ //конструктор по умолчанию случайным образом заполняет поля
        std::string names[] = {"Charly", "Max", "Bro", "Bobby", "Qwerty", "Archie", "Bonny", "Toby", "Obeme", "Teddy"};
        std::string breeds[] = {"Retriver", "Bulldog", "Poodle", "Beagle", "Husky", "Pug", "Boxer", "Dalmatian", "Doberman", "Chihuahua"};
        name = names[rand() % 10];
        breed = breeds[rand() % 10];
        age = 1 + rand() % 20;
        weight = 1 + rand() % 50;
    }

    Pet(std::string name, std::string breed, int age, double weight) : name(name), breed(breed), age(age), weight(weight) {}

    std::string getName() const {
        return name;
    }

    std::string getBreed() const {
        return breed;
    }

    int getAge() const {
        return age;
    }

    double getWeight() const {
        return weight;
    }

    void setName(std::string name) {
        this->name = name;
    }

    void setBreed(std::string breed) {
        this->breed = breed;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setWeight(double weight) {
        this->weight = weight;
    }

    friend std::ostream& operator<<(std::ostream& out, const Pet& pet) { //корректный вывод объекта в поток
        out << pet.name << " (" << pet.breed << ", " << pet.age << " years, " << pet.weight << " kg)";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Pet& pet) { //корректный ввод объекта из потока
        if(&in == &std::cin) std::cout << "Enter name: "; //если ввод из консоли, то выводим подсказку
        in >> pet.name;
        if(&in == &std::cin) std::cout << "Enter breed: ";
        in >> pet.breed;
        if(&in == &std::cin) std::cout << "Enter age: ";
        in >> pet.age;
        if(&in == &std::cin) std::cout << "Enter weight: ";
        in >> pet.weight;
        return in;
    }
};

#endif //SEQUENCES_PET_H
