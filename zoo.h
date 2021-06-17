#ifndef ZOO_H
#define ZOO_H
#include "ianimal.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h> 

using namespace std;
class IAnimal;
typedef vector <IAnimal*> AnimalList;
typedef AnimalList::iterator AnimalIterator;
// typedef vector <Habitat*> HabitatList;
class Zoo
{
    string m_name;
    AnimalList m_animals;
    AnimalList m_TigerList;
    AnimalList m_AigleList;
    AnimalList m_PouleList;
    float m_money;
    int m_meats;
    int m_seeds;
    int tigerHouse;
    int eagleHouse;
    int chickenHouse;
    int TigerCount = 0;
    int PouleCount = 0;
    int AigleCount = 0;
    int count;
    // Habitat m_Habitat;

    void visitorEntry();
    void deleteTheOldOnes(AnimalList ListOfAnimal);

public:
    Zoo(string name = "");
    string getName();
    void UpdateZoo();
    int GetMoney();
    int GetMeatsStock();
    int GetSeedsStock();
    int GetTigerCount();
    int GetCount();
    AnimalList GetAnimalList();
    void GetSubvention();
    void PocketBonus();
    void BuyMeats();
    void BuySeeds();
    void increaseMoney(int op);
    void decreaseMeats(int op);
    void decreaseSeeds(int op);
    void decreaseMoney(int op);
    void PrintZooInfo();
    void sellAnimalByID(int id);
    void destroyAnimal(int id);
    void addAnimal(IAnimal* animal);
    void BuyAnimalHouse();
    void SellAnimalHouse();
    void fire();
    void BeingRobbed();
	void HarmfulSeed();
	void RottenMeat();
    void Test();
    // Habitat GetHabitat();
};

#endif // ZOO_H
