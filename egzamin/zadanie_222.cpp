#include <iostream> // cout
#include <memory> // unique_ptr
#include <string_view> // std::swap, jest też w utility i algorithm

//wszystki funkcje szablonowe wymagały uzupełnienia o parametr, argumnty i ciało funkcji 
template <typename T>
using ptr = std::unique_ptr<T>;
template <typename T> T swap(T&a, T&b){return a;} 

template<typename T>
void print(const T& el) { std::cout << el; } // tylko tu cout i jeden argument

template <typename T> void print(const T* el) // jeden argument
{
  print<const char*>(el);
}

template<typename T>
void print(const T& iterable, const char* separator = ";", const char* suffix = " --> ") {
	print("[");
	for(auto& item : iterable) {
		print<const char*>(*item); // tutaj zakładam że przekazywany obiekt iterable obsługuje iteratory oraz jego elementy mają operator dereferencji (prawdziwe dla tego przykładu, w ogólności gorzej XD)
		print<const char*>(separator);
	}
	print<const char*>("]");
	print(suffix);
}

template<class T>
void my_swap(T& a, T& b) { // można też zrobić "normalnie", tj. przypisywaniami ze zmienną tymczasową
T tmp=*a;
*a=*b;
*b=tmp;
}

int main()
{
  std::array<ptr<double>,2>a={ptr<double>(new double {1.1}), ptr<double>(new double {2.2})};

  print("----------------\n");
  print(a,";"," -> ");
  my_swap(a[0],a[1]);
  print(a,";"," -> ");
  my_swap(*a[0],*a[1]);
  print(a, ";");
  print("----------------");
}
//[1;2;] -> [2;1;] -> [1;2;]