#include <iostream>
using namespace std;

struct rectangle  {
    int width,height;
};

int main() {
	
    rectangle rect1;
    rectangle *rect1ptr= &rect1;
    
     // using ->
    rect1ptr->width=44;
    rect1ptr->height=55;

   cout <<"The width and height of rectangle rect1 is :("<<rect1ptr->width<< " "<<rect1ptr->height<<")"<<endl;   
   // using (*ptr).
   rectangle rect2={66,77};
   rectangle *rect2ptr= &rect2;
       
   cout << "The width and height of rectangle rect2 is :("<<(*rect2ptr).width <<" "<<(*rect2ptr).height <<")"<< endl; 
   
    return 0;
}
