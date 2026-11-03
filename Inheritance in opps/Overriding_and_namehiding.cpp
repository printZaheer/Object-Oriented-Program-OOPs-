#include <iostream>
using namespace std;

class Animal
{
public:
    void makeSound(){
        cout << "Animal makes a sound." << endl;
    }

    void eat(){
        cout << "Animal is eating." << endl;
    }
};

class Dog : public Animal
{
public:
                                            // Function overriding
    void makeSound(){
        cout << "Dog barks." << endl;
    }

                                                 // Name hiding
    void eat(string food){
        cout << "Dog is eating " << food << "." << endl;
    }
};

int main(){
    Dog dog;

    dog.makeSound();
    dog.eat("meat");
    dog.Animal::eat();

    return 0;
}