#include <iostream>
#include <string>
using namespace std;
int main(){
    string dot=".";
    int j=0;
    while(j<=5){
        for(int i=0;i<j;i++){
            cout<<dot;
        }
        cout<<endl;
        j++;
    }
}