#include<iostream>
using namespace std;

class Book{
	private:
		string title;
		int pages;
	public:
	Book (){                        // default constructor
		title=" unknown";
		pages=0;
	}
	Book (string tit, int pag){  // paramertrize constructor
		title=tit;
		pages=pag;
	}
	void show(){
		cout << "Title: "<< title<<endl;
		cout << "Pages: "<< pages<<endl;
	}
};

 int main () {
 	Book b1;
 	Book b2("Eliot Alderson",200);
 	
 	b1.show();
	b2.show();
	
 	return 0;
 }
