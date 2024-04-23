// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Zadanie związane jest z ideą wielokrotnego dziedziczenia, oraz wykorzystania
// dynamic_cast do sprawdzania typu.
// Dodatkowo jedna z klas bazowych, GameObject posiada mechanizm przechowywania 
// wskaźników dla obiektów dynamicznie alokowanych.
// Inne klasy bazowe, po których dziedziczą Player oraz Enemy to:
// Renderable, Collidable, Updatable, gdzie każda z nich zawiera metody, odpowiednio:
// render, collide, update, które wywołane są z poziomu metody action.
// 
// Prosze zadbac o dobre zarzadzanie pamiecia.
// Pliku main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

#include <iostream>
#include "Player.h"
#include "Enemy.h"

int main() {
  GameObject* player = GameObject::addGameObject(new Player());
  {
    GameObject* enemy = GameObject::addGameObject(new Enemy());
    GameObject::destroyGameObject(enemy); // zwolnienie pojedyńczego obiektu
  }
  GameObject* enemy = GameObject::addGameObject(new Enemy());

  performRuntimeTypeChecking(player); // uwaga: do sprawdzenia typu obiektu używamy dynamic_cast!!!
  performRuntimeTypeChecking(enemy);

  for (GameObject* ago : GameObject::ActiveGameObjects()) {
    ago->action();
  }

  GameObject::destroyGameObjects();
  return 0;
}

/* wynik:
Player object is renderable collidable
Enemy object is renderable collidable updatable
Performing player-specific action... 
Rendering object
Handling collision
Performing enemy-specific action
Rendering object
Handling collision
Updating object
*/