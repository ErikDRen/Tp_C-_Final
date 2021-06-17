#ifndef AIGLE_H
#define AIGLE_H
#include <string>
#include "ianimal.h"

using namespace std;

class Aigle :public IAnimal
{
    string m_name;
    Zoo* m_zoo;
    int id;
    int conso;
    int myage;
    int espVie = 2;
    // bool myfemale;
    // bool myhungry;
    // bool mysexual_maturity;
    // bool mygestation;
public:
    string type = "Aigle";
    Aigle(Zoo* zoo, string type, int id);
    Aigle(Zoo* zoo, string type, string name, int id,int age, bool female, bool hungry, bool sexual_maturity, bool gestation);
    void Eat();
    virtual bool checkAge();
    virtual void Update();
    virtual void fire();
};

#endif // AIGLE_H
