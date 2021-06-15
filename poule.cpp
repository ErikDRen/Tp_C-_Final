#include <iostream>
#include "ianimal.h"
#include "poule.h"

using namespace std;

Poule::Poule()
{
    conso = 8;
}

Poule::Poule(string name)
    :IAnimal(name)
{
    conso = 8;
}

void Poule::fire()
{
    cout << "Je caquette" << endl;
}