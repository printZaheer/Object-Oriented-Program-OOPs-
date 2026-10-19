#include<iostream>
using namespace std;

class Array {
    private:
    int arr[5];
    public:
    void fill();
    void show();
    int max();
    int min();
};
void Array :: fill(){
    for(int i =0 ;i<5 ; i++){
        cout << "Enter arr["<<i<<"] : ";
        cin >> arr[i];
    }
}
void Array :: show(){
    for (int i =0 ; i<5 ; i++){
        cout <<"arr["<<i<<"]: "<<arr[i]<<endl;
    }
}
int Array:: max(){
    int max = arr[0];
    for(int i=0; i<5 ;i++){
        if (max<arr[i])
        max=arr[i];
    }
    return max;
}
int Array :: min(){
    int min = arr[0];
    for(int i=0; i<5;i++){
        if (min>arr[i])
        min=arr[i];
    }
    return min;
}

int main(){
    Array A1;
    A1.fill();
    cout <<"You enter the following values: "<< endl;
    A1.show();
   cout<< "The Maximum Value is : "<<A1.max()<<endl;
   cout<< "The Minimum Value is : "<< A1.min()<<endl;
    return 0;
}