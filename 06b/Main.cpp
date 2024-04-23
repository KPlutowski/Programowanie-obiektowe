// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Zadanie związane jest z ideą wczesnego i późnego wiązania.  
// W hierarchii wystepuja 4 klasy, w których Player, Enemy, NPC dziedziczą 
// po klasie abstrakcyjnej GameObject.
// Interfejsy do odwikładnia z funkcji main, wazne by
// atrybut complexity obsluzyc za pomoc klasy enumerowanej
// GameObject::CPLX, o wartościach LOWEST, MID, HIGHEST.
// Uwaga, pomiedzy typem int a CPLX mozna dokonywac kowersji za pomocą static_cast
// 
// Prosze zadbac o dobre zarzadzanie pamiecia.
// Pliku main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab04/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include "Npc.h"
int main() {
  Player player;
  Enemy enemy;
  NPC npc;

  // Przyklad wczesnego wiazania
  player.printComplexity();
  player.interact();
  enemy.interact();
  npc.interact();

  // Przyklad poznego wiazania
  CompareCplx compareComplexity;

  // Do porowniania complexity wykorzystana powinnia byc metoda wirtualna: complexity(),
  // zwracajaca typ int lub GameObject::CPLX, w zaleznosci od tego jak zostanie
  // zaimplementowany CompareCplx::operator()
  std::cout << "Is the player more complex than the enemy? " 
            << (compareComplexity(&player, &enemy) ? "Yes" : "No") << std::endl;
  std::cout << "Is the enemy more complex than the NPC? " 
            << (compareComplexity(&enemy, &npc) ? "Yes" : "No") << std::endl;
  std::cout << "Is the NPC more complex than the player? " 
            << (compareComplexity(&npc, &player) ? "Yes" : "No") << std::endl;

  return 0;
}

/* wynik:
Player complexity: HIGHEST
Player moves!
Enemy attacks!
NPC talks!
Is the player more complex than the enemy? No
Is the enemy more complex than the NPC? No
Is the NPC more complex than the player? Ye
*/