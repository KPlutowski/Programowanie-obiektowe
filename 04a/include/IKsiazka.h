#pragma once



class IKsiazka
{
public:
    enum class Status {
        Dostepna,
        Wypozyczona
    };
    virtual ~IKsiazka() {}
    virtual std::string getTitle() const = 0;
    virtual std::string getAuthor() const = 0;
    virtual int getId() const = 0;
    virtual std::string getGenre() const = 0;
    virtual int getShelf() const = 0;
    virtual Status getStatus() const = 0;
    virtual void setStatus(Status status) = 0;
};

