#include <iostream>
#include <stdexcept>

// Fat Interface: Forces every worker to implement ALL zoo tasks
class IZooWorker {
public:
    virtual ~IZooWorker() = default;
    virtual void feedAnimals() = 0;
    virtual void cleanCages() = 0;
    virtual void performSurgery() = 0;
    virtual void sellTickets() = 0;
};

// Zookeeper only feeds animals and cleans cages
class Zookeeper : public IZooWorker {
public:
    void feedAnimals() override {
        std::cout << "Feeding lions and elephants...\n";
    }

    void cleanCages() override {
        std::cout << "Cleaning enclosure...\n";
    }

    // Forced to implement methods they can't do!
    void performSurgery() override {
        throw std::logic_error("Zookeepers cannot perform surgery!");
    }

    void sellTickets() override {
        throw std::logic_error("Zookeepers do not sell tickets!");
    }
};

// TicketSeller only sells tickets
class TicketSeller : public IZooWorker {
public:
    void feedAnimals() override { /* No implementation */ }
    void cleanCages() override { /* No implementation */ }
    void performSurgery() override { /* No implementation */ }

    void sellTickets() override {
        std::cout << "Selling entry ticket...\n";
    }
};