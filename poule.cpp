#include <iostream>
#include "ianimal.h"
#include "poule.h"

using namespace std;

Poule::Poule()
{

}

Poule::Poule(string name)
    :IAnimal(name)
{

}

void Poule::fire()
{
    cout << "Je caquette" << endl;
}