#include <iostream>
#include <string.h>
using namespace std;

class animal
{
private:
    char gender;
    int babbies;

public:
    char name[50];
    int legs;
    int hands;
    void setData(char, int);
    void getData();
};

void animal ::setData(char gen, int bab)
{
    gender = gen;
    babbies = bab;
}

void animal ::getData()
{
    cout << name << ":\n";
    cout << "\t gender : " << gender;
    cout << "\t babbies : " << babbies;
    cout << "\t legs : " << legs;
    cout << "\t hands : " << hands;
}
int main()
{
    animal kangaroo, dog;
    kangaroo.hands = 2, kangaroo.legs = 2;
    strcpy(kangaroo.name, "Kangaroo");
    dog.hands = 0, dog.legs = 4;
    strcpy(dog.name, "Dog");
    kangaroo.setData('M', 3);
    dog.setData('F', 2);

    kangaroo.getData();
    cout << "\n";
    dog.getData();

    return 0;
}
