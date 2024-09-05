#include <iostream>
using namespace std;
int main(){
    string dot,space;
    dot=".";
    space="\t";
      int k=5;
    while(k>=0){
        for(int i=0;i<k;i++)
        {
            cout<<"-";
        }
        int j=0;
    while(j<=5){
        int p=4;
        while(p>=0){
            for(int i=4;i<=0;i--){
                cout<<space;
            }
            p--;
        }
        for(int i=0;i<j;i++){
            cout<<dot;
        }
        cout<<endl;
        j++;
    }
        cout<<endl;
        k--;
    }
    
}