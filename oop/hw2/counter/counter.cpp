#include "counter.h"
#include <iostream>
#include <stdexcept>

Counter::Counter() {}

void Counter::reset(State s) {
    // 參考 DFF::reset，但歸零的是 value_
    if(s==State::Z){
        throw std::invalid_argument("RESET cannot be Z");
    }
    reset_=s;
    if(s==State::H){
        value_=0;
    }
}

void Counter::en(State s) {
    // 跟 DFF::en 一樣
}

void Counter::clk(State s) {
    // 參考 DFF::clk 的結構
    // 最後一步不是 q_ = d_，而是讓 value_ 加 1，並且 4 要變回 0
}

State Counter::count(unsigned i) {
    // i 不是 0 或 1 → throw
    // 用 (value_ >> i) & 1 取出第 i 位，1 回傳 H，0 回傳 L
}

void Counter::print() {
    // 跟 Ripple2::print 類似，但改用 count(1)、count(0)
}