#ifndef AIGLE_H
#define AIGLE_H
#include <string>
#include "ianimal.h"

using namespace std;

class Aigle :public IAnimal
{
    Zoo* m_zoo;
    int conso;
    // int myage;
    // bool myfemale;
    // bool myhungry;
    // bool mysexual_maturity;
    // bool mygestation;
public:
    Aigle(Zoo* zoo);
    Aigle(Zoo* zoo, string name, int age, bool female, bool hungry, bool sexual_maturity, bool gestation);
    void Eat();
    virtual void Update();
    virtual void fire();
};

#endif // AIGLE_H
