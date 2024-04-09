#pragma once
#include "IPracownik.h"


class Programista: public IPracownik
{
private:
    std::string _language;
public:
    Programista(std::string name,std::string surname, int ID,std::string language) : IPracownik(name,surname,ID),_language(language){}
    void przedstawSie() const override
    {
        std::cout<<"Jestem programistą."<<'\n';
        std::cout<<"Mam na imię: "<<_name<<" "<<_surname<<"i mpoim numerem ID jest: "<<_id<<'\n';
        std::cout<<"Moim jezykiem programowania jest: "<<_language<<"\n\n";
    }
    void ReleaseFromWork()override{delete this;}
    
    ~Programista(){/*std::cout<<"Zwalnianie Pamięci programisty."<<std::endl;*/}

};

