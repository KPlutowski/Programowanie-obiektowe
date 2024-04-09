#pragma once
#include <iostream>

class GameObject
{
public:
    virtual void attack();
    virtual ~GameObject();
    
    GameObject() = default;
    GameObject(GameObject& other) = default;
};




class Renderable
{
public:
    virtual void attack();
    virtual ~Renderable();

    Renderable() = default;
    Renderable(Renderable& other) = default;
};




class PlayerCharacter : public Renderable, public GameObject
{
public:
    void attack() override;

    PlayerCharacter(PlayerCharacter& other) = default;
    PlayerCharacter() = default;
};

namespace gutils
{
    void handleGameObject(Renderable* renderable);
    void handleGameObject(GameObject* object);

    void handleRenderable(Renderable* renderable);
    void handleRenderable(GameObject* object);
}