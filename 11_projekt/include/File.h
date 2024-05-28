#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>



class FSElement {
public:
    enum class Type { Dir, File };
    virtual ~FSElement() = default;
    virtual Type getType() const = 0;
    virtual std::string getName() const = 0;
    virtual void listDirs(int depth, int currentDepth = 0) const = 0;
};

class File : public FSElement
{
private:
    std::string name;

public:
    File(const std::string& name) : name(name) {}
    
    Type getType() const override {
        return Type::File;
    }
    
    std::string getName() const override {
        return name;
    }

    void listDirs(int depth, int currentDepth = 0) const override {
        // Do nothing, since it's a file
    }
};
