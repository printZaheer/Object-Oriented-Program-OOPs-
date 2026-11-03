#include <iostream>
using namespace std;

class Base{
private:
    int a;
protected:
    int b;
public:
    int c;
    Base(){
        a = 10;
        b = 20;
        c = 30;
    }
};

class PubDerived : public Base{
public:
    void show() {
        cout << "b= " << b << " c= " << c << endl;
    }
};
class PrivDerived : private Base{
public:
    void show() {
        cout << "b=" << b << " b=" << b << endl;
    }
};
int main(){
    PubDerived p;
    cout << p.c << endl; 
    p.show();

    PrivDerived q;
    q.show(); 
    return 0;
}