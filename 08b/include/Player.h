#pragma once

#include "GameObject.h"
#include "Enemy.h"

class Player : public GameObject, public Renderable, public Collidable
{
private:
    std::string name = "Unnamed Player";

public:
    void action() override
    {
        std::cout << "Performing enemy-specific action for " << name << ":\n";
        render();
        update();
    }

    Player(std::string name = "Unnamed Player") : name(name) {}

    std::string Name() const override
    {
        return name;
    }
};
