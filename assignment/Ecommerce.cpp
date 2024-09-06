// user and admin 
// 1 admin and n customers 
//login functionality

#include <iostream>
#include <string>
using namespace std;


class Customers{
    int pass,id;
    string name;
    bool isAdmin;

    public:
    Customers(){
        isAdmin=false;
    }
    Customers(int id,int pass){
        if(id==1&&pass==1221){
            isAdmin=true;
            cout<<"\n\n Hello Admin  \n";
        }else{
            isAdmin=false;
        }
    }

    void createAcc(){
        cout<<"\nEnter your Name : ";
        cin>>name;
        cout<<"\nEnter your pass :";
        cin>>pass;
        id=(rand()+rand());
        cout<<"\n Account created Successfully \n Welcome to our APP  "<<name<<" your id is "<<id;
    }

    void myAcc(){
        cout<<"\n Hello , "<<name<<" your id is "<<id;
    }

};

class Product{
    int no_of_product,price;
    string prod_name;
    public:
    Product(){
        prod_name="Choclate";
        no_of_product=20;
        price=300;
    }

    void getProducts(){
        cout<<"\nProducts Available\n";
        cout<<prod_name<<"\t"<<no_of_product<<"\t"<<"$ "<<price<<" per each\n\n";
    }
};

int main(){
    int auth_choice,log_choice,log_id,log_pass;
    auth_choice=0;
    cout<<"\n\n__________E-Commerce Application________________\n\n";
    while(auth_choice!=3){
        cout<<"\n\n 1.Login \n2.Create Account  \nEnter your Choice";
        cin>>auth_choice;
        switch(auth_choice){
            case 1:
            cout<<"\n\n Login Menu \n\n";
            cout<<"\n 1.Admin \n 2.User";
            cin>>log_choice;
            switch(log_choice){
                case 1:
                cout<<"\n Enter Your id and password  : ";
                cin>>log_id>>log_pass;
                if(log_id==1&&log_pass==1221){
                    Customers c(log_id,log_pass);
                }
                else{
                    cout<<"\nThe id and pass details are incorrect\n";
                }
                break;
                // case 2:Customers c;
                // c.createAcc();
                // c.myAcc();
                // break;
                default:break;
            }
            case 2:Customers c;
            c.createAcc();
            c.myAcc();

    
            default:
                break;
            }
        }
    }



