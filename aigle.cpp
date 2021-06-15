#include <iostream>
#include "ianimal.h"
#include "aigle.h"
using namespace std;
Aigle::Aigle()
{

}


Aigle::Aigle(string name)
    :IAnimal(name)
{

}

void Aigle::fire()
{
    cout << "Je pousse un cri" << endl;
}