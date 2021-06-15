#ifndef POULE_H
#define POULE_H
#include <string>
#include "ianimal.h"

using namespace std;


class Poule :public IAnimal
{
    int conso;
    int dayBeforeHungry;
    Zoo* m_zoo;
    string m_name;
    // int myage;
    // bool myfemale;
    // bool myhungry;
    // bool mysexual_maturity;
    // bool mygestation;
public:
    Poule(Zoo* zoo);
    Poule(Zoo* zoo, string name, int age, bool female, bool hungry, bool sexual_maturity, bool gestation);
    void Eat();
    virtual void Update();
    virtual void fire();
};

#endif // POULE_H
