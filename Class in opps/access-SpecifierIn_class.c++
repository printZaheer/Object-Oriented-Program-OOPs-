#include <iostream>
#include <string>
using namespace std;

class Account{
public:
    string owner;
    void setBalance(int b){
        balance = b;
    }
    void show(){
        cout << owner << " has " << balance << endl;
    }
private:
    int balance;                        //Private which cannor be access  or hidden from outside 
};

int main(){
    Account a1;
    a1.owner = "Zaheer";    //  public
    a1.setBalance(80000); // public function sets private data
    a1.show();
    // a1.balance = 100;     // ERROR: balance is private
    return 0;
}