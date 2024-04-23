#pragma once
#include "Character.h"

class Thief : public Character
{
private:

public:
    Thief(const std::string name, State state = State::Idle):Character(name,state){};
    ~Thief(){};

    void perform_action() override {
        switch(_state) {
            case State::Idle:
                std::cout << _name << " the Thief is idling around.\n";
                break;
            case State::Attacking:
                // Attacking
                break;
            case State::Defending:
                // Defending
                break;
            case State::Resting:
                // Resting
                break;
            default:
                break;
        }
    }
};
