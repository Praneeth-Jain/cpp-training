#include <iostream>
using namespace std;
int main(){
    string dot,space;
    dot=".";
    space=" ";
    int height=5;
    int i,j,k;

    for(i=height;i>=1;i--){
        for(j=height-i;j>=1;j--){
            cout<<space;
        }
        for(k=(2*i)-1;k>=1;k--){
            cout<<dot;
        }
        cout<<endl;
    }

    for(i=2;i<=height;i++){
        for(j=1;j<=height-i;j++){
            cout<<space;
        }
        for(k=1;k<=(2*i)-1;k++){
            cout<<dot;
        }
        cout<<endl;
    }
    return 0;
}