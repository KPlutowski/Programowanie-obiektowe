#include <iostream>
#include<utility>

//UZUPEŁNIJ 1
template< typename T>
struct ptr{
  using value_type = T;
  explicit ptr(T* p):_p(p){}
  ptr(ptr&& x): _p(std::__exchange(x._p, nullptr)){}
  ~ptr(){
    delete _p;
  }
  T& operator*(){
    return *_p;
  }
  T operator*() const{
    return *_p;
  }
  T* operator->(){
    return _p;
  }
  private:
  T* _p;
};

template< typename T = char>
struct Type_t{

  Type_t(T arg = 0) : _v(arg) { }

  /*operator char() const {
    return static_cast<char>(_v);
  }*/

  T operator+ (int i) const { return static_cast<T> ( static_cast<int>(_v) + i ); }

  friend std::ostream& operator<< (std::ostream& str, const Type_t& to_print) {
    str << to_print._v;
    return str;
  } //do wypisania w linijce 68

  //Type_t(float v = 0): _v(v){} // do testów
  T _v;
};
//UZUPEŁNIJ 1 END

template <typename T> T move_t(T& p){
  return std::move(p);
}

using Float_t = Type_t<>;


// w main tam gdzie zakomentowane: //Po odkomentowaniu błąd kompilacji czy tam inny
int main(){
  using Type_ptr = ptr<std::pair<Float_t, Float_t>>;

  Type_ptr t1 { new Type_ptr::value_type{}};
  // Type_ptr t2 = t1; // po zrobieniu ptr(ptr&& x), ptr(ptr& x) jest domyślnie usuwany
  // Type_ptr t2; t2 = t1; // po zrobieniu ptr(ptr&& x), op.=(ptr& x) jest domyślnie usuwany
  // Type_ptr t3 = new Type_ptr::value_type(); // bez explicit tu nie byłoby błędu
  (*t1).first = Type_ptr::value_type::first_type{65};
  t1->second = t1->first + 1;
  std::cout<< t1->first._v<<" "<<t1->second<<std::endl;

  Type_ptr t2 = move_t(t1);
  // t2->first = 13; //tu byłby potrzebny konstruktor (Float_t) - Type_t(float v)
  // t2->second = 13;
  const Type_ptr t3 = move_t(t2);
  //t3->first = Type_ptr::value_type::first_type{13}; // tu potrzebaby drugi op.->() z const... (wtedy by się kompilowało, ale przez const t3 i tak 13 nie byłoby przypisywane)
  //t3->second = Type_ptr::value_type::second_type{13}; 

  std::cout<< (*t3).first._v<<" "<<(*t3).second<<std::endl; // tutaj możliwe, że było coś innego, ale wydaje się git
  return 0;
}
