#include "PlayerCharacter.h"

GameObject::~GameObject() {}
void GameObject::attack()
{
    std::cout<<"Object attacks!\n";
}

Renderable::~Renderable() {}
void Renderable::attack()
{
    std::cout<<"Renderable attacks!\n";
}

void PlayerCharacter::attack()
{
    std::cout<<"PlayerCharacter attacking!\n";
}

void gutils::handleGameObject(Renderable* renderable)
{
    if (renderable)
    {
        std::cout<<"Drawing Renderable\n";
        renderable->attack();
    }
}
void gutils::handleGameObject(GameObject* object)
{
    if (object)
    {
        std::cout<<"Rendering GameObject\n";
        object->attack();
    }
}
void gutils::handleRenderable(Renderable* renderable)
{
    if (renderable)
    {
        std::cout<<"Drawing Renderable\n";
        renderable->attack();
    }
}
void gutils::handleRenderable(GameObject* object)
{
    if (object)
    {
        std::cout<<"Rendering GameObject\n";
        object->attack();
    }
}
