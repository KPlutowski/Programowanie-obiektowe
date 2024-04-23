#pragma once
#include "GameObject.h"
#include "CompareCplx.h"

class Player : public GameObject
{
private:
    /* data */
public:

    CPLX complexity() const{return GameObject::CPLX::HIGHEST;}
    void printComplexity() const
    {
        std::cout<<"Player complaexity: "<<static_cast<int>(complexity())<<"\n";
    }
    void interact() const
    {
        std::cout<<"Player moves!\n";
    } 
    ~Player(){};
};
