#include "counter.h"
#include <iostream>
#include <stdexcept>

Counter::Counter() {}

void Counter::reset(State s) {
    if(s==State::Z){
        throw std::invalid_argument("RESET cannot be Z");
    }
    reset_=s;
    if(s==State::H){
        value_=0;
    }
}

void Counter::en(State s) {
    if(s==State::Z){
        throw std::invalid_argument("EN cannot be Z");
    }
    en_=s;
}

void Counter::clk(State s) {
    if(s==State::Z){
        throw std::invalid_argument("CLK cannot be Z");
    }
    bool rising={s==State::H&&prevClk_==State::L};
    prevClk_=s;
    if(!rising){ //不是正緣
        return;
    }
    if(en_==State::L||reset_==State::H){ //en沒開或正在reset
        return;
    }
    value_ = value_ + 1;
    if (value_ == 4) value_ = 0;
}

State Counter::count(unsigned i) {
    if (i > 1) {
        throw std::invalid_argument("count index must be 0 or 1");
    }
    if (((value_ >> i) & 1) == 1) {
        return State::H;
    }
    return State::L;
}

void Counter::print() {
    if(count(1)==State::H) std::cout<<"1";
    else std::cout<<"0";
    if(count(0)==State::H) std::cout<<"1";
    else std::cout<<"0";
    std::cout<<std::endl;
}