#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
private:
    /* data */
public:
    CPLX complexity() const{return GameObject::CPLX::MID;}
    void printComplexity() const
    {
        // std::cout<<"Player complaexity: "<<complexity()<<"\n";
    }
    void interact() const
    {
        std::cout<<"Enemy attacks!\n";
    }
    ~Enemy(){};
};
