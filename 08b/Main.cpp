// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Zadanie oparte jest o rozszerzenie / modyfikację zadania z Lab07.
// Zadanie związane jest z ideą wielokrotnego dziedziczenia:
// Klasa bazowa GameObject posiada mechanizm przechowywania 
// wskaźników dla obiektów dynamicznie alokowanych.
// Inne klasy bazowe, po których dziedziczą Player oraz Enemy to:
// Renderable, Collidable, Updatable, gdzie każda z nich zawiera metody, odpowiednio:
// render, collide, update, które wywołane są z poziomu metody action.
// UWAGA: Klasy Collidable i Renderable są z założenia Updatable, czyli dziedziczą po Updatable.
// Tym samym, trzeba zadbać o wirtualny mechanizm dziedziczenia, by nie było problemu, np.
// class Player : public GameObject, public Renderable, public Collidable {...};
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
#include "Player.h"
#include "Enemy.h"

int main() {
  GameObject* player_1 = GameObject::addGameObject(new Player());
  GameObject* player_2 = GameObject::addGameObject(new Player("Ned"));
  {
    GameObject* enemy_1 = GameObject::addGameObject(new Enemy());
    GameObject* enemy_2 = GameObject::addGameObject(new Enemy("Cersei"));
    std::cout << "List of active game objects:" << std::endl;
    for (GameObject* ago : GameObject::ActiveGameObjects())
      std::cout << ago->Name() << ", ";
    std::cout << std::endl;
    GameObject::destroyGameObject(enemy_1); // zwolnienie pojedyńczego obiektu
  }
  GameObject::destroyGameObject(player_1); // zwolnienie pojedyńczego obiektu
  GameObject* enemy_1 = GameObject::addGameObject(new Enemy("Jaime"));

  for (GameObject* ago : GameObject::ActiveGameObjects()) {
    ago->action();
  }

  GameObject::destroyGameObjects();
  return 0;
}

/* wynik:
List of active game objects:
Unnamed Player, Ned, Unnamed Enemy, Cersei, 
Performing player-specific action for Ned:
Rendering object
Updating object
Performing enemy-specific action for Cersei:
Rendering object
Handling collision
Updating object
Performing enemy-specific action for Jaime:
Rendering object
Handling collision
Updating object
*/