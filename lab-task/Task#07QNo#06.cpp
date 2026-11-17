#include<iostream>
using namespace std;

class Buffer{
	public:
		int id;
		int* arr;
		static int active;
	Buffer(int i, int size){
		id = i;
		arr = new int[size];
		active++;
		cout << "Buffer " << id << " created at " << arr << endl;
	}
	~Buffer(){
		cout << "Buffer " << id << " destroyed at " << arr << endl;
		delete[] arr;
		active--;
	}
};
int Buffer::active = 0;
int main(){
	for(int i = 1; i <= 2; i++){
		Buffer b(i, 5);
	}
	{
		Buffer b3(3, 5);
		Buffer b4(4, 5);
	}
	Buffer* p = new Buffer(5, 5);
	delete p;
	cout << "Active buffers: " << Buffer::active << endl;
	return 0;
}
