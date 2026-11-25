//*********************Simple Compile time /Early binding  Polymorphism example ************************
#include<iostream>
using namespace std;
class Calculator{
public:
int multiply(int a,int b){
 return a*b;
}
double multiply (double a , double b){
    return a * b;
}
int multiply ( int a , int b , int c ){
    return a * b * c;
}

};
int main(){
    Calculator c;
    cout <<c.multiply(2,5)<< endl ;
    cout <<c.multiply(2.5,3.4)<< endl;
    cout << c.multiply(2,3,5)<<endl;
    return 0; 
}