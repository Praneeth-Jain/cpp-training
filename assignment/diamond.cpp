#include <iostream>
using namespace std;
class G{
    public:
    void display(){
        cout<<"\n G is called";
    }
};
class A:virtual public G{
    
};
class B:virtual public G{
    
};
class E:public A,B{
};

int main(){
    E e;
    e.display();
    return 0;
}