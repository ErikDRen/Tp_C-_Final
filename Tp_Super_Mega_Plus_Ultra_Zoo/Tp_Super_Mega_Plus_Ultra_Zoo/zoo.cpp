#include "Zoo.h"



void Zoo::startSimulation()
{
 
//  new AnimalName(zoo, genre, age)
    // Male
    new Chicken(this, true, 180);// 6 mois = 180j = maturité
    new Tiger(this, true, 2190);// 6 ans = 2190j = maturité
    new Eagle(this, true, 1460); // 4 ans = 1460j = maturité

    // Female
    new Tiger(this, false, 2190);
    new Eagle(this, false, 1460);
    for (int i = 0; i < 10; i++)
    {
        new Chicken(this, false, 180)
    }

}

void Zoo::add(IAnimal *animal)
{
    liste_animal.push_back(animal);
}


void Zoo::sellAnimal(IAnimal* animal)
{
    delete animal;
    // money ++
}


void Zoo::buyAnimal(IAnimal* animal)
{
    liste_animal.push_back(animal);
    //money--
}


void Zoo::buyFood()
{

}

void Zoo::buyBasement()
{

}
