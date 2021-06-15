#ifndef ZOO_H
#define ZOO_H
#include "ianimal.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class IAnimal;
typedef vector <IAnimal*> AnimalList;
typedef AnimalList::iterator AnimalIterator;
class Zoo
{
    string m_name;
    AnimalList m_animals;
    int m_money;

    int m_meats;
    int m_seeds;
    //static int count;
public:
    Zoo(string name = "");
    string getName();
    void UpdateZoo();
    int GetMoney();
    int GetMeatsStock();
    int GetSeedsStock();
    void BuyMeats();
    void BuySeeds();
    void decreaseMeats(int op);
    void decreaseSeeds(int op);
    //static int GetCount();
    void PrintZooInfo();
    void addAnimal(IAnimal* animal);
    void fire();
};

#endif // ZOO_H
