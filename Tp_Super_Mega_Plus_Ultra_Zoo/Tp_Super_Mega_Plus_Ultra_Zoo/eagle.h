#ifndef EAGLE_H
#define EAGLE_H

#include "IAnimal.h"



class Eagle : public IAnimal
{
public:
    Eagle(Zoo* zoo);
    ~Eagle();
     virtual void show();

    virtual bool fire();
     
};

#endif // AIGLE_H