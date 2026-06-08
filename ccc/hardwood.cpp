#include<iostream>
#include<iomanip>
#include<string>
#include<map>
using namespace std;
int main(){
    int t;
    int first=1;
    string s;
    cin>>t;
    getline(cin,s);
    getline(cin,s);
    while(t--){
        if(first!=1) cout<<'\n';
        first++;
        map<string,int> mp;
        int sum=0;
        while(getline(cin,s)&&s!=""){
            mp[s]++;
            sum++;
        }
        for(auto i:mp){
            cout<<i.first<<" "<<fixed<<setprecision(4)<<(double)i.second/sum*100<<'\n';
        }
    }
}