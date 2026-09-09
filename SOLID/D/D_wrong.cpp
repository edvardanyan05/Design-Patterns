#include <iostream>

// Low-Level Concrete Class 1
class Lion {
public:
    void eatMeat() {
        std::cout << "Lion is eating meat.\n";
    }
};

// Low-Level Concrete Class 2
class Elephant {
public:
    void eatGrass() {
        std::cout << "Elephant is eating grass.\n";
    }
};

// High-Level Class: Tied directly to concrete animals!
class Caretaker {
private:
    Lion lion;         // Direct hardcoded dependency
    Elephant elephant; // Direct hardcoded dependency

public:
    void feedAnimals() {
        lion.eatMeat();
        elephant.eatGrass();
    }
};