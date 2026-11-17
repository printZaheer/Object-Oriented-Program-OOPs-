#include<iostream>
using namespace std;

class Counter{
	public:
		static int count;

	Counter(){
		count++;
	}
	~Counter(){
		count--;
	}
	static int getCount(){
		return count;
	}
};

int Counter::count = 0;

int main(){
	cout << "Before: " << Counter::getCount() << endl;
	Counter c1;
	Counter c2;
	cout << "After c1, c2: " << Counter::getCount() << endl;
	{
		Counter c3;
		Counter c4;
		cout << "Inside nested scope: " << Counter::getCount() << endl;
	}
	cout << "After nested scope: " << Counter::getCount() << endl;
	return 0;
}
