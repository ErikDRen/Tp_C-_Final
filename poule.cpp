#include <iostream>
#include "ianimal.h"
#include "poule.h"

using namespace std;

Poule::Poule(Zoo* zoo ,string type, int id)
    :IAnimal(zoo, type, id)
{
    myage = 0;
    m_zoo = zoo;
    conso = 8;
    dayBeforeHungry = 2;
    //id = m_zoo->GetCount();
}

Poule::Poule(Zoo* zoo, string type, string name ,int id,int age,bool female,bool hungry,bool sexual_maturity,bool gestation)
    :IAnimal(zoo, type, name,id,age,female, hungry,sexual_maturity, gestation)
{
    myage = age;
    m_zoo = zoo;
    m_name = name;
    conso = 8;
    dayBeforeHungry = 2;
    //id = m_zoo->GetCount();
}

void Poule::Update()
{
    Eat();
    myage++;
}

bool Poule::checkAge() {
    if (myage > espVie) {
        return false;
    }
    return true;
}

void Poule::Eat() {
    m_zoo->decreaseSeeds(conso);
}
void Poule::fire()
{
    cout << m_name << " caquette : "  << "id: "<< this->GetId() << " " << "age: " << myage << " " << "espVie: " << espVie << endl;
}