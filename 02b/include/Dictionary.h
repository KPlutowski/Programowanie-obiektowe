#pragma once
#include <iostream>
#include <vector>
#include <map>

class Dictionary
{
private:
    std::map<std::string,int> data;
public:
    void add(const std::string& key, int value);
    Dictionary move();
    void remove(const std::string& key);


    int& operator[](const std::string& key);
    const int& operator[](const std::string& key) const;

    friend std::ostream& operator<<(std::ostream& os, const Dictionary& dict);
};

