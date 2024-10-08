    // Zadanie polega na zaimplementowaniu klasy szablonowej MyContainer,
    // która będzie przechowywać elementy dowolnego typu.
    // Klasa MyContainer powinna zawierać następujące metody:
    // 1. void add(const T& element) - dodaje element do kontenera
    // 2. void remove(int index) - usuwa element z kontenera na podanym indeksie
    // 3. T get(int index) const - zwraca element z kontenera na podanym indeksie
    // 4. int size() const - zwraca liczbę elementów w kontenerze
    // 5. void print() const - wypisuje wszystkie elementy w kontenerze
    // Dodatkowo, metoda print() powinna obsługiwać poprawne wypisywanie wskaźników.
    
    // Dodatkowo, proszę zaimplementować rzutowanie pomiędzy różnymi typami 
    // przy użyciu statycznego rzutowania (static_cast).
    
    // Zakładamy, że elementy w kontenerze mają operator<< przeciążony do wypisywania.


#include <iostream>
#include "MyContainer.h"

int main() {

    MyContainer<int> intContainer;
    intContainer.add(10);
    intContainer.add(20);
    intContainer.add(30);
    intContainer.print();

    MyContainer<std::string> stringContainer;
    stringContainer.add("Hello");
    stringContainer.add("World");
    stringContainer.print();

    // Rzutowanie między typami (np. int na double)
    MyContainer<double> doubleContainer;
    for (int i = 0; i < intContainer.size(); ++i) {
        doubleContainer.add(static_cast<double>(intContainer.get(i)));
    }
    doubleContainer.print();

    // Przechowywanie wskaźników
    MyContainer<int*> ptrContainer;
    int a = 1, b = 2, c = 3;
    ptrContainer.add(&a);
    ptrContainer.add(&b);
    ptrContainer.add(&c);
    ptrContainer.print();

    return 0;
}


// Spodziewany Output:
/*

10 20 30 
Hello World 
10 20 30 
1 2 3 

*/