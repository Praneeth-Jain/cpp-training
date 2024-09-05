#include <iostream>
using namespace std;
class Myclass{
    public:
    int x;
    void setX();
};
void Myclass::setX(){
    x=10;
    cout<<x;
}
int main(){
    Myclass m;
    m.setX();
}