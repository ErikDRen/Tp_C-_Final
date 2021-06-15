#ifndef TIGRE_H
#define TIGRE_H

#include "ianimal.h"

#include <string>

using namespace std;

class Tigre :public IAnimal
{

public:
    Tigre();
    Tigre(string name);
    virtual void fire();
};

#endif // TIGRE_H
