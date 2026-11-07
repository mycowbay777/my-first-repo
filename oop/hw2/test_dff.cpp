#include "dff.h"
#include <cassert>

int main()
{
    DFF df;
    df.en(State::L);
    df.d(State::H);
    df.clk(State::L);
    df.clk(State::H);
    assert((df.q() == State::L));
    df.en(State::H);
    df.d(State::H);
    df.clk(State::L);
    df.clk(State::H);
    df.d(State::L);
    df.clk(State::H);
    assert((df.q() == State::H));
    df.en(State::L);
    df.en(State::H);
    df.clk(State::H);
    assert((df.q() == State::H));
    df.reset(State::H);
    df.d(State::H);
    df.clk(State::L);
    df.clk(State::H);
    df.d(State::L);
    df.clk(State::H);
    assert((df.q() == State::L));
    df.d(State::Z);
}
