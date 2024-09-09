#include <iostream>
using namespace std;
class Car{
    int num;
    public:
    void setData(int num){
        this->num=num;
    } 
    void display(){
        cout<<this->num<<endl;
    }
};
int main(){
    Car c1,c2;
    c1.setData(10);
    c2.setData(20);
    c1.display();
    c2.display();
}