#include <iostream>
using namespace std;

class Base {
public:
     virtual void display() const {
        cout << "Base display()" <<endl;
    }
};

class Derived : public Base {
public:
    void display() const override{
        cout << "Derived display()" << endl;
    }
};


int main(){
    Derived d;
    d.display();
}