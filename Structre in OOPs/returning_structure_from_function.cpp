#include <iostream >
using namespace std;

struct point {
	int x,y;
};
point makepoint(int a,int b){
	point temp;
	temp.x=a;
	temp.y=b; 
	return temp;
}

int main() {
    point p1 = makepoint(3, 4);
    cout <<"The returning point is :("<<p1.x << " ," << p1.y <<")"<< endl;
    return 0;
}
