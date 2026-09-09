#include <iostream>
#include <vector>
#include <memory>

// Base class contains only traits/behaviors shared by all birds
class Bird {
public:
    virtual ~Bird() = default;
    virtual void eat() const {
        std::cout << "Eating seeds and bugs...\n";
    }
};

// Sub-interface/abstract class specifically for birds that can fly
class FlyingBird : public Bird {
public:
    virtual void fly() const = 0;
};

class Sparrow : public FlyingBird {
public:
    void fly() const override {
        std::cout << "Sparrow is flying smoothly!\n";
    }
};

// Ostrich inherits from Bird, not FlyingBird
class Ostrich : public Bird {
public:
    void eat() const override {
        std::cout << "Ostrich is pecking at grass...\n";
    }
};

void makeFlyingBirdsFly(const std::vector<std::shared_ptr<FlyingBird>>& flyingBirds) {
    for (const auto& bird : flyingBirds) {
        bird->fly();
    }
}

void feedAllBirds(const std::vector<std::shared_ptr<Bird>>& allBirds) {
    for (const auto& bird : allBirds) {
        bird->eat();
    }
}