#ifndef IANIMAL_H
#define IANIMAL_H
#include <string>
#include "zoo.h"
using namespace std;

class Zoo;
class IAnimal
{
    string m_name;

    //static int count;
     bool m_female;
    // bool fidelity;
    bool m_sexual_maturity;
    bool m_hungry;
    bool m_gestation;
    int m_age;

protected:
    Zoo* m_zoo;

public:
    IAnimal(Zoo* zoo);
    IAnimal(Zoo* zoo, string m_name,int m_age,bool female, bool m_hungry,bool m_sexual_maturity,bool m_gestation);
    virtual ~IAnimal();
    virtual void Update() = 0;
    virtual void fire() = 0;
    // int Grow();
    // virtual bool CanBirth() = false;
    //static int GetCount();
};

#endif // IANIMAL_H
