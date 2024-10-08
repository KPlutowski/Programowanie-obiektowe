#include <iostream>
#include <string>



struct is_printable
{
  virtual void print(std::ostream& os) const =0;
};
class A:public is_printable
{
private:
  std::string text;
public:
  A(std::string txt):text(txt) {}

  void print(std::ostream& os) const{
    os<<text;
  }
};

class B:public is_printable
{
private:
  int x;
public:
  B(int a):x(a){};
  void print(std::ostream& os) const{
    os<<x;
  }

};

std::ostream& operator<<(std::ostream& os, const is_printable& obj){
    obj.print(os);
    return os;
  }

int main()
{
  A a ("Tekst"); B b {123};
  std::cout<< "a:\t"<<a<<"; b:\t"<<b<<"\n";
  const is_printable & a_r = a; const is_printable & b_r = b;
   std::cout<< "a_r:\t"<<a_r<<"; b_r:\t"<<b_r<<"\n";
}

/*
a:      Tekst; b:       123
a_r:    Tekst; b_r:     123
*/