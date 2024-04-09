#include "PointSmartPtr.h"

// Named
Named::Named(const std::string &name) : _name(name) {}
const std::string &Named::Name() const { return _name; }
void operator>>(std::string is, Named &named) { named._name = is; }

// Point
Point::Point(int x, int y, const std::string &name) : Named(name), _x(x), _y(y) {}
Point Point::operator++(int)
{
    Point temp = *this;
    ++this->_x;
    ++this->_y;
    return temp;
}
std::ostream &operator<<(std::ostream &os, const Point &point)
{
    os << point.Name() << " [" << point._x << ',' << point._y << ']';
    return os;
}

// PointSmartPtr
PointSmartPtr::PointSmartPtr(Point *ptr) : _point_ptr(ptr), _count_ptr(new int(1)) {}
PointSmartPtr::~PointSmartPtr() { release(); }
PointSmartPtr::PointSmartPtr(const PointSmartPtr &other) : _point_ptr(other._point_ptr), _count_ptr(other._count_ptr) { (*_count_ptr)++; }
PointSmartPtr &PointSmartPtr::operator=(const PointSmartPtr &other)
{
    if (this != &other)
    {
        this->release();
        _point_ptr = other._point_ptr;
        _count_ptr = other._count_ptr;
        (*_count_ptr)++;
    }
    return *this;
}
void PointSmartPtr::release()
{
    (*_count_ptr)--;
    if (*_count_ptr <= 0)
    {
        delete _point_ptr;
        delete _count_ptr;
    }
}
Point &PointSmartPtr::operator*() { return *_point_ptr; }