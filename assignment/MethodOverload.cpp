#include <iostream>
using namespace std;
class Shape{
    int length,breadth;
    float radius;
    public:
    int area(int l,int b){
        length=l;
        breadth=b;
        cout<<"\n\nRectangle AREA   ";
        return length*breadth;
    }
    float area(float r){
        radius=r;
        cout<<"\n\ncircle AREA   ";
        return radius*radius*3.14f;
    }
    int area(int size){
        cout<<"\n\nSQUARE AREA   ";
        return size*size;
    }
};
int main(){
    Shape a1;
    cout<<a1.area(10)<<endl;
    cout<<a1.area(4.5f)<<endl;
    cout<<a1.area(10,20)<<endl;
    return 0;

}