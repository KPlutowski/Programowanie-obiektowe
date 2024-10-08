struct A {
    void operator()(int& el){
        el=i;
        i--;
    }
    int i=-1;
};

int main() {
    list<int> coll(11);
    for_each( coll.begin(),coll.end(), A());
    copy(coll.begin(),coll.end(),  ostream_iterator<int>(cout, "; "));
    return 0;
}
///////////////////////////

template<typename T = int, template<typename U = T, typename Allocator = std::allocator<U>> class StorageType = std::deque>
struct fifo{
  using storage_type = StorageType<T>;
  fifo(){
    std::cout<<__PRETTY_FUNCTION__<<"\n";
  }
  void push(T i){
    data.push_back(i);
  }

  T get(){
    T tmp = data[0];
    data.pop_front();
    return tmp;
  }

  int size(){
    return data.size();
  }

  StorageType<T> data;

  typename storage_type::const_iterator begin() {
    return data.begin();
  }
  
  typename storage_type::const_iterator end() {
    return data.end();
  }
};


///////////////////////////


template<typename I,typename F>
void my_for_each(I begin,I end, F func){
    for(I i = begin;i!=end;i++){
       func(*i);
    }
}

int main() {
    using namespace std;

    int c[] = { 1, 2, 3, 4, 5 };

    auto print = [](int el){ cout<<el<<" ";};
    auto print_eol = [](){ cout<<"\n";};
    my_for_each(begin(c), end(c), print);
    print_eol();

    int add_value = 1;
    auto add = [&add_value](int& i){i+=add_value;};
    my_for_each(begin(c), end(c), add);
    my_for_each(begin(c), end(c), print);
    print_eol();

    add_value = 10;

    my_for_each(begin(c), end(c), add);
    my_for_each(begin(c), end(c), print);
    print_eol();

    return 0;
}


//////////////////////////

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


/////////////////////////////