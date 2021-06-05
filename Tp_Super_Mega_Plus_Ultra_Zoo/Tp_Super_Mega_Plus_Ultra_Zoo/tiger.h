#ifndef TIGER_H
#define TIGER_H

#include "IAnimal.h"



class Tiger : public IAnimal
{
public:
    Tiger(Zoo* zoo);

    virtual void show();
    virtual bool fire();
};

#endif // TIGER_H
