#include <iostream>
using namespace std;
int main(){
    int comp_marks,math_marks,sci_marks,total_marks;
    cout << "Enter your Computer Science Marks : ";
    cin>>comp_marks;
    cout << "Enter your Mathematics Marks : ";
    cin>>math_marks;
    cout << "Enter your Science Marks : ";
    cin>>sci_marks;
    total_marks=comp_marks+math_marks+sci_marks;
    cout<<"Your total marks is "<<total_marks;
    return 0;
}