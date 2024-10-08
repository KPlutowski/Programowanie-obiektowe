// 2021 1 termin 1) (podobne do 2017 2 termin 2))

#include <iostream> 
#include <cstdlib>
#include <vector>

// namespace OOP{ // tworzymy namespace bo potem wyciągamy z niego ten szablon
//     template<typename T>
//     struct Array{
//         using value_type = T;
//         Array(int size){}
        
//         Array& insert(char x){
//             _vec.push_back(static_cast<int>(x));
//             return *this;
//         }

//         Array& operator%(char x){
//             return insert(x);
//         }

//         T& operator[](int index){
//             return _vec.at(index);
//         }
//         int operator ~(){
//             return _vec.size();
//         }

//         private:
//             std::vector<T> _vec;
//     };
// }
















namespace OOP{
    template<typename T>
    struct Array{
        using value_type = T;
        Array(size_t size=0){
            _arr=new T[size];
            _pos=0;
            _size=size;
        }
        ~Array(){delete _arr;}
        
        Array& insert(T c){
            _arr[_pos]=c;
            _pos++;
            return *this;
        }
        Array& operator%(const T& c){
            return this->insert(c);
        }

        T* _arr;
        size_t _pos=0;
        size_t _size;

        T& operator[](size_t pos){
            return _arr[pos];
        }
        size_t operator~(){return _pos+1;}
        
    };
}

int main()
{
    typedef ::OOP::Array<int> type;
    type a(rand() % 100 + 10); // nie trzeba seedować żeby program się wykonał

    a.insert('#' - 1).insert('P') % type::value_type('O') % ('-') % ('E') % ('G') % ('Z') % ('1');

     ++a[0];
    for (unsigned i = 0; i != ~a; i++){
        std::cout << static_cast<char>(a[i]) << (i + 1 != ~a ? '_' : '\n');
    }
}
//#_P_O_-_E_G_Z_1