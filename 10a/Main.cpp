/*
Proszę dopisać kod, dodać nowe pliki, tak aby program wykonywał się, 
a wynik jego działania był taki sam jak podany na końcu tego pliku.

Wymagania:
    Napisać klasy Company i Worker/Employee tak by program wykonywał się
    Zdefiniować wyrażenia lambda przekazywane do metod w taki sposób by program wykonywał się
    Zdefiniować metody addEmployee, displayEmployees, removeEmployees jak i sortEmployees w klasie company 
    Proszę się upewnić czy importujemy to co jest potrzebne 
    
Pliku Main.cpp nie wolno modyfikować, chyba że w tekście zadania podano inaczej (Oznaczenie TODO:).

Program wyjściowy powinien składać się z czytelnego kodu. Powinna być spełniona zasada D.R.Y. - Don’t Repeat Yourself.

Zadania oceniane są wg algorytmu:

    Warunkiem przystąpienia do oceniania programu jest jego poprawna kompilacja (bez błędów).
    Dokumentacja - 1 pkt.
    Poprawna kompilacja (bez ostrzeżeń) - 2 pkt.
    Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt.
    Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt.


Programy niezgodne z tematem/celem zadania, 
ale kompilujące się (i dające potencjalnie "poprawne" wyjście) będą oceniane na 0 pkt.

*/

#include <iostream>
#include "Company.h"


int main() {
    Company company;

    // Dodajemy kilka pracowników do firmy
    company.addEmployee("Jan Kowalski", "Programista", 5000);
    company.addEmployee("Anna Wysocka", "Księgowa", 4500);
    company.addEmployee("Piotr Zieliński", "Manager", 8000);

    // Wyświetlamy wszystkich pracowników
    company.displayEmployees();

    // Sortujemy pracowników według pensji za pomocą wyrażenia lambda
    // TODO: Napisz wyrażenie lambda, które porównuje pensje pracowników
    company.sortEmployees( [](const Employee& a, const Employee& b) {
        return a.getSalary() < b.getSalary();
    });


    std::cout << "Posortowani pracownicy (rosnąco wg pensji):" << std::endl;
    // Ponownie wyświetlamy pracowników
    company.displayEmployees();

    // Usuwamy pracowników, którzy spełniają określone kryterium za pomocą wyrażenia lambda
    // TODO: Napisz wyrażenie lambda, które sprawdza, czy pensja pracownika jest mniejsza niż 5000
    company.removeEmployees( [](const Employee& employee) {
        return employee.getSalary() < 5000;
    });

    std::cout << "Posortowani pracownicy (po zwolnieniach):" << std::endl;

    // Ponownie wyświetlamy pracowników
    company.displayEmployees();

    return 0;
}

/*Spodziewany output

Jan Kowalski - 5000.0 PLN
Anna Wysocka - 4500.0 PLN
Piotr Zieliński - 8000.0 PLN

Posortowani pracownicy (rosnąco wg pensji):

Anna Wysocka - 4500.0 PLN
Jan Kowalski - 5000.0 PLN
Piotr Zieliński - 8000.0 PLN

Posortowani pracownicy (po zwolnieniach):

Jan Kowalski - 5000.0 PLN
Piotr Zieliński - 8000.0 PLN



*/