#include <iostream>
#include <utility>

template<typename T=float>
struct Type_t{
    explicit Type_t(T value = 0) : _v(value){}

    T _v;

    friend std::ostream& operator<<(std::ostream& os, Type_t& a){
        os<<a._v;
        return os;
    }

};



template<typename T>
struct ptr{
    using value_type = T;

    explicit ptr(T* p=nullptr) : _p(p){}

    ptr(ptr&)=delete; // konstruktor kopiujacy
    ptr operator=(ptr&)=delete; // operator kopiujacy

    T& operator*()const {return *_p;}
    T* operator->()const{return _p;}

    void operator=(ptr&& other){
        _p=std::move(other._p);
    }

    ptr(ptr&& other){
        _p=std::move(other._p);
    }


    private:
        T* _p;
};



int main()
{
    using Float_t = Type_t<>;
    using Test_t = ptr<std::pair<Float_t, Float_t>>;

    Test_t t1{new Test_t::value_type{}};
    // Test_t t2 = t1;                            // BLAD KOMPILACJI
    // Test_t t3; t3 = t1;                        // BLAD KOMPILACJI
    // Test_t t4 = new Test_t::value_type();    // BLAD KOMPILACJI

    (*t1).first = Test_t::value_type::first_type{1};
    t1->second = Test_t::value_type::second_type{3.141};

    Test_t t2;
    t2 = std::move(t1);
    std::cout << (*t2).first << ", " << t2->second._v << "\n";

    const Test_t t3 = std::move(t2);
    // (*t3).first = 13;       //  BLAD KOMPILACJI
    // t3->second = 13;        //  BLAD KOMPILACJI

    std::cout << (*t3).first._v << ", " << t3->second << "\n";
}
/* output:
1, 3.141
1, 3.141
*/