#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Prototype Base Class
class Enemy {
protected:
    std::string name;

public:
    Enemy(const std::string& name) : name(name) {}
    virtual ~Enemy() = default;

    // Pure virtual clone method
    virtual std::unique_ptr<Enemy> clone() const = 0;
    virtual void attack() const = 0;
};

// 1st Instance Orc Class
class Orc : public Enemy {
private:
    int weaponDamage;

public:
    Orc(const std::string& name, int weaponDamage) 
        : Enemy(name), weaponDamage(weaponDamage) {}

    // Copy Constructor
    Orc(const Orc& other) : Enemy(other.name), weaponDamage(other.weaponDamage) {
        std::cout << "Copy Constructor - " << name << "\n";
    }

    // Clone method that calls the copy constructor
    std::unique_ptr<Enemy> clone() const override {
        return std::make_unique<Orc>(*this);
    }

    void attack() const override {
        std::cout << "Orc (" << name << ") attacks with its weapon (Damage: " << weaponDamage << ")\n";
    }
};

// 2nd Instance Goblin Class
class Goblin : public Enemy {
private:
    int speed;

public:
    Goblin(const std::string& name, int speed) 
        : Enemy(name), speed(speed) {}

    // Copy Constructor
    Goblin(const Goblin& other) : Enemy(other.name), speed(other.speed) {
        std::cout << "Copy Constructor - " << name << "\n";
    }

    // Clone method that calls the copy constructor
    std::unique_ptr<Enemy> clone() const override {
        return std::make_unique<Goblin>(*this);
    }

    void attack() const override {
        std::cout << "Goblin (" << name << ") throws a throwing axe! (Speed: " << speed << ")\n";
    }
};

// Enemy spawner function
std::unique_ptr<Enemy> spawnDuplicate(const Enemy& prototype) {
        return prototype.clone();
}


int main() {
    auto baseOrc = std::make_unique<Orc>("Ork", 50);
    auto baseGoblin = std::make_unique<Goblin>("Goblin", 100);

    std::cout << "--- Cloning ---\n\n";

    auto clonedOrc = spawnDuplicate(*baseOrc);
    auto clonedGoblin = spawnDuplicate(*baseGoblin);

    std::cout << "\n--- Results ---\n";
    clonedOrc->attack();
    clonedGoblin->attack();

    return 0;
}