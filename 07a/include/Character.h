#pragma once
#include <iostream>

enum class State
{
    Idle,
    Attacking,
    Defending,
    Resting
};

class Character
{
protected:
    std::string _name;
    State _state;

public:
    const State get_state() const {return _state;}
    void set_state(const State state) {_state = state;}
    virtual void perform_action() = 0;

    Character(const std::string &name, State state = State::Idle) : _name(name), _state(state) {}
    ~Character(){};
};
