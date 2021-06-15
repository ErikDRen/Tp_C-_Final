#ifndef TIGRE_H
#define TIGRE_H

#include "ianimal.h"

#include <string>

using namespace std;

class Tigre :public IAnimal
{
    Zoo* m_zoo;
    int conso;
    int myage;
    bool myfemale;
    bool myhungry;
    bool mysexual_maturity;
    bool mygestation;
public:
    Tigre(Zoo* zoo);
    Tigre(Zoo* zoo, string name, int age, bool female, bool hungry, bool sexual_maturity, bool gestation);
    void Eat();
    virtual void Update();
    virtual void fire();
    void ifHungry();
    void CheckifHungry();
};

#endif // TIGRE_H
