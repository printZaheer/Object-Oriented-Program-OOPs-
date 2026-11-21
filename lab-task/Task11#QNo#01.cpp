#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
class CurrencyAmount {
    string currencyCode;
    double amount;
public:
    CurrencyAmount(string code, double amt) {
        currencyCode = code;
        amount = amt;
    }
    CurrencyAmount operator+(const CurrencyAmount& rhs) const {
        if (this->currencyCode != rhs.currencyCode) {
            cout << "Error: currency mismatch" << endl;
            return CurrencyAmount("ERR", 0.0);
        }
        return CurrencyAmount(currencyCode, amount + rhs.amount);
    }
    CurrencyAmount operator-(const CurrencyAmount& rhs) const {
        if (this->currencyCode != rhs.currencyCode) {
            cout << "Error: currency mismatch" << endl;
            return CurrencyAmount("ERR", 0.0);
        }
        return CurrencyAmount(currencyCode, amount - rhs.amount);
    }
    CurrencyAmount& operator+=(const CurrencyAmount& rhs) {
        if (currencyCode == rhs.currencyCode) amount += rhs.amount;
        else cout << "Error: currency mismatch" << endl;
        return *this;
    }
    bool operator==(const CurrencyAmount& rhs) const {
        return currencyCode == rhs.currencyCode && fabs(amount - rhs.amount) < 0.001;
    }
    friend ostream& operator<<(ostream& out, const CurrencyAmount& c) {
        out << "[" << c.currencyCode << " " << fixed << setprecision(2) << c.amount << "]";
        return out;
    }
};
int main() {
    string code;
    double amt;
    cout << "Wallet 1 (code amount): ";
    cin >> code >> amt;
    CurrencyAmount w1(code, amt);
    cout << "Wallet 2 (code amount): ";
    cin >> code >> amt;
    CurrencyAmount w2(code, amt);
    cout << "Wallet 3 (code amount): ";
    cin >> code >> amt;
    CurrencyAmount w3(code, amt);
    cout << "w1 + w2 = " << w1 + w2 << endl;
    cout << "w1 - w2 = " << w1 - w2 << endl;
    cout << "w1 + w3 = " << w1 + w3 << endl;
    cout << "w1 == w2: " << (w1 == w2) << endl;
    (w1 += w2) += w3;
    cout << "w1 after += w2 and += w3: " << w1 << endl;
    return 0;
}
