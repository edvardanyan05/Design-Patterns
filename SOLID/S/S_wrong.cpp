#include <iostream>
#include <string>
#include <fstream>

class Animal {
private:
    std::string name;
    std::string species;
    double weightKg;

public:
    Animal(std::string name, std::string species, double weightKg)
        : name(std::move(name)), species(std::move(species)), weightKg(weightKg) {}

    // Responsibility 1: Domain/Biological Data
    std::string getName() const { return name; }
    double getWeight() const { return weightKg; }

    // Responsibility 2: Financial / Budgeting Logic
    double calculateDailyFoodCost() const {
        if (species == "Lion") {
            return weightKg * 0.05 * 12.5; // Meat cost per kg
        } else if (species == "Elephant") {
            return weightKg * 0.08 * 2.0;  // Hay/vegetable cost per kg
        }
        return 10.0;
    }

    // Responsibility 3: Reporting & File Formatting
    void exportHealthReportToFile() const {
        std::cout << "=== HEALTH REPORT ===\n";
        std::cout << "Animal: " << name << " (" << species << ")\n";
        std::cout << "Weight: " << weightKg << " kg\n";
        std::cout << "Daily Cost: $" << calculateDailyFoodCost() << "\n";
    }
};