#ifndef RIPPLE2_H
#define RIPPLE2_H

#include "dff.h"

class Ripple2 {
public:
    Ripple2();
    void reset(State);
    void en(State);
    void clk(State);
    State count(unsigned);
    void print();
private:
    DFF ff0_;
    DFF ff1_;
};

#endif
