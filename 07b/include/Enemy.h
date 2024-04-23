#pragma once

#include "GameObject.h"

class Enemy : public GameObject, public Renderable, public Collidable, public Updatable {
public:
    void action() override {
        std::cout << "Performing enemy-specific action\n";
        render();
        collide();
        update();
    }
};