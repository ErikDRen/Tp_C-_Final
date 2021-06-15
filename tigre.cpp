#include <iostream>
#include "ianimal.h"
#include "tigre.h"

using namespace std;

Tigre::Tigre(Zoo* zoo)
    :IAnimal(zoo)
{
    m_zoo = zoo;
    conso = 180;
}

Tigre::Tigre(Zoo* zoo, string name, int age, bool female, bool hungry, bool sexual_maturity, bool gestation)
    :IAnimal(zoo, name, age, female, hungry, sexual_maturity, gestation)
{
    m_zoo = zoo;
    conso = 180;
    myage = age;
    myhungry = hungry;
    mygestation = gestation;
    mysexual_maturity = sexual_maturity;
    cout << "groooar je suis " + name << endl;
}

void Tigre::Update()
{
    Eat();
}

void Tigre::Eat() {
    m_zoo->decreaseMeats(conso);
}

void Tigre::fire()
{
    cout << "Je rugis" << endl;
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
