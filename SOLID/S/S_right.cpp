#include <iostream>
#include <string>
#include <fstream>
#include <memory>

// 1. Biological/Domain Entity (Only holds animal identity and state)
class Animal {
private:
    std::string name;
    std::string species;
    double weightKg;

public:
    Animal(std::string name, std::string species, double weightKg)
        : name(std::move(name)), species(std::move(species)), weightKg(weightKg) {}

    std::string getName() const { return name; }
    std::string getSpecies() const { return species; }
    double getWeight() const { return weightKg; }
};

// 2. Financial Service (Only handles dietary & cost calculations)
class FeedingCostCalculator {
public:
    double calculateDailyCost(const Animal& animal) const {
        if (animal.getSpecies() == "Lion") {
            return animal.getWeight() * 0.05 * 12.5;
        } else if (animal.getSpecies() == "Elephant") {
            return animal.getWeight() * 0.08 * 2.0;
        }
        return 10.0;
    }
};

// 3. Reporting Service (Only handles formatting and export operations)
class HealthReportExporter {
private:
    FeedingCostCalculator costCalculator_;

public:
    void exportToFile(const Animal& animal) const {
        std::cout << "=== HEALTH REPORT ===\n";
        std::cout << "Animal: " << animal.getName() << " (" << animal.getSpecies() << ")\n";
        std::cout << "Weight: " << animal.getWeight() << " kg\n";
        std::cout << "Daily Food Cost: $" << costCalculator_.calculateDailyCost(animal) << "\n";
    }
};