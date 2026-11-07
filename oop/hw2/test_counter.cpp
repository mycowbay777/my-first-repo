#include "dff.h"
#include "ripple2.h"
#include <cassert>

int main()
{
    Ripple2 rp;
    rp.en(State::H);
    rp.clk(State::L);
    rp.clk(State::H);
    assert((rp.count(0) == State::H));
    rp.en(State::L);
    rp.clk(State::L);
    rp.clk(State::H);
    rp.en(State::H);
    assert((rp.count(0) == State::H));
    rp.reset(State::H);
    rp.clk(State::L);
    rp.clk(State::H);
    rp.reset(State::L);
    assert((rp.count(0) == State::L));
    rp.clk(State::L);
    rp.clk(State::H);
    rp.clk(State::L);
    rp.clk(State::H);
    rp.clk(State::L);
    rp.clk(State::H);
    assert((rp.count(1) == State::H && rp.count(0) == State::H));
    rp.clk(State::L);
    rp.clk(State::H);
    rp.clk(State::H);
    assert((rp.count(1) == State::L && rp.count(0) == State::L));
}
