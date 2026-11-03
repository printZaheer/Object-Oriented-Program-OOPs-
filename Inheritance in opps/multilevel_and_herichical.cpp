#include <iostream>
using namespace std;

class Animal{
public:
    void eat() {
        cout << "Eating" << endl;
    }
};

class Dog : public Animal{                       //Single inheritance 
public:
    void bark() {
        cout << "Barking" << endl;
    }
};

class Puppy : public Dog{                           // Multilevel inheritance
public:
    void weep() {
        cout << "Weeping" << endl;
    }
};

class Cat : public Animal{                         // Hierarchical inheritance
public:
    void meow() {
        cout << "Meowing" << endl;
    }
};

int main(){
    Puppy p;
    p.eat(); 
    p.bark(); 
    p.weep(); 

    Cat c;
    c.eat(); 
    c.meow();
    return 0;
}