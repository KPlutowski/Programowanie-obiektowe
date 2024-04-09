#pragma once
#include <iostream>
class Animal
{
private:
    const std::string name;
public:
    virtual const std::string getName()const =0;

    virtual void makeSound() const =0;
    virtual void eat()const=0;
    virtual void interact(const Animal *other)const=0 ;
    virtual void useSkill()const=0;
    virtual void sleep()const =0;
    virtual ~Animal(){};
};