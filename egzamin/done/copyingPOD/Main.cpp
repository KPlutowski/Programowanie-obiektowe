//2017 1)

#include <iostream>
#include <array>
#include <vector>

struct A{
    int a;
};

struct B {
    virtual void f(){}
    int a;
};


template<typename T> 
void memcopy( T src[], T dst[], size_t size){
  std::string str = std::is_pod<T>::value ? "POD" : "non-POD";
  std::cout<<"Copying "<< str <<" type.\n";
  for(int i = 0 ; i < size; i++)
    dst[i] = src[i];
} 

template<typename T> 
void test() { 
    T src[10] = {}, dst[10];
    std::cout<< typeid(T).name() << " is_pod = "<< std::is_pod<T>::value << ", ";
    memcopy(src, dst, sizeof(src)/sizeof(T));
}














// struct A{ // POD

// };

// struct B{
//     virtual ~B(){} // nie jest POD
// };


// template<typename T>
// void test(){
//     std::cout<<typeid(T).name()<< " is_pod = "<<std::is_pod<T>::value<<", ";

//     if(std::is_pod<T>::value)
//     {
//         std::cout<<"Copying POD type.\n";
//     }
//     else
//         std::cout<<"Copying non-POD type.\n";

// }

int main() {
    test<A>();
    test<B>();
    test<std::array<A,10>>();
    test<std::vector<A>>();
    return 0;
}

// A is_pod = 1, Copying POD type.
// B is_pod = 0, Copying non-POD type.
// std::array<A,10> is_pod = 1, Copying POD type.
// std::vector<A> is_pod = 0, Copying non-POD type.