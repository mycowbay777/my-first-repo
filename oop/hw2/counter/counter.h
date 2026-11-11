#ifndef COUNTER_H
#define COUNTER_H

enum class State { L, H, Z };
class Counter {
public:
    Counter();
    void reset(State);
    void en(State);
    void clk(State);
    State count(unsigned);
    void print();
private:
    unsigned value_ = 0;
    State en_ = State::L;
    State reset_ = State::L;
    State prevClk_ = State::L;
};

#endif
