#pragma once
#include "IKsiazka.h"


class Ksiazka : public IKsiazka
{
private:
    std::string title;
    std::string author;
    int id;
    std::string genre;
    int shelf;
    Status status;
public:
    Ksiazka(const std::string& title, const std::string& author, int id, const std::string& genre, int shelf)
    : title(title), author(author), id(id), genre(genre), shelf(shelf), status(Status::Dostepna) {};

    std::string getTitle() const override{return title;};
    std::string getAuthor() const override{return author;};
    int getId() const override{return id;};
    std::string getGenre() const override{return genre;};
    int getShelf() const override{return shelf;};
    Status getStatus() const override{return status;};;
    void setStatus(Status status) override{this->status=status;};

    // bool Ksiazka::isBorrowedBy(const User& user) const {
    //     if(status==IKsiazka::Status::Wypozyczona&& user)

    // return borrowed && borrower == &user;
    // }
    };
