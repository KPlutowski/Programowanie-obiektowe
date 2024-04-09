#pragma once
#include <iostream>
#include <string>

class Named
{
private:
    std::string _name;

public:
    Named(const std::string &name = "None");

    const std::string &Name() const;
    friend void operator>>(std::string is, Named &named);
};

class Point : public Named
{
private:
    int _x;
    int _y;

public:
    Point(int x = 0, int y = 0, const std::string &name = "None");

    friend std::ostream &operator<<(std::ostream &os, const Point &point);
    Point operator++(int);
};

class PointSmartPtr : public Point
{
private:
    Point *_point_ptr = nullptr;
    int *_count_ptr = nullptr;

public:
    PointSmartPtr(Point *ptr);
    ~PointSmartPtr();
    PointSmartPtr(const PointSmartPtr &other);

    PointSmartPtr &operator=(const PointSmartPtr &other);
    void release();
    Point &operator*();
};
