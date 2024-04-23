#pragma once
#include "GameObject.h"

class NPC : public GameObject
{
private:
    /* data */
public:
    CPLX complexity() const{return GameObject::CPLX::LOWEST;}
    void printComplexity() const
    {
        // std::cout<<"Player complaexity: "<<complexity()<<"\n";
    }
    void interact() const
    {
        std::cout<<"NPC talks!\n";
    } 
    ~NPC(){};
};
