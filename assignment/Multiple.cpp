#include <iostream>
using namespace std;
class Parent1{
    public : 
    Parent1(){
        cout<<"\n Hello im parent 1 \n";
    }
};
class Parent2{
    public : 
    Parent2(){
        cout<<"\n Hello im parent 2 \n";
    }
};
class Child:public Parent1,Parent2{
    public : 
    Child(){
        cout<<"\n Hello im child of parent  1  and 2 \n";
    }
};

int main(){
    Child c;
}