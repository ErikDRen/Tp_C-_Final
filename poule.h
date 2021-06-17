#ifndef POULE_H
#define POULE_H
#include <string>
#include "ianimal.h"

using namespace std;


class Poule :public IAnimal
{
    int id;
    int conso;
    int dayBeforeHungry;
    Zoo* m_zoo;
    string m_name;
    int myage = 0;
    int espVie = 2;
    // bool myfemale;
    // bool myhungry;
    // bool mysexual_maturity;
    // bool mygestation;

    void Eat();
    
public:
    string type = "Poule";
    Poule(Zoo* zoo, string type, int id);
    Poule(Zoo* zoo, string type, string name, int id,int age, bool female, bool hungry, bool sexual_maturity, bool gestation);
    virtual void Update();
    virtual void fire();
    virtual bool checkAge();
};

#endif // POULE_H
