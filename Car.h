#ifndef SEQUENCES_CAR_H
#define SEQUENCES_CAR_H

#include <string>
#include <iostream>

class Car {
private:
    std::string brand;
    std::string model;
    int year;
    double price;

public:
    Car() { //конструктор по умолчанию случайным образом заполняет поля
        std::string brands[] = {"Audi", "BMW", "Mercedes", "Toyota", "Volkswagen", "Ford", "Chevrolet", "Honda", "Hyundai", "Nissan"};
        std::string models[] = {"A3", "X5", "C-Class", "Camry", "Passat", "Focus", "Cruze", "Civic", "Elantra", "Altima"};
        brand = brands[rand() % 10];
        model = models[rand() % 10];
        year = 1944 + rand() % 80;
        price = 5000 + rand() % 100000;
    }

    Car(std::string brand, std::string model, int year, double price) : brand(brand), model(model), year(year), price(price) {}

    std::string getBrand() const {
        return brand;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getPrice() const {
        return price;
    }

    void setBrand(std::string brand) {
        this->brand = brand;
    }

    void setModel(std::string model) {
        this->model = model;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setPrice(double price) {
        this->price = price;
    }

    friend std::ostream& operator<<(std::ostream& out, const Car& car) { //корректный вывод объекта в поток
        out << car.brand << " " << car.model << " (" << car.year << ") - " << car.price << "$";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Car& car) { //корректный ввод объекта из потока
        if(&in == &std::cin) std::cout << "Enter brand: "; //если ввод из консоли, то выводим подсказку
        in >> car.brand;
        if(&in == &std::cin) std::cout << "Enter model: ";
        in >> car.model;
        if(&in == &std::cin) std::cout << "Enter year: ";
        in >> car.year;
        if(&in == &std::cin) std::cout << "Enter price: ";
        in >> car.price;
        return in;
    }
};

#endif //SEQUENCES_CAR_H
