//Welcome screen
//user must be given with options
//recieve inputs from users


#include<iostream>
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
    int choice,num1,num2;
    choice=0;
    cout<<"\n\n\n___________  **** Welcome to the Arithem1atic Operations **** _____________"<<endl;
    while(choice!=5){
    cout<<"\n\nSelect Required Operations \n 1.Addition \n 2.Subtraction \n 3.Multiplication \n 4.Division  \n 5.Exit \n Enter Your Choice ....  ";
    cin>>choice;
    switch(choice){
        case 1:cout<<"\nEnter two numbers to add : ";
               cin>>num1>>num2;
               cout<<"\nThe sum of two numbers is "<<addition(num1,num2);
               break;
               
        case 2:cout<<"\nEnter two numbers to subtract : ";
               cin>>num1>>num2;
               cout<<"\nThe diffrence of two numbers is "<<subtraction(num1,num2);
               break;
               
        case 3:cout<<"\nEnter two numbers to multiply : ";
               cin>>num1>>num2;
               cout<<"\nThe product of two numbers is "<<multiplication(num1,num2);
               break;

        case 4:cout<<"\nEnter two numbers to divide : ";
               cin>>num1>>num2;
               cout<<"\nThe quotient of two numbers is "<<divison(num1,num2);
               break;
         case 5:cout<<"\n\n*---*---*_--*----*---*--- Thank you *---*---*_--*----*---*---";
                break;      
        default:cout<<"\nEnter proper choice !!!";
                break;              
    }
    }
    return 0;
}