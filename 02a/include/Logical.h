#pragma once 

class OneArg
{
public:
    virtual ~OneArg() {}
    virtual  bool result(const bool arg1) const=0;
};
class NOT : public OneArg
{
public:
    bool result(const bool arg1) const override
    {
        return !arg1;
    }
};



class TwoArg
{
public:
    virtual ~TwoArg() {}
    virtual bool result(const bool arg1,const bool arg2) const=0;
};
class OR : public TwoArg
{
public:
    bool result(const bool arg1,const bool arg2) const override
    {
        return arg1||arg2;
    }
};
class AND : public TwoArg
{
public:
    bool result(const bool arg1,const bool arg2) const override
    {
        return arg1&&arg2;
    }
};



namespace Logical
{
    bool eval(const TwoArg& f,const bool arg1,const bool arg2)
    {
        return f.result(arg1,arg2);
    }
    bool eval(const OneArg& f,const bool arg1)
    {
        return f.result(arg1);
    }
}

