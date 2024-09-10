#include <iostream>
using namespace std;
class A{
    int a=10;
    protected :int b=20; 
};

class B:public A{
};

class C:public B{
    public:
    void display(){
        cout<<b;
    }
};

int main(){
    C b;
    b.display();
    return 0;
}

