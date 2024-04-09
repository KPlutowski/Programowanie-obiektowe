#pragma once
#include "Animal.h"

class Lion : public Animal
{
private:
    const std::string name = "Lion";
public:
    const std::string getName()const {return name;};

    void makeSound() const override
    {
        std::cout<<name<<" roars\n";
    }
    void eat()const override
    {
        std::cout<<name<<" eats meet\n";
    }
    void interact(const Animal *other)const override
    {
        std::cout<<name<<" roars at "<<other->getName()<<"\n";
    }
    void useSkill()const override
    {
        std::cout<<name<<" uses Hyper Voice skill\n";
    }
    void sleep()const override
    {
        std::cout<<"\n";
    }
};

