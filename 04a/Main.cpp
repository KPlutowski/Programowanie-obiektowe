/*
Proszę dopisać kod oraz dodać nowe pliki, tak aby program wykonywał się poprawnie, a wynik jego działania był taki sam jak podany na końcu tego pliku.

Zadaniem będzie zaimplementowanie systemu zarządzania biblioteką książek. System powinien umożliwiać dodawanie, wypożyczanie i zwracanie książek przez użytkowników.

Wymagania:

  - Zdefiniuj klasę Library, która będzie zarządzać książkami w bibliotece.
  - Biblioteka powinna umożliwiać dodawanie, wypożyczanie i zwracanie książek.
  - Przy wypożyczaniu i zwracaniu książek, upewnij się, że książka jest dostępna lub wypożyczona przez odpowiedniego użytkownika.
  - Pamiętaj że to zadanie z dziedziczenia i z jakiegoś powodu przygotowałeś interface IKsiazka na dziś. 

Proszę zadbać o zarządzanie pamięcią.
Pliku Main.cpp nie wolno modyfikować, chyba że w tekście zadania podano inaczej.

Program wyjściowy powinien składać się z czytelnego kodu.
Powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

Zadania oceniane są wg algorytmu: 
  - Warunkiem przystąpienia do oceniania programu jest jego poprawna kompilacja (bez błędów). 
  - Dokumentacja - 1 pkt. 
  - Poprawna kompilacja (bez ostrzeżeń) - 2 pkt. 
  - Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt. 
  - Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt. 

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
│   └── Library.h
└── src
    ...
    └── Library.cpp

CheetSheet - żeby nie musieć za dużo stukać w klawiaturę - to nie sprawdza Twoich umiejętności:
std::cout << "Tytuł: " <<
std::cout << "Autor: " <<
std::cout << "Rok wydania: " <<
std::cout << "Gatunek: " <<
std::cout << "Liczba stron: " <<
std::cout << "Status: " <<
std::cout << std::endl;

*/

#include <iostream>
#include "IKsiazka.h"
#include "Ksiazka.h"
#include "Czasopismo.h"
#include "Komiks.h"
#include "Library.h"
#include "User.h" 

int main() {
    Library library;

    // tytuł, autor, id, gatuneki, na której półce się znajduje
    Ksiazka* ksiazka = new Ksiazka("W pustyni i w puszczy", "Henryk Sienkiewicz","klasyka", 1, "Przygodowa", 5);
    Czasopismo* czasopismo = new Czasopismo("National Geographic", "John Doe", 2, "Przyroda","geografia","zwierzęta", 7);
    Komiks* komiks = new Komiks("Batman", "Bob Kane", 3, "Akcja","Superbohaterowie", 9);
   

    library.addMaterial(ksiazka);
    library.addMaterial(czasopismo);
    library.addMaterial(komiks);

    User user1("Jan Piotrowski");
    User user2("Anna Pietruszka");

    // Wypożycz książki przez użytkowników
    library.borrowBook("Batman", user1);
    library.borrowBook("Wiedźmin", user2); // Próba wypożyczenia nieistniejącej książki
    library.borrowBook("Batman", user2); // Próba wypożyczenia niedostępnej już książki
    library.borrowBook("W pustyni i w puszczy", user2); 


    // Wyświetl informacje o wypożyczonych książkach
    std::cout << "\nKonto użytkowinka " << user1.getName() << ":\n";
    user1.displayBorrowedBooks();

    std::cout << "\nKonto użytkowinka " << user2.getName() << ":\n";
    user2.displayBorrowedBooks();

    // Zwróć książki
    library.returnBook("W pustyni i w puszczy", user1);
    library.returnBook("Batman", user1);
    library.returnBook("W pustyni i w puszczy", user2);

    // Wyświetl informacje o wszystkich książkach w bibliotece
    std::cout << "\nWszystkie książki w bibliotece:\n";
    library.displayAllBooks();

    return 0;

}


// Spodziewany output - If you feel fancy - można dodać rozróżnienie czy książka jest wypożyczona czy nie znajduje się w zasobach biblioteki.
/*

Użytkownik Jan Piotrowski wypożyczył książkę: Batman
Przepraszamy, książka "Wiedźmin" jest już wypożyczona lub nie istnieje.
Przepraszamy, książka "Batman" jest już wypożyczona lub nie istnieje.
Użytkownik Anna Pietruszka wypożyczył książkę: W pustyni i w puszczy

Konto użytkowinka Jan Piotrowski:
Lista wypożyczonych książek przez użytkownika:
Tytuł: Batman

Konto użytkowinka Anna Pietruszka:
Lista wypożyczonych książek przez użytkownika:
Tytuł: W pustyni i w puszczy

Przepraszamy, książka W pustyni i w puszczy nie została wypożyczona przez tego użytkownika lub nie istnieje.
Użytkownik Jan Piotrowski zwrócił książkę: Batman
Użytkownik Anna Pietruszka zwrócił książkę: W pustyni i w puszczy

Wszystkie książki w bibliotece:

Lista książek w bibliotece:
Tytuł: W pustyni i w puszczy
Autor: Henryk Sienkiewicz
Id ksiazki: 1
Gatunek: Przygodowa
Na półce:  5
Status: Dostępny

Tytuł: National Geographic
Autor: John Doe
Id ksiazki: 2
Gatunek: Przyroda
Na półce:  7
Status: Dostępny

Tytuł: Batman
Autor: Bob Kane
Id ksiazki: 3
Gatunek: Superbohaterowie
Na półce: 9
Status: Dostępny

*/