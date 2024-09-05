// create account,deposit,withdrawl,checkbalance
#include <iostream>
#include <cstdlib>
using namespace std;
class Bank{
    int balance,amount,accNo;
    string name;
    public:
    void createAccount(){
        balance=0;
        accNo*=rand();
        cout<<"\n\nAccount Created successfully \n Your Acc No is "<<accNo;
    }

    void deposit(){
        int dep_accNo,amt;
        cout<<"\n\nEnter your Account Number : ";
        cin>>dep_accNo;
        if(accNo!=dep_accNo){
            cout<<"\n\nThis account number is not recognised  !!!!!";
        }else{
            cout<<"\n\nEnter the Amount to be deposited  :";
            cin>>amt;
            if(amt>0){
                balance+=amt;
                cout<<"\n\nDeposit is Succesfull\n";
            }
            else{
                cout<<"Please Enter Positive Amount !!!";
            }
        }
    }

    void withdrawl(){
        int w_amt,w_accNo;
        cout<<"\n\nEnter your Account Number : ";
        cin>>w_accNo;
        if(accNo!=w_accNo){
            cout<<"\n\nThis account number is not recognised  !!!!!";
        }else{
        cout<<"\n\nEnter the amount to be withdrawed :  ";
        cin>>w_amt;
        if(w_amt<balance){
            balance-=w_amt;
            cout<<"\n\n Withdrawl is succesfull.....\n";
        }else{
            cout<<"\n\nYou do not have enough amount to be withdrawed ..!!! ";
        }
        }
    }

    void displayAcc(){
    cout<<"\n\nYour Account Number is  : "<<accNo<<"\nBalance : "<<balance;
    }
};
int main(){
    Bank b;
    int choice;
    choice=0;
    cout<<"\n\n__________ Welcome to Bank Application __________________";
    while(choice!=5){
    cout<<"\n\nEnter Your Choice \n 1.Create Account \n 2.Deposit \n 3.Withdrawl \n 4.Display Account  \n 5.Exit \n Enter Your Choice ....  ";
    cin>>choice;
    switch(choice){
        case 1:b.createAccount();
                break;
        case 2:b.deposit();
               break;
               
        case 3:b.withdrawl();
               break;

        case 4:b.displayAcc();
               break;
         case 5:cout<<"\n\n*---*---*_--*----*---*--- Thank you *---*---*_--*----*---*---";
                break;      
        default:cout<<"\nEnter proper choice !!!";
                break;              
    }
    }
}