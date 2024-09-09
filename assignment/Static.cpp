// static is used when a data is shared bw diff class so that we can use it

#include<iostream>
using namespace std;

// class Bus{
//     public :
//     static int count;

// };

// int Bus::count=0;

class Bus{
    public:
    static int count;
    void static hello(){
        cout<<"\n\nHello im  static method\n";
    }
};

class Car{
    int Ccount=Bus::count;
    public:
    void display(){
        cout<<endl<<++Ccount;
    }
};


int Bus::count=0;

int main(){
    Bus b1,b2;
    b1.count++;
    b2.count++;
    Bus::hello();
    cout<<Bus::count;
    Car c;
    c.display();
}

//therefore static members can be used in other class 