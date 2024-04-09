#pragma once
#include <vector>

#include "IKsiazka.h"
#include "User.h"

class Library
{
private:
    std::vector<IKsiazka *> materials;

public:
    void addMaterial(IKsiazka *material)
    {
        materials.push_back(material);
    }
    ~Library()
    {
        for (auto &material : materials)
        {
            delete material;
        }
        materials.clear();
    }

    void borrowBook(const std::string &title, User &user)
    {
        for (auto &material : materials)
        {
            if (material->getTitle() == title && material->getStatus() == IKsiazka::Status::Dostepna)
            {
                material->setStatus(IKsiazka::Status::Wypozyczona);
                user.borrowBook(material);
                std::cout << "Użytkownik " << user.getName() << " wypożyczył książkę: " << title << std::endl;
                return;
            }
        }
        std::cout << "Przepraszamy, książka \"" << title << "\" jest już wypożyczona lub nie istnieje." << std::endl;
    }

    void returnBook(const std::string &title, User &user)
    {
        for (auto &material : materials)
        {
            if (material->getTitle() == title && user.hasBook(material))
            {
                material->setStatus(IKsiazka::Status::Dostepna);
                user.returnBook(material);
                std::cout << "Użytkownik " << user.getName() << " zwrócił książkę: " << title << std::endl;
                return;
            }
        }
        std::cout << "Przepraszamy, książka " << title << " nie została wypożyczona przez tego użytkownika lub nie istnieje." << std::endl;
    }
    void displayAllBooks() const
    {
        std::cout << "\nLista książek w bibliotece:\n";
        for (const auto &material : materials)
        {
            std::cout << "Tytuł: " << material->getTitle() << std::endl;
            std::cout << "Autor: " << material->getAuthor() << std::endl;
            std::cout << "Id ksiazki: " << material->getId() << std::endl;
            std::cout << "Gatunek: " << material->getGenre() << std::endl;
            std::cout << "Na półce:  " << material->getShelf() << std::endl;
            std::cout << "Status: " << (material->getStatus() == IKsiazka::Status::Dostepna ? "Dostępny" : "Wypożyczony") << std::endl<< std::endl;
        }
    }
};
