// 3 student details should be taken
// display in tabular format
// name | usn | stream | sub1 | sub2 | ... sub 5 | total | average | result |

#include <iostream>
#include <string>
using namespace std;
class Student{
public : 
    string name,usn,res;
    int sub1,sub2,sub3,sub4,sub5,total,avg;

    void getData(){
        cout<<"\n\nEnter the name : ";
        cin>>name;
        cout<<"\n\nEnter the USN : ";
        cin>>usn;
        sub1=getMarks("Science");
        sub2=getMarks("Maths");
        sub3=getMarks("Computer");
        sub4=getMarks("English");
        sub5=getMarks("Hindi");
    }
    int getMarks(string sub){
        int marks;
        do{
        cout<<"\n\nEnter the marks of "<<sub<<" : ";   
        cin>>marks;
        if(!isValid(marks)){
            cout<<"\n\nPlease input proper marks !!!!";
        }
        }while(!isValid(marks));
        return marks;
    }

    void getAverage(){
        total=sub1+sub2+sub3+sub4+sub5;
        avg=total/5;
    }
    void getResult(){
        if(avg>=85){
            res="Distinction";
        }else if(avg<85 && avg>=60){
            res="first class";
        }else if(avg<60 && avg>=50){
            res="Second class";
        }else if(avg<50 && avg>=35){
            res="Third Class";
        }else{
            res="Fail";
        }
    }
    void display(){
        cout<<"\n\n"<<name<<"\t\t"<<usn<<"\t"<<sub1<<"\t"<<sub2<<"\t"<<sub3<<"\t"<<sub4<<"\t"<<sub5<<"\t"<<avg<<"\t"<<res;

    }
    bool isValid(int mark){
        if(mark>=0 && mark<=100){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Student st1,st2,st3;
    cout<<"\n\n Enter Student 1 detail :";
   
    st1.getData();
    st1.getAverage();
    st1.getResult();
    
    cout<<"\n\n Enter Student 2 detail :";
    
    st2.getData();
    st2.getAverage();
    st2.getResult();
    
    cout<<"\n\n Enter Student 3 detail :";

    st3.getData();
    st3.getAverage();
    st3.getResult();

    cout<<"\n\n\n |  Name  |  USN  |  Sci |  Maths  |  Eng  |  Comp |  Social |  Average |  Result | \n";
    st1.display();
    st2.display();
    st3.display();

    return 0;
}