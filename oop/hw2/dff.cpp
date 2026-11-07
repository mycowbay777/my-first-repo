#include"dff.h"
#include<stdexcept>

DFF::DFF(){}
void DFF::d(State s){
    d_=s;
}
void DFF::en(State s){
    if(s==State::Z){
        throw std::invalid_argument("EN cannot be Z");
    }
    en_=s;
}
void DFF::reset(State s){
    if(s==State::Z){
        throw std::invalid_argument("RESET cannot be Z");
    }
    reset_=s;
    if(s==State::H){
        q_=State::L;
    }
}
void DFF::clk(State s){
    if(s==State::Z){
        throw std::invalid_argument("RESET cannot be Z");
    }
    bool rising={s==State::H&&prevclk_==State::L};
    prevclk_=s;
    if(!rising){ //不是正緣
        return;
    }
    if(en_==State::L||reset_==State::H){ //en沒開或正在reset
        return;
    }
    if(d_==State::Z){ //d是z
        throw std::invalid_argument("D cannot be Z");
    }
    q_=d_;
}
State DFF::q(){
    return q_;
}
State DFF::qb(){
    if(q_==State::L){
        return State::H;
    }
    return State::L;
}
