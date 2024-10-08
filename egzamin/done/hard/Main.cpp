#include<utility>
#include<iostream>
#include<algorithm>


template<typename T = float>
struct Type_t{
  Type_t(){};
  explicit Type_t(T value): _v(value){};
  friend std::ostream & operator<<(std::ostream & os, const Type_t & elem){
    return os << elem._v;
  }
  T _v;

};

template<typename T>
class ptr{
  public:

  using value_type = T;
  T* _p;
  explicit ptr(T* newPointer):_p(newPointer) {}

  ptr(const ptr&)=delete;
  ptr operator=(const ptr&)=delete;
  ptr(ptr&& other){
    _p=other._p;
    other._p=nullptr;
  }

  value_type& operator*()const {return *_p;}

  value_type* operator->(){return _p;}
  ~ptr(){delete _p;}

};



using Float_t = Type_t<>;

int main(){
  using Type_ptr = ptr<std::pair<Float_t, Float_t>>;
  Type_ptr t1 { new Type_ptr::value_type{}};
  //Type_ptr t2 = t1; 
  //Type_ptr t2; t2 = t1;
  //Type_ptr t3 = new Type_ptr::value_type();
  (*t1).first = Type_ptr::value_type::first_type{1};
  t1->second = Type_ptr::value_type::second_type{2.5};
  std::cout<< t1->first._v<<" "<<t1->second<<std::endl;

  Type_ptr t2 = std::move(t1);
  // t2->first = 13; 
  // t2->second = 13;
  const Type_ptr t3 = std::move(t2);
  // t3->first = Type_ptr::value_type::first_type{13};
  // t3->second = Type_ptr::value_type::second_type{13}; 

  std::cout<< (*t3).first._v<<" "<<(*t3).second<<std::endl;
  return 0;
}

// 1 2.5
// 1 2.5