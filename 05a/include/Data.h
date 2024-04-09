#pragma once
#include <iostream>

class Data
{
private:
    /* data */
public:
    virtual void print() const = 0;
    virtual Data* clone() const =0;
    virtual ~Data(){};
};


class IntData : public Data
{
private:
    int value;
public:
    IntData(const int val):value(val){};
    void print() const{std::cout<<value;}
    
    // copy constructor
    IntData(const IntData& other):value(other.value){};
    Data* clone() const{return new IntData(*this);}

    ~IntData()
    {
        std::cout<<"~IntData()\n";
    }
};


class StringData : public Data
{
private:
    std::string value;
public:
    StringData(const std::string val):value(val){};
    void print() const {std::cout<<value;}
    
    StringData(const StringData& other):value(other.value){};
    Data* clone() const{return new StringData(*this);}

    ~StringData()
    {
        std::cout<<"~StringData()\n";
    }
};