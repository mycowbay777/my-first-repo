#ifndef DFF_H
#define DFF_H

enum class State { L, H, Z };

/**
 * @brief D flip-flop
 */
class DFF {
public:
    DFF();
    void reset(State);
    void d(State);
    void clk(State);
    void en(State);
    State q();
    State qb();
private:
    State d_=State::L;
    State q_=State::L;
    State reset_=State::L;
    State en_=State::L;
    State prevclk_=State::L; 
};

#endif
