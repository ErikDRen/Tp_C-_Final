#ifndef TIGRE_H
#define TIGRE_H

#include "ianimal.h"

#include <string>

using namespace std;

class Tigre :public IAnimal
{
    int id;
    string m_name;
    Zoo* m_zoo;
    int conso;
    int myage;
    int espVie = 3;
    bool myfemale;
    bool myhungry;
    bool mysexual_maturity;
    bool mygestation;
public:
    string type = "Tigre";
    Tigre(Zoo* zoo, string type, int id);
    Tigre(Zoo* zoo, string type,string name, int id,int age, bool female, bool hungry, bool sexual_maturity, bool gestation);
    void Eat();
    virtual bool checkAge();
    virtual void Update();
    virtual void fire();
    void ifHungry();
    void CheckifHungry();
};

#endif // TIGRE_H
