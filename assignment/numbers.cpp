#include <iostream>
#include <vector>
using namespace std;

int main(){
vector<int>numbers={0,1,2,3,4,5}; 
for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    std::cout << *it << std::endl;
}
vector <string>names={"Jay","Raghu","John","Veer"};
for (auto name=names.begin();name!=names.end();++name){
    cout<<*name<<endl;
}
}
