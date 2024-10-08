#include <iostream>


template<typename T>
struct B{
    T _x;
    B(int x):_x(x){}
    T get()const{
        return _x;
    }
};

template<typename T>
struct B<T*>
{
    T* _x;
    using value_type = T;
    B(T* x):_x(x){}
    T get() const {return *_x;}

    B(const B<T*>& )=delete;
    B<T*>& operator=(const B<T*>&)=delete;

};


int main()
{
    typedef B<int> int_b;
    typedef B<int*> int_p_b;        //jednak typedef

    int_b a(1);
    int_b a_copy(a);
    int_p_b b(new int_p_b::value_type{2});
    // int_p_b e = b; //error
    // b=b //error
    
    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
    std::cout << "b=" << b.get()+1 << std::endl;
}
/*

a=1
a_copy=2
b=3
 
*/