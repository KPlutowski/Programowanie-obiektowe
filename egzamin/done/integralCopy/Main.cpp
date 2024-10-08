// 2018 2 termin 1)

#include<type_traits> // Dla std::is_pod i std::integral_constant 
#include<iostream>
#include<deque>
#include<vector>

struct A {};
struct A_ { virtual ~A_() {} };

// Function templates to print appropriate messages
template<typename T>
void print_copy_message(std::true_type) {
    std::cout << "Copying POD objects" << std::endl;
}

template<typename T>
void print_copy_message(std::false_type) {
    std::cout << "Copying non-POD objects" << std::endl;
}

// my_copy function template
template<typename InputIt, typename OutputIt>
void my_copy(InputIt first, InputIt last, OutputIt d_first) {
    using ValueType = typename std::iterator_traits<InputIt>::value_type;
    print_copy_message<ValueType>(std::is_pod<ValueType>());
    while (first != last) {
        *d_first++ = *first++;
    }
}

int main()  {

  //prosze wykorzystac te informacje
  std::integral_constant<bool,true> tA = std::is_pod<A>::type();
  std::integral_constant<bool,false> tA_ = std::is_pod<A_>::type();

  //Iterator dla każdego kontenera ma zdefiniowany 
  //typ value_type określający typ obiektu na który wskazuje
  std::deque<A> vA1;
  std::vector<A> vA2;
  my_copy(vA1.begin(), vA1.end(), vA2.begin() ) ;

  std::vector <A_> vA_1;
  std::deque<A_> vA_2;
  my_copy(vA_1.begin(), vA_1.end(), vA_2.begin() ) ;
}

/* output/wyjscie 
Copying POD objects
Copying non-POD objects
*/ 