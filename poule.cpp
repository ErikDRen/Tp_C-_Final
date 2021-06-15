#include <iostream>
#include "ianimal.h"
#include "poule.h"

using namespace std;

Poule::Poule(Zoo* zoo)
    :IAnimal(zoo)
{
    m_zoo = zoo;
    conso = 8;
    dayBeforeHungry = 2;
}

Poule::Poule(Zoo* zoo, string name ,int age,bool female,bool hungry,bool sexual_maturity,bool gestation)
    :IAnimal(zoo, name,age,female, hungry,sexual_maturity, gestation)
{
    m_zoo = zoo;
    m_name = name;
    conso = 8;
    dayBeforeHungry = 2;
}

void Poule::Update()
{
    Eat();
}

void Poule::Eat() {
    m_zoo->decreaseSeeds(conso);
}
void Poule::fire()
{
    cout << m_name << " caquette" << endl;
}