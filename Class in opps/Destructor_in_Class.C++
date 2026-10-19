
#include <iostream>
#include <string>
using namespace std;

class Test
{
private:
    string name;

public:
    Test(string n){           // Paramaterize constructor 
        name = n;
        cout << "Constructor: " << name << endl;
    }
    ~Test(){                   // Destructor 
        cout << "Destructor: " << name << endl;
    }
};

int main()
{
    Test T1("A");
    Test T2("B");
    cout << "End of main" << endl;
    return 0;
}