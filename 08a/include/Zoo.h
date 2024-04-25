#pragma once
#include <vector>
#include <iostream>
#include <algorithm>




class Animal
{
private:
    /* data */
public:
    virtual void roar() const=0;
    virtual void display() const=0;
    virtual void climb() const=0;
    virtual ~Animal(){};
};


class Lion:public Animal
{
public:
    void roar() const override {
        std::cout << "Roarrr, I am a lion!" << std::endl;
    }

    void display() const override {
        std::cout << "It's a Lion" << std::endl;
    }

    void climb() const override {
        std::cout << "I am not able to climb!" << std::endl;
    }
};

class Tiger:public Animal
{
public:
     void roar() const override {
        std::cout << "Roarrr, I am a tiger!" << std::endl;
    }

    void display() const override {
        std::cout << "It's a Tiger" << std::endl;
    }

    void climb() const override {
        std::cout << "I am able to climb!" << std::endl;
    }
};

class Liger:public Lion,public Tiger
{
public:

    void roar() const override {
        std::cout << "Roarrr, I am a liger!" << std::endl;
    }

    void display() const override {
        std::cout << "It's a Liger" << std::endl;
    }
    void climb() const override {
        Tiger::climb();
    }

};






class Zoo
{
private:
    std::vector<Animal*> animals;
public:

    void addAnimal(Animal *animalToAdd){animals.push_back(animalToAdd);};

    void makeAllAnimalsRoar() const 
    {
        std::for_each(animals.begin(), animals.end(), [](const Animal* animal) { animal->roar(); });
    }
    void displayAnimals() const {
        std::for_each(animals.begin(), animals.end(), [](const Animal* animal) {
            animal->display();
            animal->climb();});
    }

   
};
