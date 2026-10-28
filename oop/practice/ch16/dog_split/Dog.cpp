#include<string>
#include<iostream>
#include"Dog.h"
using namespace std;

Dog::Dog(string s){
    setdogname(s);
}
void Dog::bark(){
    cout<<"汪汪"<<endl;
}
void Dog::introduce(){
    cout<<"我是 "<<getdogname()<<endl;
}
void Dog::setdogname(string s){
    name=s;
}
string Dog::getdogname(){
    return name;
}