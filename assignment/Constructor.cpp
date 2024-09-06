#include <iostream>
using namespace std;
class Test{
    public:
    Test(){
        cout<<"\n\nDefault Contructor is called  ";
    }
    Test(string name){
        cout<<"\n\nParameterized constructor is called , "<<name;
    }
};
int main (){
    Test t;
    Test t2("Vijay");
    return 0;
}