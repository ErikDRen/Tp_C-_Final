#ifndef CHICKEN_H_INCLUDED
#define CHICKEN_H_INCLUDED

#include "ianimal.h"

class Chicken : public IAnimal
{
public:
    Chicken();
    virtual void show();
};

#endif // MCHICKEN_H_INCLUDED