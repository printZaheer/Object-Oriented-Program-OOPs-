#include<iostream>
using namespace std;

class Item{
	private:
		double price;
		int quantity;
		
	public:
	Item(double p, int q){
		price = p;
		quantity = q;
	}
	void show(){
		cout << "Price: " << price << ", Quantity: " << quantity << endl;
	}
};
int main(){
	Item items[3] = { Item(10.5, 2), Item(20.0, 5), Item(7.25, 10) };

	for(int i = 0; i < 3; i++){
		items[i].show();
	}
	return 0;
}
