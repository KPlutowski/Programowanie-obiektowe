#pragma once

#include "GameObject.h"

class Enemy : public GameObject, public Renderable,public Collidable
{
private:
    std::string name = "Unnamed Enemy";

public:
    Enemy(std::string name="Unnamed Enemy"):name(name){}
    void action() override
    {
        std::cout << "Performing enemy-specific action for "<<name<<":\n";
        render();
        collide();
        update();
    }

    std::string Name() const override
    {
        return name;
    }
};