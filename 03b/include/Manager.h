#pragma once
#include "IPracownik.h"
#include <algorithm>

class Manager : public IPracownik
{
private:
    std::vector<IPracownik *> podwladni;

public:
    Manager(std::string name, std::string surname, int id) : IPracownik(name, surname, id) {}
    void przedstawSie() const override
    {
        std::cout << "Jestem managerem.\n";
        std::cout << "Mam na imię: " << _name << " " << _surname << "i mpoim numerem ID jest: " << _id << "\n\n";
    }

    void dodajPodwladnego(IPracownik *pracownik){podwladni.push_back(pracownik);}

    void wygenerujRaport() const
    {
        std::cout << "Generowanie raportu...\n";
        std::cout << "Firma zużywa za dużo pamięci na testerów.\n";
    }

    void zwolnijPracownika(IPracownik *pracownik)
    {
        podwladni.erase(std::find(podwladni.begin(), podwladni.end(), pracownik));
        delete pracownik;
    }

    void ReleaseFromWork() override {delete this;}
    ~Manager()
    {
        for (IPracownik *pracownik : podwladni)
            pracownik->ReleaseFromWork();


        // std::cout << "Zwalnianie Pamięci menagera." << std::endl;
        podwladni.clear();
    }
};
