#ifndef AIGLE_H
#define AIGLE_H
#include <string>
#include "ianimal.h"

using namespace std;

class Aigle :public IAnimal
{
public:
    Aigle();
    Aigle(string name);
    virtual void fire();
};

#endif // AIGLE_H
