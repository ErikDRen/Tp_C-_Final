#pragma once

#include "IAnimal.h"
#include <vector>
#include <iostream>

using namespace std;
class IAnimal;
typedef vector<IAnimal *> Animalist;
typedef Animalist::iterator AnimalIterator;

class Zoo
{

public:
    // void virtual leave(IAnimal * animal);
    void virtual fire();
    void virtual startSimulation();
    void virtual add(IAnimal * animal);
    void virtual buyAnimal(IAnimal * animal);
    void virtual sellAnimal(IAnimal* animal);

private:
    Animalist liste_animal;
    int meat = 0;
    int seed = 0;
};