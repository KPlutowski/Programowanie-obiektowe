#pragma once

class Calculator
{
private:
    int calc_value=0;
public:
    Calculator()=default;

    int operator()() const {return calc_value;}
    Calculator& operator=(int value) {calc_value=value; return *this;}
    Calculator operator++()
    {
        ++calc_value;
        return *this;
    }
    Calculator operator--()
    {
        --calc_value;
        return *this;
    }
    Calculator& operator*(int value) 
    {
        calc_value*=value;
        return *this;
    }
    int operator()(std::function<int(int, int)> f,int x,int y) {return f(x,y);}
    int operator()(std::function<int(int)> f) {return f(calc_value);}
    int operator()(std::function<int(int,int)> f,int x) {return f(x,calc_value);}

    Calculator operator++(int)
    {
        Calculator tmp =*this;
        calc_value++;
        return tmp;
    }
    Calculator operator--(int)
    {
        Calculator tmp =*this;
        calc_value--;
        return tmp;
    }
    friend std::ostream& operator<<(std::ostream& os,const Calculator& calculator) 
    {
        os<<calculator();
        return os;
    }
    ~Calculator()=default;


    friend Calculator& operator*(int value,Calculator& calculator);
};
Calculator& operator*(int value,Calculator& calculator)
{
    calculator.calc_value*=value;
    return calculator;
}