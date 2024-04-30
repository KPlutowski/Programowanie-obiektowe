/*
Proszę dopisać kod, dodać nowe pliki, tak aby program wykonywał się,
a wynik jego działania był taki sam jak podany na końcu tego pliku.

Wymagania:
    - Zdefiniuj Klasy Employee i Manager. Manager jako rodzaj pracownika powinien po zwukłym pracowniku dziedziczyć/
    - Przy odczytywaniu danych pracownika, zwracaj odpowiednie informacje.
    - Wyjątkowo - zdefiniuj w pliku Main.cpp metody/wyrażenia lambda, które będą sortować pracownikow wg. wynagrodzenia.
    - Zdefiniuj metodę showEmployers(), która wyswietla wszystkich pracowników i zwraca ich wynagrodzenie (dla menagerów wraz z premią)
    - Proszę zadbać o zarządzanie pamięcią.

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

Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
ani żadnych innych materiałów (np. chatboty wbudowane w edytor).

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
właściciela nie ma praw dostępu. Rozwiązanie (czyli dodane pliki i Main.cpp
należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
* archiwum powinno zawierać katalog z zadaniem, np. lab02/
* archiwum nie powinno zawierać katalogu build/

├── CMakeLists.txt
├── Main.cpp
├── include
│   ...
│   └── Heder.h
└── src
    ...
    └── Body.cpp

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Employee.h"
#include "Manager.h"

// TODO: Define me: sortEmployees(), showEmployers() - wykorzystajcie std::function lub wyrażenie lambda. Albo oba na raz?
void sortEmployees(std::vector<Employee> &employees, std::function<bool(const Employee &, const Employee &)> comparator)
{
    std::sort(employees.begin(), employees.end(), comparator);
}
void showEmployers(std::vector<Employee> &employees)
{
    for (const Employee& emp : employees)
    {
        if (emp.hasBonus())
        {
            std::cout<<reinterpret_cast<const Manager&>(emp).getInfo();
        }
        else
        {
            std::cout << emp.getInfo();
        }
        std::cout << std::endl;
    }
}
int main()
{
    // Przykładowi pracownicy i menedżerowie
    // Imię, wynagrodzenie
    Employee emp1("Anna", 5000.0);
    Employee emp2("Jan", 6000.0);
    Employee emp3("Katarzyna", 4500.0);
    // Imię, wynagrodzenie, rozmiar zespołu
    Manager man1("Piotr", 7000.0, 5);
    Manager man2("Magdalena", 8000.0, 7);

    // Wektor pracowników
    std::vector<Employee> employees = {emp1, emp2, emp3, man1, man2};

    // Sortowanie pracowników po wynagrodzeniu
    sortEmployees(employees, {// TODO: Przykład wyrażenia lambda, lub funkcji?
                              [](const Employee &emp1, const Employee &emp2)
                              { return emp1.getReward() < emp2.getReward(); }});

    // Wyświetlenie posortowanych pracowników
    std::cout << "Posortowani pracownicy (rosnąco wg wynagrodzenia):" << std::endl;
    showEmployers(employees);

    return 0;
}

/* // Oczekiwany output:

Posortowani pracownicy (rosnąco wg wynagrodzenia):
Katarzyna zarabia 4500.0 PLN
Anna zarabia 5000.0 PLN
Jan zarabia 6000.0 PLN
Piotr zarabia 7000.0 PLN i 1750 PLN premi managera
Magdalena zarabia 8000.0 PLN i 2800 PLN premi managera

// Sposób obliczenia premii managera zostawiam Tobie. Więc jak się zmieni jej wartość - będzie ok.
// W końcu to nie zadanie z algorytmów gdzie macie inżynierią wsteczną dojść do tego jaki algorytm zastosowałem.

*/