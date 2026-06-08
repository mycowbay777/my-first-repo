#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int doom[]={-1,10,21,7,4,9,6,11,8,5,10,7,12};
    string day[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int t;
    cin>>t;
    while(t--){
        int m,d;
        cin>>m>>d;
        int dd=(d-doom[m])%7;
        if(dd>=0){
            cout<<day[dd]<<endl;
        }
        else{
            cout<<day[dd+7]<<endl;
        }
    }
}