#include<iostream>
using namespace std;
class RescueRobot{
    public:
    virtual void rescue()=0;
};
class FireRobot : public RescueRobot{
    public:
    void  rescue()override{
        cout << "FireRobot stoping the fire. "<<endl;
    }
};
class WaterRobot: public RescueRobot{
    public:
    void rescue()override{
        cout << "WaterRobot is rescusing people from flood."<<endl;
    }
};
class SearchRobot: public RescueRobot{
    public:
    void rescue ()override{
        cout << "SearchRobot is find the missing people"<<endl;
    }
};
int main(){
    FireRobot f;
    WaterRobot w;
    SearchRobot s;

    f.rescue();
    w.rescue();
    s.rescue();
    
    return 0;
}