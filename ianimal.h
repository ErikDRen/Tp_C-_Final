#ifndef IANIMAL_H
#define IANIMAL_H
#include <string>

using namespace std;

class IAnimal
{
    string m_name;

    //static int count;
    // bool seek;
    // bool female;
    // bool fidelity;
    // bool gestation;
    // int hungry;
    // int sexual_maturity;
    // int age;

public:
    IAnimal();
    IAnimal(string m_name);
    virtual ~IAnimal();
    virtual void fire() = 0;
    // int Grow();
    // virtual bool CanBirth() = false;
    //static int GetCount();
};

#endif // IANIMAL_H
