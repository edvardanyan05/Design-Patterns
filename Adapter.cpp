#include <iostream>

class Animal {
public:
    virtual void makeSound() const = 0;
    virtual void action() const = 0;
    virtual ~Animal() = default;
};

class Horse : public Animal {
public:
    void makeSound() const override {
        std::cout << "Neigh\n";
    }
    void action() const override {
        std::cout << "Running!\n";
    }
};

class Plane{
public:
    void action(){
        std::cout << "Flying!\n";
    }
};

class AnimalAdapter : public Animal {
private:
    Plane* plane;
public:
    explicit AnimalAdapter(Plane* p) : plane(p) {}

    void makeSound() const override {
        std::cout << "Jet engine roar!\n";
    }

    void action() const override {
        plane->action();
    }
};

int main() {
    Horse horse;
    Plane plane;
    AnimalAdapter unicorn(&plane);

    std::cout << "Horse:\n";
    horse.makeSound();
    horse.action();

    std::cout << "\nPlane:\n";
    plane.action();

    std::cout << "\nUnicorn (adapted from Plane):\n";
    unicorn.makeSound();
    unicorn.action();

    return 0;
}