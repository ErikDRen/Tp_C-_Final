#include <iostream>
#include "ianimal.h"
#include "tigre.h"

using namespace std;

Tigre::Tigre()
{

}

Tigre::Tigre(string name)
    :IAnimal(name)
{
    cout << "groooar je suis " + name << endl;
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

