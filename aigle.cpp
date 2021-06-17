#include <iostream>
#include "ianimal.h"
#include "aigle.h"
using namespace std;
Aigle::Aigle(Zoo* zoo, string type, int id)
    :IAnimal(zoo, type ,id)
{
    m_name = "No name";
    myage = 0;
    m_zoo = zoo;
    conso = 1;
    //id = m_zoo->GetCount();
}


Aigle::Aigle(Zoo* zoo, string type, string name, int id, int age, bool female, bool hungry, bool sexual_maturity, bool gestation)
    :IAnimal(zoo, type, name,id,age,female,hungry,sexual_maturity,gestation)
{
    m_name = name;
    myage = age;
    m_zoo = zoo;
    conso = 1;
    //id = m_zoo->GetCount();
}

bool Aigle::checkAge() {
    if (myage > espVie) {
        return false;
    }
    return true;
}
void Aigle::Update()
{
    Eat();
    myage++;
}

void Aigle::Eat() {
    m_zoo->decreaseMeats(conso);
}

void Aigle::fire()
{
    cout << m_name << " Cry : " << "id: " << this->GetId() << " " << "age: " << myage << " " << "LifeExpectancy: " << espVie << endl;
}