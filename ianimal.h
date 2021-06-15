#ifndef IANIMAL_H
#define IANIMAL_H
#include <string>

using namespace std;

class IAnimal
{
    string m_name;
    //static int count;
public:
    IAnimal();
    IAnimal(string m_name);
    virtual ~IAnimal();
    virtual void fire() = 0;
    //static int GetCount();
};

#endif // IANIMAL_H
