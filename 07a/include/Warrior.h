#pragma once
#include "Character.h"

class Warrior : public Character
{
private:

public:
    Warrior(const std::string name, State state = State::Idle):Character(name,state){};
    ~Warrior(){};

    void perform_action() override {
        switch(_state) {
            case State::Idle:
                std::cout << _name << " the Warrior is idling around.\n";
                break;
            case State::Attacking:
                std::cout << _name << " the Warrior swings a sword!\n";
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


