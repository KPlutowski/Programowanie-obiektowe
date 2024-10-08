#include <iostream>
#include <utility>


template<typename T=float>
struct Type_t{
    T _v;
    explicit Type_t(T val=0):_v(val){}


    friend std::ostream& operator<<(std::ostream& os,Type_t& t){
        os<<t._v;
        return os;
    }
    
};

template<typename T>
struct ptr{
    using value_type = T;
    T* _p;
    explicit ptr(T *p):_p(p){}
    ~ptr(){delete _p;}
    ptr(const ptr&)=delete;
    ptr operator=(const ptr&)=delete;
    ptr operator=(const ptr&&)=delete;


    T& operator*()const{
        return *_p;
    }
    T* operator->()const{return _p;}

    ptr(ptr&& other){
        this->_p=other._p;
        other._p=nullptr;
    }
};


using Float_t = Type_t<>;


int main()
{
    using Type_t = ptr<std::pair<Float_t, Float_t>>;

    Type_t t1{new Type_t::value_type{}};
    // Type_t t2 = t1;
    // Type_t t5; t5 = t1;
    // Type_t t5 = new Type_t::value_type();
    // Powyższe się mają nie kompilować
    (*t1).first = Type_t::value_type::first_type{1.};
    t1->second = Type_t::value_type::second_type{2.5};

    Type_t t2 = std::move(t1);

    const Type_t t3{new Type_t::value_type{}};     
    // t3=std::move(t2); 
    // (*t3).first= 13;
    // t3->second = 13;
    // Powyższe się mają nie kompilować
    (*t3).first = Type_t::value_type::first_type{1};  
    t3->second = Type_t::value_type::second_type{2.5};

    
    std::cout << (*t3).first._v << ", " << t3->second << std::endl;
}
/* output:
1, 2.5
*/