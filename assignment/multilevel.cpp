#include <iostream>
using namespace std;
class Parent{
    public:
    Parent(){
        cout<<"\n\n This is the parent class \n\n";
    }
    };

class FirstChild:public Parent{
    public :
    FirstChild(){
        cout<<"\n\nThis is the first Child\n\n";
    }
};

class SecondChild:public FirstChild{
    public :
    SecondChild(){
        cout<<"\n\nThis is the second Child\n\n";
    }
};

int main(){
    SecondChild s;
}