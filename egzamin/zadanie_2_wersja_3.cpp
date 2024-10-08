#include <iostream> // cout
#include <memory> // unique_ptr
#include <string_view> // std::swap, jest też w utility i algorithm

//wszystki funkcje szablonowe wymagały uzupełnienia o parametr, argumnty i ciało funkcji 
template <typename T>
using ptr = std::unique_ptr<T>;
template <typename T> T swap(T&a, T&b){return a;} 

template<typename T>
void print(T el)
{
    std::cout << el;
} // tylko tu cout i jeden argument

template <typename T>
void print(T* el) // jeden argument
{
  /*
  std::cout<<el<<std::endl;
  std::cout<<sizeof(el)<<std::endl;
  for(int i=0; i<= sizeof(el)/sizeof(el[0]); i++)
    {
      print(el[i]);
      std::cout<<"a";
    }
    */
    std::cout<<" a ";
    T * t2 =el;
    while(t2+1 != "\0") 
    {
      print<T>(*t2);
      t2++;
    }
    std::cout<<" b ";
    
}


template<typename T>
void print(const T& iterable, const char* separator, const char* suffix = "") {
	print<const char*>("[");
	for(auto& item : iterable) {
		print<double>(*item); // tutaj zakładam że przekazywany obiekt iterable obsługuje iteratory oraz jego elementy mają operator dereferencji (prawdziwe dla tego przykładu, w ogólności gorzej XD)
		print<const char*>(separator);
	}
	print<const char*>("]");
	print<const char*>(suffix);
}


template<class T>
void my_swap(T& a, T& b) { // można też zrobić "normalnie", tj. przypisywaniami ze zmienną tymczasową

T tmp = std::move(a);
a = std::move(b);
b = std::move(tmp);
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
//[1.1;2.2;] -> [2.2;1.1;] -> [1.1;2.2;]