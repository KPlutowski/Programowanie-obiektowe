#include "Dictionary.h"

void Dictionary::add(const std::string& key, int value)
{
    data[key]=value;
}
Dictionary Dictionary::move()
{
   return std::move(*this);
}
void Dictionary::remove(const std::string& key)
{
    data.erase(key);
}


int& Dictionary::operator[](const std::string& key)
{
    return data[key];
}
const int& Dictionary::operator[](const std::string& key) const
{
    return data.at(key);
}

std::ostream& operator<<(std::ostream& os, const Dictionary& dict)
{
    os<<dict;
    return os;
}