#include<iostream>
using namespace std;

struct Book {
	string title ;
	string author;
	float price ;
};
	void displayBook(Book b){
	cout << "\n--- Book Details ---\n";
    cout << "Title : " << b.title << "\n";
    cout << "Author: " << b.author << "\n";
    cout << "Price : $" << b.price << "\n";
	}
int main (){
	Book b ;
	cout <<"Enter Title,Author and Price of the Book:  ";
	cin>>b.title>>b.author>>b.price;
	
	displayBook(b);

	return 0;
}


