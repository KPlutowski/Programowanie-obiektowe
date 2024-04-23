#pragma once
#include <iostream>
#include <vector>
#include <algorithm>




class GameObject
{
protected:
    static std::vector<GameObject *> activeObjects;

public:
    static GameObject *addGameObject(GameObject *obj);
    static void destroyGameObject(GameObject *obj);


    virtual ~GameObject() = default;

    virtual void action() = 0;

    static void destroyGameObjects();


    static std::vector<GameObject *> &ActiveGameObjects();

};


class Renderable
{
public:
    virtual void render() const
    {
        std::cout << "Rendering object\n";
    }
};

class Collidable
{
public:
    virtual void collide() const
    {
        std::cout << "Handling collision\n";
    }
};

class Updatable
{
public:
    virtual void update()
    {
        std::cout << "Updating object\n";
    }
};


