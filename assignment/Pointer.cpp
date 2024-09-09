#include <iostream>
using namespace std;
int main(){
    int *myPtr;
    int x=10;
    myPtr=&x;
    cout<<"The variable x has a data : "<<x<<" and is stored in :  "<<myPtr;
    *myPtr*=100;
    cout<<endl<<*myPtr<<" "<<x;
    return 0;
}