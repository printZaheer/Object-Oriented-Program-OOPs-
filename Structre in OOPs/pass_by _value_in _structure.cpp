#include <iostream>
using namespace std; 

struct point{
	int x,y;
};
//Passing by value 
void display(point p1,point p2){
	cout<<"You entered the following points:-\n";
	cout << "The point p1 is : ("<<p1.x<<","<<p1.y<<")"<<endl;
	cout << "The point p2 is : ("<<p2.x<<","<<p2.y<<")"<<endl;

}
//passing by refrence
void doubleCoordinates(point &p1) {
    p1.x *= 2;
    p1.y *= 2;
    cout << "The point p1 after modified is: ("<<p1.x<<","<<p1.y<<")"<<endl;
}

int main (){
	point p1= {2,4};
	point p2;
	cout <<"Enter the point p2 (x,y): ";
	cin >> p2.x>>p2.y;
	display(p1,p2);
	doubleCoordinates(p1);
	
	return 0;
	
}
