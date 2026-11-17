#include <iostream>
#include <string>
using namespace std;
class Wallet {
private:
    double balance;
public:
    Wallet(double b) : balance(b) {}
    friend void transferFunds(Wallet &from, Wallet &to, double amount);
    void show(string name) const {
        cout << name << " balance: " << balance << endl;
    }
};
void transferFunds(Wallet &from, Wallet &to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transfer done" << endl;
    } else {
        cout << "Transfer failed" << endl;
    }
}
int main() {
    Wallet w1(500), w2(200);
    w1.show("w1");
    w2.show("w2");
    transferFunds(w1, w2, 100);
    w1.show("w1");
    w2.show("w2");
    return 0;
}
