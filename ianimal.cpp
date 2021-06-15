#include "ianimal.h"

//int IAnimal::count = 0;
IAnimal::IAnimal()
    :m_name("Animal sans Nom")
{
    // //count++;
    // seek = false;
    // female = false;
    // fidelity = false;
    // gestation = false
    // hungry = 0;
    // sexual_maturity = 0;
    // age = 0;
}

IAnimal::IAnimal(string name)
    : m_name(name)
{
    //count++;
}

IAnimal::~IAnimal()
{
    //count--;
}

// IAnimal::Grow()
// {
//     age++
//     //count++;
// }

// bool IAnimal::CanBirth()
// {
//     return false;
// }

/*int IAnimal::GetCount() {
    return count;
}*/