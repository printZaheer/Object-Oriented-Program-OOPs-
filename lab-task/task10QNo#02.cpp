#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class PaymentGateway {
protected:
    string* logs;
    int size;
    int count;
public:
    PaymentGateway(int s) {
        size = s;
        count = 0;
        logs = new string[size];
        cout << "PaymentGateway constructor" << endl;
    }
    virtual void pay(double amount) = 0;
    void addLog(string text) {
        if (count < size) {
            logs[count] = text;
            count++;
        }
    }
    void showLogs() {
        for (int i = 0; i < count; i++) {
            cout << logs[i] << endl;
        }
    }
    virtual ~PaymentGateway() {
        delete[] logs;
        cout << "PaymentGateway destructor" << endl;
    }
};
class CreditCardPayment : public PaymentGateway {
    string* cardLogs;
public:
    CreditCardPayment(int s) : PaymentGateway(s) {
        cardLogs = new string[s];
        cout << "CreditCardPayment constructor" << endl;
    }
    void pay(double amount) {
        ostringstream s;
        s << "Paid " << amount << " by credit card";
        addLog(s.str());
        cardLogs[0] = "card approved";
    }
    ~CreditCardPayment() {
        delete[] cardLogs;
        cout << "CreditCardPayment destructor" << endl;
    }
};
class PayPalPayment : public PaymentGateway {
    string* tokenLogs;
public:
    PayPalPayment(int s) : PaymentGateway(s) {
        tokenLogs = new string[s];
        cout << "PayPalPayment constructor" << endl;
    }
    void pay(double amount) {
        ostringstream s;
        s << "Paid " << amount << " by paypal";
        addLog(s.str());
        tokenLogs[0] = "token created";
    }
    ~PayPalPayment() {
        delete[] tokenLogs;
        cout << "PayPalPayment destructor" << endl;
    }
};
int main() {
    PaymentGateway* p1 = new CreditCardPayment(5);
    PaymentGateway* p2 = new PayPalPayment(5);
    p1->pay(100);
    p2->pay(250);
    p1->showLogs();
    p2->showLogs();
    delete p1;
    delete p2;
    return 0;
}
