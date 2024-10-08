#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

template <typename T>
class MyContainer
{
private:
    std::vector<T> elements;

public:
    void add(const T &element)
    {
        elements.push_back(element);
    }

    void remove(int index)
    {
        if (index >= 0 && index < elements.size())
        {
            elements.erase(elements.begin() + index);
        }
        else
        {
            std::cerr << "Index out of range\n";
        }
    }

    T get(int index) const
    {
        return elements.at(index);
    }

    int size() const
    {
        return elements.size();
    }

    void print() const
    {
        for (const auto &element : elements)
        {
            if constexpr (std::is_pointer<T>::value)
            {
                std::cout << *element << " ";
            }
            else
            {
                std::cout << element << " ";
            }
        }
        std::cout << std::endl;
    }


    template<typename U>
        MyContainer<U> cast() const {
            MyContainer<U> newContainer;
            for (const auto& element : elements) {
                newContainer.add(static_cast<U>(element));
            }
            return newContainer;
    }
    
    //     // Print for non-pointer types
    // template<typename U = T>
    // typename std::enable_if<!std::is_pointer<U>::value>::type print() const {
    //     for (const auto& element : elements) {
    //         std::cout << element << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // // Print for pointer types
    // template<typename U = T>
    // typename std::enable_if<std::is_pointer<U>::value>::type print() const {
    //     for (const auto& element : elements) {
    //         std::cout << *element << " ";
    //     }
    //     std::cout << std::endl;
    // }
};



// /////////////////// specialization:
// template <class T>
// class Test
// {
//   // Data members of test
// public:
//    Test()
//    {
//        // Initialization of data members
//        cout << "General template object \n";
//    }
//    // Other methods of Test
// };
 
// template <>
// class Test <int>
// {
// public:
//    Test()
//    {
//        // Initialization of data members
//        cout << "Specialized template object\n";
//    }
// };
 

//  //////////////////////////////
//  template <class T>
// void fun(T a)
// {
//    cout << "The main template fun(): "
//         << a << endl;
// }
 
// template<>
// void fun(int a)
// {
//     cout << "Specialized Template for int type: "
//          << a << endl;
// }
 