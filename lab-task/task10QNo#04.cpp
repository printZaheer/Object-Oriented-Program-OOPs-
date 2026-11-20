#include <iostream>
#include <string>
using namespace std;
class LoanAccount;
class SavingsAccount {
    string id;
    double balance;
public:
    SavingsAccount(string i, double b) {
        id = i;
        balance = b;
    }
    friend void auditCustomerRisk(SavingsAccount s, LoanAccount l);
};
class LoanAccount {
    string id;
    double loan;
    int missed;
public:
    LoanAccount(string i, double l, int m) {
        id = i;
        loan = l;
        missed = m;
    }
    friend void auditCustomerRisk(SavingsAccount s, LoanAccount l);
};
void auditCustomerRisk(SavingsAccount s, LoanAccount l) {
    if (s.id != l.id) {
        cout << "Different customers, cannot audit" << endl;
        return;
    }
    double score = 700;
    score = score + (s.balance / 1000) * 5;
    score = score - (l.loan / 1000) * 4;
    score = score - l.missed * 25;
    if (score > 850) score = 850;
    if (score < 300) score = 300;
    cout << "Customer " << s.id << " score = " << score << " risk = ";
    if (score >= 720) cout << "LOW" << endl;
    else if (score >= 620) cout << "MEDIUM" << endl;
    else cout << "HIGH" << endl;
}
int main() {
    SavingsAccount s1("C101", 25000);
    LoanAccount l1("C101", 8000, 0);
    SavingsAccount s2("C102", 1500);
    LoanAccount l2("C102", 40000, 4);
    SavingsAccount s3("C103", 5000);
    LoanAccount l3("C999", 1000, 0);
    auditCustomerRisk(s1, l1);
    auditCustomerRisk(s2, l2);
    auditCustomerRisk(s3, l3);
    return 0;
}
