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
    
    static void destroyGameObjects();

    static const std::vector<GameObject *> &ActiveGameObjects();



    virtual std::string Name() const =0;

    virtual ~GameObject() = default;

    virtual void action() = 0;


};

class Updatable
{
public:
    virtual void update()
    {
        std::cout << "Updating object\n";
    }
};


class Renderable : virtual public Updatable
{
public:
    virtual void render() const
    {
        std::cout << "Rendering object\n";
    }
};

class Collidable : virtual public Updatable
{
public:
    virtual void collide() const
    {
        std::cout << "Handling collision\n";
    }
};


