#include <iostream>
using namespace std;
int addition(int num1,int num2){
    return num1+num2;
}
int subtraction(int num1,int num2){
    return num1-num2;
}
int multiplication(int num1,int num2){
    return num1*num2;
}
int divison(int num1,int num2){
    return num1/num2;
}
int main(){
    int num1,num2;
    cout<<" Enter two numbers to perform arithematic operations  :";
    cin>>num1>>num2;
    cout<<" \n The sum of given numbers is : "<<addition(num1,num2);
    cout<<" \n The diffrence of given numbers is : "<<subtraction(num1,num2);
    cout<<" \n The multiplication of given numbers is : "<<multiplication(num1,num2);
    cout<<" \n The division of given numbers is : "<<divison(num1,num2);
    return 0;
}
