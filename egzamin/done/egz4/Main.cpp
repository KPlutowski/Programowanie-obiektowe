#include <iostream> 
#include <cstdlib>
#include <vector>

namespace OOP
{
    template<typename T>
    struct Array
    {
        std::vector<T> vec;
        using value_type = T;
        Array(int size){}

        Array& insert(T c){
            vec.push_back(c);
            return *this;
        }

        int operator~(){
            return vec.size();
        }

        Array& operator%(T next){
            return insert(next);
        }

        T& operator[](int index){
            return vec.at(index);
        }
    };
} // namespace OOP


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