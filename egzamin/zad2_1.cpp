#include <iostream> // cout
#include <memory> // unique_ptr
#include <string_view> // std::swap, jest też w utility i algorithm


template<class T>
void my_print_el (const T& el) { std::cout << el; }

template<class T>
void my_print(const T& iterable, const char* separator = ";", const char* suffix = "\n") {
	my_print_el("[");
	for(auto& item : iterable) {
		my_print_el(*item); // tutaj zakładam że przekazywany obiekt iterable obsługuje iteratory oraz jego elementy mają operator dereferencji (prawdziwe dla tego przykładu, w ogólności gorzej XD)
		my_print_el(separator);
	}
	my_print_el("]");
	my_print_el(suffix);
}

template<class T>
void my_swap(T& a, T& b) { // można też zrobić "normalnie", tj. przypisywaniami ze zmienną tymczasową
T tmp=*a;
*a=*b;
*b=tmp;
}

int main()
{
  std::array<std::unique_ptr<int>,2>a={std::unique_ptr<int>(new int {1}), std::unique_ptr<int>(new int {2})};

  my_print_el("----------------\n");
  my_print(a,";"," -> ");
  my_swap(a[0],a[1]);
  my_print(a,";"," -> ");
  my_swap(*a[0],*a[1]);
  my_print(a);
  my_print_el("----------------");
}
//[1;2;] -> [2;1;] -> [1;2;]