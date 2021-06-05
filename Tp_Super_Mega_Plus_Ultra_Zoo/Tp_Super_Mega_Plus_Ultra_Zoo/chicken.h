#ifndef CHICKEN_H
#define CHICKEN_H

#include "IAnimal.h"




class Chicken : public IAnimal
{
public:
    Chicken(Zoo* zoo);

    virtual void show();
    virtual bool fire();
};

#endif // CHICKEN_H
