#pragma once

#include "GameObject.h"
#include "Enemy.h"



class Player : public GameObject, public Renderable, public Collidable {
public:
    void action() override {
        std::cout << "Performing player-specific action...\n";
        render();
        collide();
    }
};



void performRuntimeTypeChecking(GameObject* obj){
    if (dynamic_cast<Player*>(obj)) {
        std::cout << "Player object is renderable collidable\n";
    } else if (dynamic_cast<Enemy*>(obj)) {
        std::cout << "Enemy object is renderable collidable updatable\n";
    }
}