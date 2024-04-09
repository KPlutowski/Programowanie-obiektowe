#pragma once
#include "Animal.h"

class Tiger : public Animal
{
private:
    const std::string name = "Tiger";
    
public:
    const std::string getName()const {return name;};


    void makeSound()const override
    {
        std::cout<<name<<" growls\n";
    }
    void eat()const override
    {
        std::cout<<name<<" eats meet\n";
    }
    void interact(const Animal *other)const override
    {
        std::cout<<name<<" stares at "<<other->getName()<<"\n";
    }
    void useSkill()const override
    {
        std::cout<<name<<" uses Flare Blitz skill\n";
    }
    void sleep()const override
    {
        std::cout<<"\n";
    }
};

