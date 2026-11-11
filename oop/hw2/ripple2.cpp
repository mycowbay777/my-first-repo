#include<iostream>
#include<stdexcept>
#include"ripple2.h"

Ripple2::Ripple2(){}
void Ripple2::reset(State s){
    ff0_.reset(s);
    ff1_.reset(s);
}
void Ripple2::en(State  s){
    ff0_.en(s);
    ff1_.en(s);
}
State Ripple2::count(unsigned i){
    if(i==0) return ff0_.q();
    if(i==1) return ff1_.q();
    else throw std::invalid_argument("count index must be 0 or 1");
}
void Ripple2::print(){
    if(ff1_.q()==State::H) std::cout<<"1";
    else std::cout<<"0";
    if(ff0_.q()==State::H) std::cout<<"1";
    else std::cout<<"0";
    std::cout<<std::endl;
}
void Ripple2::clk(State s){
    ff0_.d(ff0_.qb());
    ff1_.d(ff1_.qb());
    ff0_.clk(s);
    ff1_.clk(ff0_.qb());
}