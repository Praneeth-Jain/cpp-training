#include <iostream>
using namespace std;
class Employee{
    protected:
    int id;
    double salary;
    string name;
    float bonus,base;
    public:

    Employee(int id,string name){
        this->id=id;
        this->name=name;
        salary=0;
    }


    virtual void getInfo(){
        cout<<"\nEmployee Details"<<endl;
        cout<<"\nName : "<<name<<"  Id : "<<id<<" salary : "<<salary;
    }

    virtual void displaySalary(){
        cout<<"\nEmployee Salary is  "<<salary<<endl;
    }

    virtual void calculateSalary(){
        bonus=0.05;
        base=10000;
        salary=base+(bonus*base);
        displaySalary();
    }
};


class Manager:public Employee{
  public :
  Manager(int id,string name):
    Employee(id,name){
        salary=0;
    }

  void calculateSalary() override{
    bonus=0.15;
    base=40000;
    salary=base+(bonus*base);
    displaySalary();
  }  
};

class Engineer:public Employee{
    public :
    Engineer(int id,string name):Employee(id,name){
    salary=0;
   } 

   void calculateSalary() override{
    bonus=0.10;
    base=25000;
    salary=base+(bonus*base);
    displaySalary();    
   }
};

class Intern:public Employee{
    public :
    Intern(int id,string name):Employee(id,name){
    salary=0;
   } 

    void calculateSalary ()override{
    bonus=0;
    base=15000;
    salary=base+(bonus*base);
    displaySalary();    
   }
};

class UI{
    int choice,choice_id;
    string choice_name;
    public:

    void userMenu(Employee &Emp){
        int user_choice;
        while(user_choice!=3){
        cout<<"\n\n ====== Welcome =====";
        cout<<"\n\n1.Get My Salary\n2.Get my Details \n3.Exit \n";
        cin>>user_choice;
        switch(user_choice){
            case 1:
            Emp.calculateSalary();
            break;
            case 2:
            Emp.getInfo();
            break;
            case 3:
            cout<<"\nThank you.....\n";
            break;
            default:cout<<"\n\nEnter valid option\n\n";
            break;
        }
        }
    }
    


    void startMenu(){
        cout<<"\n________________ Welcome to Employee Portal ___________\n";
        while(choice!=5){
        cout<<"1.Manager \n2.Engineer \n3.Intern \n4.Others \n5.Exit \n";
        cout<<"\n\nEnter your Choice : ";
        cin>>choice;
        if(choice!=5){
        choice_name=getName();
        choice_id=getID();
        }
        
        switch(choice){
            case 1:{
            Manager m(choice_id,choice_name);
            userMenu(m);
            break;
            }
            case 2:{
            Engineer e(choice_id,choice_name);
            userMenu(e);
            break;
            }
            case 3:{
            Intern i(choice_id,choice_name);
            userMenu(i);
            break;
            }
            case 4:{
            Employee e(choice_id,choice_name);
            userMenu(e);
            break;
            }
            case 5:
            {
                cout<<"\n..Thank you...  exiting....\n ";
                break;
            }
            default:{
                cout<<"\n\nSorry Employee type not found \n\n";
            break;}
        }
    }
    }

    string getName(){
        string emp_name;
        cout<<"\nEnter Your name :  ";
        cin>>emp_name;
        return emp_name;
    }

    int getID(){
        int emp_id;
        cout<<"\nEnter Your ID :  ";
        cin>>emp_id;
        return emp_id;
    }
    
};


int main(){
    UI u;
    u.startMenu();
    return 0;
}