// destructors are used to deallocate the memory
// destructors will be automatically create the default destructors if not specified
// malloc calloc realloc are some of the dynamic memory allocaters


#include <iostream>
using namespace std;


class A{
    public:
    A(){
        cout<<"This is the constructor";
    }
    ~A(){
        cout<<"T\n\nhis is the destructor";
    }
};

int main(){
    A a;
    return 0;
}