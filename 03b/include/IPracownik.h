#pragma once
#include <iostream>
#include <vector>

class IPracownik
{
protected:
    std::string _name;
    std::string _surname;
    int _id;
public:
    IPracownik(std::string name,std::string surname, int id):_name(name),_surname(surname),_id(id) {}
    virtual ~IPracownik(){};

    virtual void przedstawSie() const=0;
    virtual void ReleaseFromWork() =0;
};

