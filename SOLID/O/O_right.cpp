#include <iostream>
#include <string>
#include <vector>

enum class AnimalType { Dog, Cat, Cow };

class Animal {
public:
    AnimalType type;
    virtual void makeSound() const = 0;
};

class Dog : public Animal {
public:
    Dog() { type = AnimalType::Dog; }
    void makeSound() const override { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    Cat() { type = AnimalType::Cat; }
    void makeSound() const override { std::cout << "Meow!\n"; }
};

class Cow : public Animal {
public:
    Cow() { type = AnimalType::Cow; }
    void makeSound() const override { std::cout << "Moo!\n"; }
};

class AnimalSoundPlayer {
public:
    void makeSounds(const std::vector<std::unique_ptr<Animal>>& animals) {
        for (const auto& animal : animals) {
            animal->makeSound();
        }
    }
};