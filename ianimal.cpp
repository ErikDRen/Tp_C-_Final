#include "ianimal.h"

//int IAnimal::count = 0;
IAnimal::IAnimal(Zoo* zoo, string type, int id)
    :m_name("Animal sans Nom"), m_zoo(zoo), m_type(type), m_id(id),m_age(0) ,m_female(false),  m_hungry(false) ,m_sexual_maturity(false),m_gestation(false) 
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

IAnimal::IAnimal(Zoo* zoo, string type, string name, int id, int age,bool female, bool hungry , bool sexual_maturity,bool gestation)
    : m_name(name), m_zoo(zoo) , m_type(type), m_id(id), m_age(age),m_female(female),m_hungry(hungry),m_sexual_maturity(sexual_maturity),m_gestation(gestation)
{
    //count++;
}

IAnimal::~IAnimal()
{
    //count--;
}

int IAnimal::GetId() {
    return m_id;
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