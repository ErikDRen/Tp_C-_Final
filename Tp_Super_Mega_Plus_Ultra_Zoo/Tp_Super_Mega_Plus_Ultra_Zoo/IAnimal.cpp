#include "IAnimal.h"
#include <iostream>
using namespace  std;
int IAnimal::count=0;
IAnimal::IAnimal(Zoo* zoo):m_zoo(zoo)
{
    m_zoo ->add(this);
    count++;
}

IAnimal::~IAnimal()
{
    count --;
}

int IAnimal::getCount()
{
    return count;
}
#include "IAnimal.h"
