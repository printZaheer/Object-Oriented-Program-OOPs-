#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance;
    bool isValidAmount(double amount){
        return amount > 0;
    }

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance){}

    void deposit(double amount){
        if (isValidAmount(amount))
        {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        }
        else
        {
            cout << "Deposit failed: $" << amount << " is not a valid amount.\n";
        }
    }
    void withdraw(double amount){
        if (!isValidAmount(amount))
        {
            cout << "Withdrawal failed: $" << amount << " is not a valid amount.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Withdrawal failed: insufficient funds (balance: $" << balance << ").\n";
            return;
        }
        balance -= amount;
        cout << "Withdrew $" << amount << " New balance: $" << balance << endl;
    }
    double getBalance() const{
        return balance;
    }
};

int main()
{
    BankAccount acc(1000.0);
    cout << "Starting balance: $" << acc.getBalance() << "\n";
    acc.deposit(500.0);
    acc.withdraw(200.0);
    acc.deposit(-50.0);
    acc.withdraw(0.0);
    acc.withdraw(100000.0);
    cout << "\nFinal balance: $" << acc.getBalance() << endl;
    return 0;
}