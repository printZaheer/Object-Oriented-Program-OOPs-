#include<iostream>
using namespace std;
class Complex{
private :
int real ; int img;
public:
Complex (){
    real=0;
    img=0;
}
Complex(int r , int i){
    real =r;
    img = i;
}
Complex operator + (Complex c ){
    Complex temp;
    temp.real = real+ c.real;
    temp.img = img + c.img;
    return temp;
}
void operator++(){
    real++;
    img++;
}
void show (){
    cout <<"The complex number after addition is : ";
    cout << real << "+"<< img<<"i"<< endl;
}
};
int main(){
    Complex c1(2,5),c2(3,4);
    Complex c3=c1+c2;
    c3.show ();
    ++c1;
    c1.show();

    return 0;
}