#include <iostream>
using namespace std;
int main(){
    int i;
    int num=0;
    cout<<"Enter the number for which you need the multiples till 100 : ";
    cin>>num;
    for(i=1;i<101;i++){
        if(i%num!=0){
            continue;
        }
        else{
            cout<<endl<<i;
        }
    }
}