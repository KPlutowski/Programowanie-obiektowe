#pragma once

#include "GameObject.h"
class GameObject;

class CompareCplx {
public:
    bool operator()(const GameObject* obj1, const GameObject* obj2) const
    {
        return static_cast<int>(obj1->complexity()) < static_cast<int>(obj2->complexity());
    }
};