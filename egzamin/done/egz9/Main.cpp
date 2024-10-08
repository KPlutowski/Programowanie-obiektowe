#include <iostream>

using namespace std;

class A
{
private:
    int _a=0;
    int _b=0;
public:
    A(int a=0,int b=0)
    {
        cout<< __PRETTY_FUNCTION__ << "_a="<<_a<<", _b="<<_b<<"\n";
    }
    A(A&& other)
    {
        this->_a=other._a;
        this->_b=other._b;
        cout<< __PRETTY_FUNCTION__ << "_a="<<_a<<", _b="<<_b<<"\n";

    }
};





int main()
{
    cout << "a->"; A a;
    cout << "b->"; A b(1);
    cout << "c->"; A c(1,2);

    cout << "d->"; A d = std::move(c);

    //A e = c;
    //A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[...]: _a=1,_b=2
*/