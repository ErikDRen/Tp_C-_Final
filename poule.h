#ifndef POULE_H
#define POULE_H
#include <string>
#include "ianimal.h"

using namespace std;


class Poule :public IAnimal
{
    int conso;
public:
    Poule();
    Poule(string name);
    virtual void fire();
};

#endif // POULE_H
