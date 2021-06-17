#include <iostream>
#include "ianimal.h"
#include "tigre.h"

using namespace std;

Tigre::Tigre(Zoo* zoo, string type, int id)
    :IAnimal(zoo ,type, id)
{
    m_name = "No Name";
    myage = 0;
    m_zoo = zoo;
    conso = 180;
    //id = m_zoo->GetCount();
}

Tigre::Tigre(Zoo* zoo, string type, string name, int id,int age, bool female, bool hungry, bool sexual_maturity, bool gestation)
    :IAnimal(zoo,type, name,id, age, female, hungry, sexual_maturity, gestation)
{
    m_name = name;
    myage = age;
    m_zoo = zoo;
    conso = 180;
    myage = age;
    myhungry = hungry;
    mygestation = gestation;
    mysexual_maturity = sexual_maturity;
    //id = m_zoo->GetCount();
    cout << "groooar je suis " + name << endl;
}

bool Tigre::checkAge() {
    if (myage > espVie) {
        return false;
    }
    return true;
}
void Tigre::Update()
{
    Eat();
    myage++;
}

void Tigre::Eat() {
    m_zoo->decreaseMeats(conso);
}

void Tigre::fire()
{
    cout << m_name << " rugis : " << "id: " << this->GetId() << " " << "age: " << myage << " " << "espVie: " << espVie << endl;
}

// bool Tigre::CanBirth()
// {
//     if (female == true && age >= 6) {
//         gestation = true
//     }
// }

void Tigre::ifHungry()
{
    if (myhungry == true /* &&  meat == 0*/)
    {
        mygestation = false;
        mysexual_maturity = false;
    }
}

void Tigre::CheckifHungry()
{
    /*if(pas manger)
    {
        myhungry = true
    }*/
}
