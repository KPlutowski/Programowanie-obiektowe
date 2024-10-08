// 2017 2 termin 2)

#include <iostream>

// namespace oop{
//   template<typename T>
//   struct Array{
//     using value_type = T;

//     Array(int size) :_size(size) , _arr( new T[size] ){};
    
//     Array& insert(T s){
//       _arr[_index] = s;
//       _index++;
//       return *this;
//     }

//     Array& operator+(T s){
//       return insert(s);
//     }

//     T operator[](unsigned i){
//       return _arr[i];
//     }

//     int operator~(){
//       return _size;
//     }

//     private:
//       int _size;
//       int _index = 0;
//       T* _arr = nullptr;
//   };
// }






namespace oop{
  template<typename T>
  struct Array{
    using value_type=T;
    Array(int size){arr = new T[size];}
    ~Array(){delete arr;}

    Array& insert(T c){
      arr[pos]=c;
      pos++;
      return *this;
      }

    Array& operator+(T c){
      return insert(c);
    }





    int operator~(){return pos+1;}

    T* arr;
    int pos=0;

    T& operator[](int i)const{
      return arr[i];
    }
  };



}

namespace std{
  class vector{};
  class list{};
  class deque{};
  class set{};
  class map{};}

#include<cstdlib>
#include <iostream>

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