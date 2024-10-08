// 2018 2 termin 2)


// template<typename T>
// struct ptr{
//     ptr(){};

//     explicit ptr(T* a) :_p(a){};

//     ptr(const ptr& x) = delete;

//     T operator*() const{
//         return *_p;
//     }

//     T* operator->() const{
//         return _p;
//     }

//     T& operator++(){
//         (*_p)++;
//         return *this;
//     }

//     bool operator==(ptr<T> other) const{
//         if(other._p == nullptr) return false;
//         return (*_p).i == (*(other._p)).i;
//     }

//     bool operator!=( ptr<T> other) const{
//         if(other._p == nullptr) return true;
//         return (*_p).i != (*(other._p)).i;
//     }

//     private:
//         T* _p = nullptr;
// };

// struct A { int i = 1; };





#include<iostream>
namespace std {class auto_ptr{}; class unique_ptr{}; class shared_ptr{} ; }

template<typename T>
struct ptr{
    ~ptr() {delete _p;}

    explicit ptr(T* newPtr=nullptr) {_p=newPtr;}

    ptr operator=(const ptr&)=delete;
    ptr(const ptr&)=delete;
    

    T operator*()const{return *_p;}
    T* operator->()const{return _p;}

    T& operator++(){_p->i++;return *this;}

    bool operator==(const ptr& other)const{
        return other._p==_p;
    }
    bool operator!=(const ptr& other)const{
        return other._p!=_p;
    }

    private:
        T* _p;
};

struct A{
    int i = 1;
};

int main() {
    const ptr<A>  a(new A);
    const ptr<A> b;
    ptr<A> c(new A);

    //ptr<A>  _b_error = new A;      // Odkomentowanie powoduje błąd kompilacji 
    //a = a;               // Odkomentowanie powoduje błąd kompilacji 
    //const ptr<A> _c_error = a;     // Odkomentowanie powoduje błąd kompilacji 

     std::cout << ((*a).i, a->i)<<" "<< ++c->i<<" ";
     std::cout << (a == ptr<A>() )<<" "<< (a != b)<<"\n";
}
/* output/wyjście:
1 2 0 1
*/ 