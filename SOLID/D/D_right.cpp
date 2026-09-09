#include <iostream>
#include <memory>
#include <vector>

// 1. Abstraction: Contract that all animals fulfill
class IEating {
public:
    virtual ~IEating() = default;
    virtual void eat() = 0;
};

// 2. Low-Level Implementation 1
class Lion : public IEating {
public:
    void eat() override {
        std::cout << "Lion is eating meat.\n";
    }
};

// 3. Low-Level Implementation 2
class Elephant : public IEating {
public:
    void eat() override {
        std::cout << "Elephant is eating grass.\n";
    }
};

// 4. Low-Level Implementation 3 (Added without touching Caretaker)
class Penguin : public IEating {
public:
    void eat() override {
        std::cout << "Penguin is eating fish.\n";
    }
};

// High-Level Class: Depends strictly on the IAnimal abstraction!
class Caretaker {
private:
    std::vector<std::shared_ptr<IEating>> animals;

public:
    // Injected via constructor
    explicit Caretaker(std::vector<std::shared_ptr<IEating>> animals)
        : animals(std::move(animals)) {}

    void feedAnimals() {
        for (const auto& animal : animals) {
            animal->eat(); // Uniform interface
        }
    }
};