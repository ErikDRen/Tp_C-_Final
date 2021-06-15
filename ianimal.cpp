#include "ianimal.h"

//int IAnimal::count = 0;
IAnimal::IAnimal()
    :m_name("Animal sans Nom")
{
    //count++;
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

/*int IAnimal::GetCount() {
    return count;
}*/