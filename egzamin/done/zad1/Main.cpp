#include<iostream>
#include<vector>
class Base{
public:
    virtual std::ostream& print(std::ostream&os) const=0;
    friend std::ostream& operator<<(std::ostream & os,Base& a){
        a.print(os);
        return os;
    }
};

class Derived1 : public Base
{
    public:
    std::ostream& print(std::ostream&os) const{
        return os<<__PRETTY_FUNCTION__;
    }
};

class Derived2 : public Base
{
    public:
    std::ostream& print(std::ostream&os) const{
        return os<<__PRETTY_FUNCTION__;
    }
};

class Derived3 : public Derived2
{
    public:
    std::ostream& print(std::ostream&os) const{
        return os<<__PRETTY_FUNCTION__;
    }
};

std::ostream& operator<<(std::ostream& os, std::vector<Base*>& v){
    std::cout<<"[\n";
    for(int i =0;i<v.size()-1;i++)
    {
        v[i]->print(os);
        std::cout<<", \n";
    }
    v[v.size()-1]->print(os);
    os<<"\n]\n";
    return os;
}



int main(){
    Derived1 d1;
    Derived3 d3;
    Derived2 d2 = d3;
    // Derived1 d1_make_err = d2;

    // std::vector<Base> v_make_err = {d1, d2, d3};
    std::vector<Base*> v = {&d1, &d2, &d3};

    std::cout << *v.front()<<std::endl;
    std::cout << v;
}

/*Wynik:
virtual std::ostream& Derived1::print(std::ostream&) const
[
virtual std::ostream& Derived1::print(std::ostream&) const,
virtual std::ostream& Derived2::print(std::ostream&) const,
virtual std::ostream& Derived3::print(std::ostream&) const
]
*/