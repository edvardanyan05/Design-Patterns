#include <iostream>
#include <string>

class Car{
public:
    class Builder;
private:
    double engineCapacity;
    int maxSpeed;
    
    std::string color = "Black";
    int numberOfDoors = 4;

    Car(double engineCapacity, int maxSpeed)
        : engineCapacity(engineCapacity), maxSpeed(maxSpeed) {}

public:
    void displaySpecifications() const {
        std::cout << "Car Specifications:\n";
        std::cout << "Engine Capacity: " << engineCapacity << " liters\n";
        std::cout << "Max Speed: " << maxSpeed << " km/h\n";
        std::cout << "Color: " << color << "\n";
        std::cout << "Number of Doors: " << numberOfDoors << "\n";
    }
};

class Car::Builder {
private:
    Car car;
public:
    Builder(double engineCapacity, int maxSpeed)
        : car(engineCapacity, maxSpeed) {}
    Builder& setColor(const std::string& color) {
        car.color = color;
        return *this;
    }
    Builder& setNumberOfDoors(int numberOfDoors) {
        car.numberOfDoors = numberOfDoors;
        return *this;
    }
    Car build() {
        return std::move(car);
    }
};

int main() {
    Car::Builder builder(2.0, 220);
    Car myCar = builder.setColor("Red").setNumberOfDoors(4).build();
    myCar.displaySpecifications();

    return 0;
}