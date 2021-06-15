#include <iostream>
#include "ianimal.h"
#include "aigle.h"
using namespace std;
Aigle::Aigle(Zoo* zoo)
    :IAnimal(zoo)
{
    m_zoo = zoo;
    conso = 1;
}


Aigle::Aigle(Zoo* zoo, string name,int age,bool female,bool hungry,bool sexual_maturity,bool gestation)
    :IAnimal(zoo, name,age,female,hungry,sexual_maturity,gestation)
{
    m_zoo = zoo;
    conso = 1;
}

void Aigle::Update()
{
    Eat();
}

void Aigle::Eat() {
    m_zoo->decreaseMeats(conso);
}

void Aigle::fire()
{
    cout << "Je pousse un cri" << endl;
}