#pragma once
#include "File.h"

class Dir : public FSElement
{
private:
    std::string name;
    std::vector<std::unique_ptr<FSElement>> elements;

public:
    Dir(const std::string &name) : name(name) {}
    ~Dir()
    {
        // for (FSElement *elem : elements)
        // {
        //     delete elem;
        // }
    }
    
    Type getType() const override {
        return Type::Dir;
    }
    std::string getName() const override
    {
        return name;
    }
    
    void add(FSElement* element) {
        elements.emplace_back(element);
    }
    Dir& operator+=(FSElement* element) {
        add(element);
        return *this;
    }



    Dir* findDir(const std::string& dirName) const 
    {
        for (const auto& elem : elements)
        {
            if (elem->getType()==Type::Dir)
            {
                if (elem->getName() == dirName || static_cast<Dir*>(elem.get())->findDir(dirName) )
                {
                    std::cout<<static_cast<Dir*>(elem.get())->getName()<<std::endl;
                    return static_cast<Dir*>(elem.get());
                }
            }
        }
        return nullptr;
    }

    
    
    void listDirs(int depth, int currentDepth = 0) const {
        if (currentDepth > depth) return;

        for (const auto& elem : elements) {
            if (elem->getType()==Type::Dir) {
                std::cout << elem->getName() << " ";
                if (currentDepth < depth) {
                    static_cast<Dir*>(elem.get())->listDirs(depth, currentDepth + 1);
                }
            }
        }
        if (currentDepth == 0) std::cout << std::endl;  // Newline after top level call
    }



    friend std::ostream &operator<<(std::ostream &os, const Dir &dir)
    {
        os << dir.name << " (DIR)\n";
        for (const auto& elem : dir.elements)
        {
            
            if (elem->getType()==Type::Dir)
            {
                os << "  " << *static_cast<Dir*>(elem.get());
            }
            else
            {
                os << "  " << elem->getName() << " (FILE)\n";
            }
        }
        return os;
    }

    };
