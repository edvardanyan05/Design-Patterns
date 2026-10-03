#include <iostream>

class Game{
    private:
        AbstractEnemyFactory* enemyFactory = nullptr;
public:
    Game(bool level) {
        if(level){
            enemyFactory = new StrongEnemyFactory();
        }else{
            enemyFactory = new SilyEnemyFactory();
        }
    }

    void spawnEnemies() {
        Soldier* soldier = enemyFactory->createSoldier();
        Tank* tank = enemyFactory->createTank();
        Helicopter* helicopter = enemyFactory->createHelicopter();

        soldier->attack();
        tank->attack();
        helicopter->attack();

        delete soldier;
        delete tank;
        delete helicopter;
    }
};

//Base Enemy class
class Enemy{
protected:
    int health;
public:
    virtual void attack() = 0;
    virtual ~Enemy() = default;
};

//Concrete Enemy classes
class Soldier : public Enemy{
public:
    void attack() override {
        std::cout << "Soldier attacks with a rifle!" << std::endl;
    }
};
class Tank : public Enemy{
public:
    void attack() override {
        std::cout << "Tank attacks with a cannon!" << std::endl;
    }
};
class Helicopter : public Enemy{
public:
    void attack() override {
        std::cout << "Helicopter attacks with missiles!" << std::endl;
    }
};


//Sily Family of Enemies
class SilySoldier : public Soldier{
public:
    SilySoldier() {
        health = 100;
    }
};
class SilyTank : public Tank{
public:
    SilyTank() {
        health = 300;
    }
};
class SilyHelicopter : public Helicopter{
public:
    SilyHelicopter() {
        health = 200;
    }
};


//Strong Family of Enemies
class StrongSoldier : public Soldier{
public:
    StrongSoldier() {
        health = 200;
    }
};
class StrongTank : public Tank{
public:
    StrongTank() {
        health = 600;
    }
};
class StrongHelicopter : public Helicopter{
public:
    StrongHelicopter() {
        health = 400;
    }
};


//Abstract Factory Interface
class AbstractEnemyFactory{
public:
    virtual Soldier* createSoldier() = 0;
    virtual Tank* createTank() = 0;
    virtual Helicopter* createHelicopter() = 0;
    virtual ~AbstractEnemyFactory() = default;
};


//Concrete Factory for Sily Enemies
class SilyEnemyFactory : public AbstractEnemyFactory{
public:
    Soldier* createSoldier() override {
        return new SilySoldier();
    }
    Tank* createTank() override {
        return new SilyTank();
    }
    Helicopter* createHelicopter() override {
        return new SilyHelicopter();
    }
};

//Concrete Factory for Strong Enemies
class StrongEnemyFactory : public AbstractEnemyFactory{
public:
    Soldier* createSoldier() override {
        return new StrongSoldier();
    }
    Tank* createTank() override {
        return new StrongTank();
    }
    Helicopter* createHelicopter() override {
        return new StrongHelicopter();
    }
};



