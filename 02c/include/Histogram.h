#pragma once
#include <iostream>
#include <vector>

class Series
{
private:
    std::string _name;
    std::vector<double> _values;
public:
    Series();
    ~Series();
    Series(const Series &other);

    void append(double value);
    std::string get_name() const;
    void set_name(const std::string& series_name);

    double& operator[](size_t index);
    friend std::ostream& operator<<(std::ostream& os, const Series& series);
    Series& operator+=(const Series& other);
};

class Histogram
{
private:
    std::vector<Series> _series_list;
public:
    Histogram();
    ~Histogram();

    void add_series(const std::string &name);
    std::vector<std::string> get_series_names() const;

    Series &operator[](const std::string &name);
};