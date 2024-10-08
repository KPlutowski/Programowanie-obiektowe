namespace std{
  class vector{};
  class list{};
  class deque{};
  class set{};
  class map{};
}

#include <cstdlib>
#include <iostream>


namespace oop{

  template<typename T>
  struct Array
  {
    using value_type = T;
  
    Array(int size):_size(size){
      arr = new T(size);
    }
    ~Array(){
      delete arr;
    }

    Array& insert(T val){
      arr[index]=val;
      index++;
      return *this;
    }

    Array& operator+(T c){
      insert(c);
      return *this;
    }

    int operator~(){
      return index;
    }
    char operator[](int index){
      return arr[index];
    }

    private:
      T* arr;
      int _size=0;
      int index=0;
  };
}



int main(){

    typedef oop::Array<char> type;
    type a( rand() % 10 + 6 );

    a.insert('#').insert('C') + type::value_type('+') + '+' + '0' + ('0' + 3 );

    for(unsigned i = 0; i!= ~a; ++i)
      std::cout<< a[i] << (i+1 != ~a ? "" : "\n"  );
}

/*
  #C++03
*/