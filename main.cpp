#include <iostream>

class GenericCreature
{
public:
    GenericCreature(const std::string &name) : name(name)
    {
        std::cout << "Init construct GenericCreature: " << name << std::endl;
    }
    ~GenericCreature()
    {
        std::cout << "Destructor GenericCreature: " << name << std::endl;
    }
    void exist() const
    {
        std::cout << name << " exists as a generic creature." << std::endl;
    }

protected:
    std::string getName() const { return name; }

private:
    std::string name;
};

class OceanCreature : public GenericCreature
{
public:
    OceanCreature(const std::string &name, bool canSwim)
        : GenericCreature(name), canSwim(canSwim)
    {
        std::cout << "Init construct OceanCreature: " << getName() << std::endl;
    }
    ~OceanCreature()
    {
        std::cout << "Destructor OceanCreature: " << getName() << std::endl;
    }
    void swim() const
    {
        if (canSwim)
            std::cout << getName() << " can swim in the ocean." << std::endl;
        else
            std::cout << getName() << " cannot swim." << std::endl;
    }

private:
    bool canSwim;
};

class Amphibious : public OceanCreature
{
public:
    Amphibious(const std::string &name, bool canSwim, bool canWalk)
        : OceanCreature(name, canSwim), canWalk(canWalk)
    {
        std::cout << "Init construct Amphibious: " << getName() << std::endl;
    }
    ~Amphibious()
    {
        std::cout << "Destructor Amphibious: " << getName() << std::endl;
    }
    void walk() const
    {
        if (canWalk)
            std::cout << getName() << " can walk on land." << std::endl;
        else
            std::cout << getName() << " cannot walk." << std::endl;
    }

private:
    bool canWalk;
};

class TerrestrialCreature : public Amphibious
{
public:
    TerrestrialCreature(const std::string &name, bool canSwim, bool canWalk, bool walksOnTwoLegs)
        : Amphibious(name, canSwim, canWalk), walksOnTwoLegs(walksOnTwoLegs)
    {
        std::cout << "Init construct TerrestrialCreature: " << getName() << std::endl;
    }
    ~TerrestrialCreature()
    {
        std::cout << "Destructor TerrestrialCreature: " << getName() << std::endl;
    }
    void walkOnTwoLegs() const
    {
        if (walksOnTwoLegs)
            std::cout << getName() << " walks on two legs." << std::endl;
        else
            std::cout << getName() << " does not walk on two legs." << std::endl;
    }

private:
    bool walksOnTwoLegs;
};

class Bird : public TerrestrialCreature
{
public:
    Bird(const std::string &name, bool canSwim, bool canWalk, bool walksOnTwoLegs, bool canFly)
        : TerrestrialCreature(name, canSwim, canWalk, walksOnTwoLegs), canFly(canFly)
    {
        std::cout << "Init construct Bird: " << getName() << std::endl;
    }
    ~Bird()
    {
        std::cout << "Destructor Bird: " << getName() << std::endl;
    }
    void fly() const
    {
        if (canFly)
            std::cout << getName() << " can fly in the sky." << std::endl;
        else
            std::cout << getName() << " cannot fly." << std::endl;
    }

private:
    bool canFly;
};

class Waterfowl : public Bird
{
public:
    Waterfowl(const std::string &name, bool canSwim, bool canWalk, bool walksOnTwoLegs, bool canFly)
        : Bird(name, canSwim, canWalk, walksOnTwoLegs, canFly)
    {
        std::cout << "Init construct Waterfowl: " << getName() << std::endl;
    }
    ~Waterfowl()
    {
        std::cout << "Destructor Waterfowl: " << getName() << std::endl;
    }
    void swim() const
    {
        std::cout << getName() << " swims gracefully like a waterfowl." << std::endl;
    }
};

int main()
{
    std::cout << "===================================================" << std::endl;
    GenericCreature multicell("Creature");
    std::cout << "---------------------------------------------------" << std::endl;
    multicell.exist();
    std::cout << "===================================================" << std::endl;
    OceanCreature ocean("Fish", true);
    std::cout << "---------------------------------------------------" << std::endl;
    ocean.exist();
    ocean.swim();
    std::cout << "===================================================" << std::endl;
    Amphibious amphibious("Frog", true, true);
    std::cout << "---------------------------------------------------" << std::endl;
    amphibious.exist();
    amphibious.swim();
    amphibious.walk();
    std::cout << "===================================================" << std::endl;
    TerrestrialCreature terrestrial("Human", false, true, true);
    std::cout << "---------------------------------------------------" << std::endl;
    terrestrial.exist();
    terrestrial.swim();
    terrestrial.walk();
    terrestrial.walkOnTwoLegs();
    std::cout << "===================================================" << std::endl;
    Bird bird("Eagle", false, true, true, true);
    std::cout << "---------------------------------------------------" << std::endl;
    bird.exist();
    bird.swim();
    bird.walk();
    bird.walkOnTwoLegs();
    bird.fly();
    std::cout << "===================================================" << std::endl;
    Waterfowl duck("Duck", true, true, true, true);
    std::cout << "---------------------------------------------------" << std::endl;
    duck.exist();
    duck.swim();
    duck.walk();
    duck.walkOnTwoLegs();
    duck.fly();
    std::cout << "===================================================" << std::endl;

    return 0;
}
