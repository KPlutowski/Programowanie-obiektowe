/* Zadaniem będzie zaimplementowanie systemu zarządzania zwierzętami w zoo. System powinien umożliwiać tworzenie zwierząt różnych gatunków (Lew, Tygrys, Liger) oraz zarządzanie ich zachowaniami.

Wymagania:
    
    - Zdefiniuj klasę Animal, która będzie bazową klasą dla różnych gatunków zwierząt.
    - Zdefiniuj klasę Zoo, które będzie przechowywała wszystkie zwierząta.
    - Utwórz klasy Lion i Tiger, które dziedziczą po klasie Animal i implementują jej metody wirtualne. (roar(), display(), climb())
    - Utwórz klase Liger, które dziedziczy po Lion i Tiger.
    - Klasa Liger powinna w wywołaniu metody climb powodować wywołanie metody climb() odpowiedniej klasy rodzica. 
    - Pamiętaj, że to zadanie z dziedziczenia, polimorfizmu i prezentuje problem diamentu. Każde zwierzę powinno mieć unikalne cechy i zachowania.
    - Wszystkie metody Klasy Zoo powinny działać na bazie prostej lambdy.
    - Proszę zadbać o zarządzanie pamięcią.

Pliku Main.cpp nie wolno modyfikować, chyba że w tekście zadania podano inaczej (Oznaczenie TODO:).

Program wyjściowy powinien składać się z czytelnego kodu. Powinna być spełniona zasada D.R.Y. - Don’t Repeat Yourself.

Zadania oceniane są wg algorytmu:

    Warunkiem przystąpienia do oceniania programu jest jego poprawna kompilacja (bez błędów).
    Dokumentacja - 1 pkt.
    Poprawna kompilacja (bez ostrzeżeń) - 2 pkt.
    Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt.
    Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt. */


#include "Zoo.h"
#include <iostream>
#include <vector>

int main() {
    Zoo zoo;

    auto lion = new Lion();
    auto tiger = new Tiger();
    decltype(lion) liger = new Liger();

    zoo.addAnimal(lion);
    zoo.addAnimal(tiger);
    zoo.addAnimal(liger);

    zoo.makeAllAnimalsRoar();
    zoo.displayAnimals();

    delete lion;
    delete tiger;
    delete liger;

    return 0;
}

/* Przewidywany output:

Roarrr, I am a lion!
Roarrr, I am a tiger!
Roarrr, I am a liger!

It's a Lion
I am not able to climb!

It's a Tiger
I am able to climb!

It's a Liger
I am able to climb!

*/