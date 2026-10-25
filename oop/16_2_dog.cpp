#include<iostream>
using namespace std;
class Dog{
    public:
        Dog(string s){ //建構子:名字跟class一樣，沒有回傳型別
            setdogname(s);
        }
        void bark(){
            cout<<"汪汪!"<<endl;
        }
        void introduce(){
            cout<<"我是 "<<getdogname()<<endl;
        }
        void setdogname(string s){
            name=s;
        }
        string getdogname(){
            return name;
        }    
    private:
        string name;
};
int main(){
    Dog dog1("小白");
    Dog dog2("小黑");
    //dog1.name="小花"; 這樣打的話會報錯 因為Dog裡的name是宣告成private

    dog1.bark();
    dog1.introduce();
    dog2.introduce();
    dog1.introduce();
}