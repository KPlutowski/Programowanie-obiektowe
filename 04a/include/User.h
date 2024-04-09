#pragma once
#include "IKsiazka.h"

#include <vector>
#include <algorithm>

class User
{
private:
    std::string name;
    std::vector<IKsiazka *> borrowedBooks;

public:
    User(const std::string &name) : name(name){};
    const std::string &getName() const { return name; };
    void borrowBook(IKsiazka *book)
    {
        borrowedBooks.push_back(book);
    }

    void returnBook(IKsiazka *book)
    {
        auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
        if (it != borrowedBooks.end())
        {
            borrowedBooks.erase(it);
        }
    }

    bool hasBook(IKsiazka *book) const
    {
        return std::find(borrowedBooks.begin(), borrowedBooks.end(), book) != borrowedBooks.end();
    }

    void displayBorrowedBooks() const
    {
        std::cout << "Lista wypożyczonych książek przez użytkownika:\n";
        for (const auto &book : borrowedBooks)
        {
            std::cout << "Tytuł: " << book->getTitle() << std::endl;
        }
    }
};
