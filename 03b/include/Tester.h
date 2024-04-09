#pragma once
#include "IPracownik.h"


class Tester: public IPracownik
{
private:
    bool _isTesting;
public:
    Tester(std::string name,std::string surname, int ID,bool isTrsting) : IPracownik(name,surname,ID),_isTesting(isTrsting){}
    void przedstawSie() const override
    {
        std::cout<<"Jestem testerem."<<'\n';
        std::cout<<"Mam na imię: "<<_name<<" "<<_surname<<"i mpoim numerem ID jest: "<<_id<<'\n';
        std::cout<<"JA odpowiedź na to, czy automatyzuję testy brzmi - "<< (_isTesting?"tak":"nie") <<"\n\n";
    }
    void ReleaseFromWork()override{delete this;}

    ~Tester(){std::cout<<"Zwalnianie Pamięci Testera."<<std::endl;}


};

