#include <iostream>
#include <string>

class GenericCreature
{
public:
    GenericCreature()
    {
        std::cout << "GenerecCreature constructor was called!" << std::endl;
    }
    ~GenericCreature()
    {
        std::cout << "GenericCreature destructor was called!" << std::endl;
    }

    void live()
    {
        std::cout << "I can live!" << std::endl;
    }
};

class OceanCreature : public GenericCreature
{
public:
    OceanCreature()
    {
        std::cout << "OceanCreature constructor was called!" << std::endl;
    }
    ~OceanCreature()
    {
        std::cout << "OceanCreature destructor was called!" << std::endl;
    }
    void swim()
    {
        std::cout << "I can swim!" << std::endl;
    }
};

class AmphibiousCreature : public OceanCreature
{
public:
    AmphibiousCreature()
    {
        std::cout << "AmphibiousCreature constructor called!" << std::endl;
    }
    ~AmphibiousCreature()
    {
        std::cout << "AmphibiousCreature destructor called!" << std::endl;
    }
    void walk()
    {
        std::cout << "I can walk!" << std::endl;
    }
};

class TerrestrialCreature : protected AmphibiousCreature
{
public:
    TerrestrialCreature()
    {
        std::cout << "TerrestrialCreature constructor was called!" << std::endl;
    }

    ~TerrestrialCreature()
    {
        std::cout << "TerrestrialCreature destructor was called!" << std::endl;
    }
    using AmphibiousCreature::walk;
};

class Bird : public TerrestrialCreature
{
public:
    Bird()
    {
        std::cout << "Bird constructor was called!" << std::endl;
    }
    ~Bird()
    {
        std::cout << "Bird destructor was called!" << std::endl;
    }
    void fly()
    {
        std::cout << "I can fly!" << std::endl;
    }
};

class Waterfowl : public Bird
{
public:
    Waterfowl()
    {
        std::cout << "Waterfowl constructor called!" << std::endl;
    }
    ~Waterfowl()
    {
        std::cout << "Waterfowl destructor called!" << std::endl;
    }
    using OceanCreature::swim;
};

int main()
{
    std::cout << "----------------------------------------------" << std::endl;
    GenericCreature one_cell;
    std::cout << "----------------------------------------------" << std::endl;
    OceanCreature fish;
    fish.swim();
    std::cout << "----------------------------------------------" << std::endl;
    AmphibiousCreature frog;
    frog.swim();
    frog.walk();
    std::cout << "----------------------------------------------" << std::endl;
    TerrestrialCreature some;
    some.walk();
    std::cout << "----------------------------------------------" << std::endl;
    Bird parrot;
    parrot.walk();
    parrot.fly();
    std::cout << "----------------------------------------------" << std::endl;
    Waterfowl duck;
    duck.fly();
    duck.swim();
    duck.walk();
    std::cout << "----------------------------------------------" << std::endl;
    return 0;
}