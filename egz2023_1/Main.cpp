#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> c = {1,2,3,4,5,6,7};

    std::cout << "c: ";
    std::for_each(c.begin(), c.end(),[](int x){std::cout<<x<<" ";});

    std::cout << "\nc parzyste: ";
    std::for_each(c.begin(), c.end(), [](int x){
        if(!(x%2))std::cout<<x<<" ";});

    std::cout << "\nc malejaco: ";
    std::sort(c.begin(), c.end(), [](int x,int y){return x>y;});
    std::for_each(c.begin(), c.end(), [](int x){std::cout<<'['<<x<<"] ";});

    std::cout << "\nc + x: ";
    int x=5;
    std::for_each(c.begin(), c.end(),[x](int &c){c+=x;});
    std::for_each(c.begin(), c.end(), [](int c){std::cout<<c<<", ";});

    auto f = [&x](int c)mutable{x+=c;return x;};
    std::cout << "\nx: " << x << " ";
    std::cout << "f: " << f(6) << " ";
    std::cout << "x: " << x << std::endl;
}
/*
c: 1 2 3 4 5 6 7 
c parzyste: 2 4 6 
c malejaco: [7] [6] [5] [4] [3] [2] [1] 
c + x: 12, 11, 10, 9, 8, 7, 6, 
x: 5 f: 11 x: 11
*/