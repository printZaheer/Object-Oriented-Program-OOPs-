#include<iostream>
using namespace std;
class Area {
public:
int  area(int side ){
    return side *side ;
}
int  area (int lenght , int width ){
    return lenght* width ;    
}
double  area (double radius ){                  
return 3.14*radius*radius;
}
};

int main(){
    Area a ;
    cout<< "Square : "<< a.area(2)<<endl;
    cout << "Rectangle : "<< a.area(2,5)<< endl;
    cout << "Circle : "<< a.area(2.5)<< endl;

    return 0;
}