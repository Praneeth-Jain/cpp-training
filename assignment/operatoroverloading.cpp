#include <iostream>
using namespace std;
class A{
    int value;
    public:
    A(int no){
        value=no;
    }

    A operator+(const A& other)const{
        return A(value+other.value);
    }

    A operator-(const A& other)const{
        return A(value-other.value);
    }

    void print ()const{
        cout<<value;
    }
};

int main(){
    A a1(20);
    A a2(15);

    A a3=a1+a2;
    A a4=a1-a2;
    cout<<"A1 + A2 = ";
    a3.print();
    cout<<endl;
    cout<<"A1 - A2 = ";
    a4.print();
    return 0;
}

