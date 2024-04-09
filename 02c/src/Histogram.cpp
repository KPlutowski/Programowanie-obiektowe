#include "Histogram.h"

Series::Series()
{
}
Series::~Series()
{
    std::cout << "Destruktor klasy Series\n";
}
std::string Series::get_name() const
{
    return _name;
}
void Series::set_name(const std::string &series_name)
{
    _name = series_name;
}
void Series::append(double value)
{
    _values.push_back(value);
}

double &Series::operator[](size_t index)
{
    if (index >= _values.size())
    {
        throw std::out_of_range("Index out of range");
    }
    return _values[index];
}
std::ostream &operator<<(std::ostream &os, const Series &series)
{
    os << "[";
    for (size_t i = 0; i < series._values.size(); i++)
    {
        os << series._values[i] << ',';
    }
    os << "]\n";
    return os;
}
Series &Series::operator+=(const Series &other)
{
    size_t min_size = other._values.size() > this->_values.size() ? this->_values.size() : other._values.size();
    for (size_t i = 0; i < min_size; i++)
    {
        this->_values[i] += other._values[i];
    }
    return *this;
}
Series::Series(const Series &other)
{
    std::cout << "Kopiujący operator przypisania klasy Series" << std::endl;
    _name = other._name;
    _values = other._values;
}

Histogram::Histogram()
{
    std::cout << "Konstruktor klasy Histogram" << std::endl;
}
Histogram::~Histogram()
{
    std::cout << "Destruktor klasy Histogram" << std::endl;
}
void Histogram::add_series(const std::string &name)
{
    Series series;
    series.set_name(name);
    _series_list.push_back(series);
}

Series &Histogram::operator[](const std::string &name)
{
    for (size_t i = 0; i < _series_list.size(); i++)
    {
        if (_series_list[i].get_name() == name)
            return _series_list[i];
    }
    throw std::out_of_range("Series not found");
}
std::vector<std::string> Histogram::get_series_names() const
{
    std::vector<std::string> names;
    for (const auto &series : _series_list)
    {
        names.push_back(series.get_name());
    }
    return names;
}
