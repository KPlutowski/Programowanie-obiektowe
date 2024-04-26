#include <iostream>
#include <utility>

template<typename T = float>
struct Type_t
{
	T _v;
	Type_t() = default;
	Type_t(const T& t): _v(t) {}
	operator T&() { return _v; }
};

template<typename Container>
struct ptr
{
	ptr() = default;
	explicit ptr(Container * c): _container(c) {}
	~ptr() = default;

	ptr(const ptr& p) = delete;
	ptr& operator=(const ptr& p) = delete;

	ptr(ptr&& p): ptr(std::move(p._container)) {}
	ptr& operator=(ptr&& p)
	{
		if (this == &p) 
			return *this;

		_container = std::move(p._container);
		p._container = nullptr;

		return *this;
	}

	Container* operator->() const { return _container; }
	Container& operator*() const { return *_container; }

	using value_type = Container;
	Container * _container;
};

int main()
{
    using Float_t = Type_t<>;
    using Test_t = ptr<std::pair<Float_t, Float_t>>;

    Test_t t1{new Test_t::value_type{}};
    // Test_t t2 = t1;                            // BLAD KOMPILACJI
    // Test_t t3; t3 = t1;                        // BLAD KOMPILACJI
    // Test_t t4 = new Test_t::value_type();    // BLAD KOMPILACJI

    (*t1).first = Test_t::value_type::first_type{1};
    t1->second = Test_t::value_type::second_type{3.141};

    Test_t t2;
    t2 = std::move(t1);
    std::cout << (*t2).first << ", " << t2->second._v << "\n";

    const Test_t t3 = std::move(t2);
    // (*t3).first = 13;       //  BLAD KOMPILACJI
    // t3->second = 13;        //  BLAD KOMPILACJI

    std::cout << (*t3).first._v << ", " << t3->second << "\n";
}
/* output:
1, 3.141
1, 3.141
*/