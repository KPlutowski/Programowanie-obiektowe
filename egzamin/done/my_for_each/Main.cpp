// 2017 2 termin 1)

#include <iostream>
// template<typename T1, typename T2>
// void my_for_each(T1 begin, T1 end, T2 fun) {
//     for(T1 iterator = begin; iterator != end; iterator++){
//         fun(&(*iterator));
//     }
// }

// struct dupa{
//     void operator()(){
//         std::cout<<"\n";
//     }
// };

// int main() {
//     using namespace std;

//     int c[] = { 1, 2, 3, 4, 5 };

//     auto print = [](int* el){ cout<<*el<<" ";};
//     auto print_eol = dupa(); //[](){ cout<<"\n";};
//     my_for_each(begin(c), end(c), print);
//     print_eol();

//     int add_value = 1;
//     auto add = [&add_value](int *el){ *el += add_value; };
//     my_for_each(begin(c), end(c), add);
//     my_for_each(begin(c), end(c), print);
//     print_eol();

//     add_value = 10;

//     my_for_each(begin(c), end(c), add);
//     my_for_each(begin(c), end(c), print);
//     print_eol();

//     return 0;
// }








template<typename I,typename F>
void my_for_each(I begin,I end, F func){
    for(I i = begin;i!=end;i++){
       func(*i);
    }
}

int main() {
    using namespace std;

    int c[] = { 1, 2, 3, 4, 5 };

    auto print = [](int el){ cout<<el<<" ";};
    auto print_eol = [](){ cout<<"\n";};
    my_for_each(begin(c), end(c), print);
    print_eol();

    int add_value = 1;
    auto add = [&add_value](int& i){i+=add_value;};
    my_for_each(begin(c), end(c), add);
    my_for_each(begin(c), end(c), print);
    print_eol();

    add_value = 10;

    my_for_each(begin(c), end(c), add);
    my_for_each(begin(c), end(c), print);
    print_eol();

    return 0;
}


/* 
    1 2 3 4 5
    2 3 4 5 6
    12 13 14 15 16 
*/


