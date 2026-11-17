#include <iostream>
#include <string>
using namespace std;
class Account {
private:
    string owner;
    double balance;
public:
    Account(string o, double b) : owner(o), balance(b) {}
    string getOwner() const { return owner; }
    double getBalance() const { return balance; }
    void setBalance(double b) { balance = b; }
};
int main() {
    const Account myAccount("Alice", 1500.75);
    cout << myAccount.getOwner() << " " << myAccount.getBalance() << endl;
   
    return 0;
}
