#include <iostream>
#include <list>

void f1(int a){
    std::cout<<a<<" ";
}
void f2(int a){
    if(a%2==0)
    std::cout<<a<<" ";
}

template <typename T, typename F>
void print_to_if(std::ostream& os, T begin, T end, F fun){
    os;
    for(T iter = begin; iter != end; iter++){
        fun(*iter);
    }
    std::cout << "\n";
}

template<typename T,typename U>
void change(T begin,T end,U f){
    for (T iter = begin; iter != end; iter++)
    {
        (*iter)+=f.get();
    }
}


struct f3
{
    int val;
    f3(int x): val(x){}
    int get(){
        return val;
    }
};



int main(){
    const auto cl = {1,2,3,4,5,6,7};

    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f1);
    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f2);

    int add_value{-1};
    std::list<int> cl2 = {7,6,5,4,3,2,1};
    change(begin(cl2), end(cl2), f3{add_value});
    print_to_if(std::cout << "All  ", begin(cl2), end(cl2), f1);
}
/*
All: 1 2 3 4 5 6 7 
All: 2 4 6 
All  6 5 4 3 2 1 0 
*/