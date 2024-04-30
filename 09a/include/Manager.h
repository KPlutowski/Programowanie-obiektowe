#pragma once
#include "Employee.h"

class Manager : public Employee
{
private:
    int teamSize;

public:
    Manager(const std::string &name, double reward, int teamSize) : Employee(name, reward), teamSize(teamSize) {bonus=1;}
    virtual ~Manager() {}

    int getTeamSize() const
    {
        return teamSize;
    }
    std::string getInfo() const
    {
        double bonus = 0.1 * getReward(); // Premia managera
        return Employee::getInfo() + " i " + std::to_string(bonus) + " PLN premii managera";
    }
};
