#include <iostream>
using namespace std;

class Calculator
{
private:
    int result;

public:
    void add(int a, int b);                   
    int getResult();                           
    void show(){                               // Inside Member Function which is defined inside
        cout << "Result: " << result << endl;
    }
};

void Calculator::add(int a, int b){           // Outside Member Function which is defined outside
    result = a + b;
}

int Calculator::getResult(){                  // Outside Member Function which is defined outside
    return result;
}

int main(){
    Calculator c;
    c.add(10, 5);                             
    c.show();
    int r = c.getResult();                    
    cout << "Returned Result is : " << r << endl;
    return 0;
}