#pragma once
#include <iostream>

class Employee
{
protected:
    std::string name;
    double reward;
    bool bonus=0;

public:
    Employee(const std::string &name, double reward) : name(name), reward(reward) {}
    virtual ~Employee() {}

    const std::string &getName() const
    {
        return name;
    }
    double getReward() const
    {
        return reward;
    }
    std::string getInfo() const
    {
        return name + " zarabia " + std::to_string(reward) + " PLN";
    }
    bool hasBonus() const {return bonus;}
};