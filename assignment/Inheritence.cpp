#include <iostream>
using namespace std;
class Vehicle{
    string sound;
    public:
    void honk(){
        cout<<"\n\nKeenk keenkkk!!!!";
    }
};

class Car:public Vehicle{
    string model;
    public :
    void setModel(){
        model="XUV300";
        cout<<"\n\n The model is "<<model<<endl;
    }
};

int main(){
    Car myCar;
    myCar.honk();
    myCar.setModel();
    return 0;
}
