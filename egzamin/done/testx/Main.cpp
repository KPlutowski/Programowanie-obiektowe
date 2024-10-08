#include <iostream>

// struct S
// {
//     S(){std::cout<<"S";}
// };
// struct A:virtual S
// {
//     A(){std::cout<<"A";}
// };
// struct B:virtual S
// {
//     B(){std::cout<<"B";}
// };

// struct D: A, B
// {
//     D(){std::cout<<"D\n";}
// };


struct S
{
    S(){std::cout<<"S";}
};
struct A: S
{
    A(){std::cout<<"A";}
};
struct B:  A
{
    B(){std::cout<<"B";}
};
struct C:  A
{
    C(){std::cout<<"C";}
};

struct X:  B
{
    X(){std::cout<<"X";}
};
struct Y: virtual C
{
    Y(){std::cout<<"Y";}
};
struct D:   Y, virtual X
{
    D(){std::cout<<"D\n";}
};

// SACSABXYD
// 
int main(){
    D d;
}
//SASABC SAC D