#include "GameObject.h"

std::vector<GameObject*> GameObject::activeObjects;


GameObject *GameObject::addGameObject(GameObject *obj)
{
    activeObjects.push_back(obj);
    return obj;
}
void GameObject::destroyGameObject(GameObject *obj)
{
    auto it = std::find(activeObjects.begin(), activeObjects.end(), obj);
    if (it != activeObjects.end())
    {
        delete *it;
        activeObjects.erase(it);
    }
}

void GameObject::destroyGameObjects()
{
    for (GameObject *obj : activeObjects)
    {
        delete obj;
    }
    activeObjects.clear();
}

std::vector<GameObject *>& GameObject::ActiveGameObjects()
{
    return activeObjects;
}