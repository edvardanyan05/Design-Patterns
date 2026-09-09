#include <iostream>
#include <string>
#include <vector>

enum class AnimalType { Dog, Cat, Cow };

class Animal {
public:
    AnimalType type;
};

class AnimalSoundPlayer {
public:
    void makeSounds(const std::vector<Animal>& animals) {
        for (const auto& animal : animals) {
            if (animal.type == AnimalType::Dog) {
                std::cout << "Woof!\n";
            } else if (animal.type == AnimalType::Cat) {
                std::cout << "Meow!\n";
            } else if (animal.type == AnimalType::Cow) {
                std::cout << "Moo!\n";
            }
        }
    }
};