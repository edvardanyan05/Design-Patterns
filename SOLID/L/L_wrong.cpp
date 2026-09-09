#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

class Bird {
public:
    virtual ~Bird() = default;
    virtual void fly() const {
        std::cout << "Bird is flying high in the sky!\n";
    }
};

class Sparrow : public Bird {
public:
    void fly() const override {
        std::cout << "Sparrow is fluttering quickly!\n";
    }
};

// Violation: Ostrich is a Bird, but it CANNOT fly
class Ostrich : public Bird {
public:
    void fly() const override {
        //Throw an exception
        throw std::logic_error("Ostriches cannot fly!");
    }
};

// A function that expects any Bird to behave like a Bird
void makeBirdsFly(const std::vector<std::shared_ptr<Bird>>& birds) {
    for (const auto& bird : birds) {
        bird->fly(); // CRASH
    }
}