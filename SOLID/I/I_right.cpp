#include <iostream>

class IFeedingWorker {
public:
    virtual ~IFeedingWorker() = default;
    virtual void feedAnimals() = 0;
};

class ICleaningWorker {
public:
    virtual ~ICleaningWorker() = default;
    virtual void cleanCages() = 0;
};

class ISurgeryWorker {
public:
    virtual ~ISurgeryWorker() = default;
    virtual void performSurgery() = 0;
};

class ITicketSellingWorker {
public:
    virtual ~ITicketSellingWorker() = default;
    virtual void sellTickets() = 0;
};

// Zookeeper only feeds animals and cleans cages
class Zookeeper : public IFeedingWorker, public ICleaningWorker {
public:
    void feedAnimals() override {
        std::cout << "Feeding lions and elephants...\n";
    }

    void cleanCages() override {
        std::cout << "Cleaning enclosure...\n";
    }
};

// TicketSeller only sells tickets
class TicketSeller : public ITicketSellingWorker {
public:
    void sellTickets() override {
        std::cout << "Selling entry ticket...\n";
    }
};