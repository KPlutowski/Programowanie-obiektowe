// Celem zadania jest systemu zarządzania systemem plików.
// Skladnikami tymi sa miedzy innymi katalog (klasa Dir) i plik (klasa File),
// ale z możliwością rozszerzenia implementacji o kolejne typy, np. Link
// W tym zadaniu należy zaimplementowac metodę listDirs, której argumentem jest głębokość
// w drzewie katalogu, do której chcemy listować katalogi, ale z założeniem że
// metoda listDirs korzysta z metody FSElement::getFSElemets, które zwraca również liste 
// katalogow / plikow / itp do danego poziomu zagnieżdzenia.
// Metoda ta przyjmuje również określenie typu, np. Type::Dir, Type::File
// Dodatkowym założeniem jest kopiowanie katalagu z całą jego "zawartością".
// UWAGA: FSElement to klasa bazowa.
// UWAGA: Haczyk w zadaniu to ryzyko ewentualnego "circular dependency".
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.


#include "Dir.h"
#include "File.h"

int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; // dodajemy do kat TOP podkatalog
  *home += new Dir("ewa");
  
  *home += new File("proj.descr");
  home->add(new File("proj.files.repo") );
  home->add(new Dir("adam") );
  
  top->findDir("ewa")->add( new Dir("Desk") );

  Dir* ewa = home->findDir("ewa");  
  *ewa += new File("pict.jpg");
  top->findDir("ewa")->add( new Dir("work") );

  std::cout << *top << std::endl;


  std::cout << "--------------" << std::endl;
  top->listDirs(1);
  std::cout << "--------------" << std::endl;
  top->listDirs(2);

  // delete top;
}

/*
. (DIR)
  home (DIR)
    ewa (DIR)
      Desk (DIR)
      pict.jpg (FILE)
      work (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)

--------------
. home 
--------------
. home ewa adam
*/