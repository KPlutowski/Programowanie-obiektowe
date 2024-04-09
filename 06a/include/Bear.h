#pragma once
#include "Animal.h"

class Bear : public Animal
{
private:
    const std::string name = "Bear";
public:
    const std::string getName()const {return name;};



    void makeSound()const override
    {
        std::cout<<name<<" growls\n";
    }
    void eat()const override
    {
        std::cout<<name<<" eats fish\n";
    }
    void interact(const Animal *other)const override
    {
        std::cout<<name<<" grunts at "<<other->getName()<<"\n";
    }
    void useSkill()const override
    {
        std::cout<<name<<" uses Belly Drum skill\n";

    }
    void sleep()const override
    {
        std::cout<<"\n";
    }
};


