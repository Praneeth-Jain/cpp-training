#include <iostream>
#include <string>
using namespace std;
class Student{
    string firstName,lastName,usn,branch,gender;
    int age;

    public :
    Student(){
        cout<<"Student Object is created \n\n";
    }

    void getData(){
        cout<<"\n\nEnter the first and last name : ";
        cin>>firstName>>lastName;
        cout<<"\n\nEnter the USN  : ";
        cin>>usn;
        cout<<"\n\nEnter Your Branch : ";
        cin>>branch;
        cout<<"\n\nEnter the gender : ";
        cin>>gender;
        cout<<"\n\nEnter the Age : ";
        cin>>age;
    }
    void displayData(){
        cout<<"\n\n_______  Student Data _______________"<<endl;
        cout<<firstName<<" "<<lastName<<"\t"<<usn<<"\t"<<branch<<"\t"<<gender<<"\t"<<age;
    }
};


int main(){
    Student st;
    st.getData();
    st.displayData();
    return 0;
}
