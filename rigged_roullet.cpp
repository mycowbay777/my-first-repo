#include <iostream>      
#include <string>        
#include <vector>        
#include <cstdint>      
#include <chrono>     
#include <type_traits>
using namespace std;
template<typename T,std::enable_if_t<std::is_integral_v<T>&&std::is_unsigned_v<T>,bool> =true>
bool parity(T n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n = n & (n - 1);
    }
    return parity;
}

void lfsr(std::uint32_t &value, const std::uint32_t mask = 0x8020'0003)
{
    value=(value << 1) | (uint32_t) parity(value & mask);
}

template <typename T>
T& rigged_sample(vector<T>& vec,uint32_t& state){
    lfsr(state);
    if(vec.size()==1){
        return vec[0];
    }
    if((state & 1)==1){
        return vec[0];
    }
    size_t num=1+((state>>1)%(vec.size()-1));
    return vec[num];
}

int main(){
    string s;
    vector<string> unit;
    cout<<"請輸入選項(每行一個，輸入空白行結束)"<<endl;
    auto start = chrono::high_resolution_clock::now();
    while(getline(cin,s)&& !s.empty()){
        unit.push_back(s);
    }
    auto end = chrono::high_resolution_clock::now();
    auto x=chrono::duration_cast<chrono::milliseconds>(end-start).count();
    
    std::uint32_t state = 0xdead'beef;
    for(long long i=0;i<x;i++){
        lfsr(state);
    }
    cout<<"x = "<<x<<", state = "<<state<<endl;
    if(unit.empty()){
        cout << "沒有輸入任何選項" << endl;
        return 0;
    }
    cout<<"抽中: "<<rigged_sample(unit,state)<<endl;
}
