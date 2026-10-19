#include<iostream>
using namespace std;
class Computer{
    public:
    class CPU{
        public:
        void run (){
            cout << "Cpu running"<< endl ;
        }
    };
    void start(){
        CPU c;
        c.run();
        cout << "Computer starting "<<endl;
    }
};
int main(){
    Computer pc;
    pc.start();

    Computer::CPU cpu;
    cpu.run();
    return 0;
}