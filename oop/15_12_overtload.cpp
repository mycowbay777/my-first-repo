#include<bits/stdc++.h>
using namespace std;

void describe(int x){
    cout<<x<<endl;
}
void describe(double x){
    cout<<x<<endl;
}
void describe(string s){
    cout<<s<<endl;
}
int main(){
    describe(42);
    describe(3.14);
    describe("hello");
}