// 2017 2)

#include <iostream>

// struct is_printable{
//   friend std::ostream& operator << (std::ostream& s, const is_printable& o){
//       return s<<o.print();
//   }
//   virtual std::string print() const = 0;
// };

// struct A : is_printable{
//   A(std::string a) : text(a){};
//   std::string print() const override{
//     return text;
//   }
//   std::string text;
// };

// struct B : is_printable{
//   B(int a) : nr(a){};
//   std::string print() const override{
//     return std::to_string(nr);
//   }
//   int nr;
// };

// std::ostream& operator << (std::ostream& s, const is_printable& o);








struct is_printable
{
  virtual std::string getText() const = 0;
  friend std::ostream &operator<<(std::ostream &os, is_printable &t)
  {
    os << t.getText();
    return os;
  }
};

struct A : is_printable
{
  A(std::string t) { text = t; }
  std::string getText() const{return text;}
private:
  std::string text;
};

struct B : is_printable
{
  B(int t) { text = std::to_string(t); }
  std::string getText() const{return text;}
private:
  std::string text;
};

int main()
{
  A a{"Tekst"};
  B b{123};

  std::cout << "a=" << a << ";\tb=" << b << ";\n";
  is_printable &a_r = a;
  is_printable &b_r = b;
  std::cout << "a_r=" << a_r << ";\tb_r=" << b_r << ";\n";

  return 0;
}

// a: Tekst; b: 123
// a_r: Tekst b_r: 123