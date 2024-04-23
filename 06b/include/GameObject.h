#pragma once 
#include <iostream>


class GameObject
{
private:
    /* data */
public:
    enum class CPLX
    {
        LOWEST=1,
        MID,
        HIGHEST
    };
    virtual void printComplexity() const=0;
    virtual void interact() const=0; 
    virtual CPLX complexity() const=0;

    virtual ~GameObject(){};
};
