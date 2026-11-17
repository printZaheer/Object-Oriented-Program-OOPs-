#include<iostream>
#include<string>
using namespace std;

class Logger{
	public:
		string name;
		
	Logger(string nam){
		name = nam;
		cout << name << " object created" << endl;
	}
	~Logger(){
		cout << name << " object destroyed" << endl;
	}
};

void localfun(){
	Logger local("Local");
	cout << "Inside local Function" << endl;
}
int main () {
	Logger obj1("Object one");
	localfun();
	cout << "Inside main function" << endl;
	return 0;
}
