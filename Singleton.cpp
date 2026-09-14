#include <iostream>

class BankAccount {
private:
    double balance;
    BankAccount() : balance(0.0) {} // Private constructor
public:
    static BankAccount& getInstance() {
        static BankAccount instance;
        return instance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << ", New Balance: $" << balance << "\n";
        } else {
            std::cout << "Deposit amount must be positive.\n";
        }
    }

    void getBalance() const {
        std::cout << "Current Balance: $" << balance << "\n";
    }
};

int main() {
    BankAccount& account = BankAccount::getInstance();
    account.deposit(100.0);
    account.getBalance();

    // Attempting to create another instance will return the same instance
    BankAccount& anotherAccount = BankAccount::getInstance();
    anotherAccount.deposit(50.0);
    anotherAccount.getBalance();

    return 0;
}