#pragma once

#include <iostream>

class Complex {
public:
    Complex(double real, double imag) : real_(real), imag_(imag) {}

    double getReal() const { return real_; }
    double getImag() const { return imag_; }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c)
    {
        os << "(" << c.getReal() << ", " << c.getImag() << "i)";
        return os;
    }

private:
    double real_;
    double imag_;
};

// Template function for adding two numbers
template<typename T>
T add(T* a, T* b) {
    return *a + *b;
}

// Template function for multiplying two numbers
template<typename T>
T multiply(T* a, T* b) {
    return (*a) * (*b);
}

// Template specialization for adding two complex numbers
template<>
Complex add(Complex* a, Complex* b) {
    return Complex(a->getReal() + b->getReal(), a->getImag() + b->getImag());
}

// Template specialization for multiplying two complex numbers
template<>
Complex multiply(Complex* a, Complex* b) {
    double real = a->getReal() * b->getReal() - a->getImag() * b->getImag();
    double imag = a->getReal() * b->getImag() + a->getImag() * b->getReal();
    return Complex(real, imag);
}