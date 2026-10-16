#include<iostream>
using namespace std;
class dog{
    public:
    void bark(){
        cout<<"汪汪!"<<endl;
    }
    void introduce(string s){
        cout<<"我是 "<<s<<endl;
    }
};
int main(){
    dog dog1;
    dog dog2;
    dog1.bark();
    dog1.introduce("小白");
    dog2.introduce("小黑");
}