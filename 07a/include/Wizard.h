#pragma once
#include "Character.h"

class Wizard : public Character
{
private:

public:
    Wizard(const std::string name, State state = State::Idle):Character(name,state){};
    ~Wizard(){};

    void perform_action() override {
        switch(_state) {
            case State::Idle:
                std::cout << _name << " the Wizard is idling around.\n";
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

    void cast_spell() const {
        std::cout << _name << " the Wizard casts a spell!\n";
    }
};
