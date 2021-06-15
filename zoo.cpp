#include "zoo.h"

//int Zoo::count = 0;
Zoo::Zoo(string name)
    :m_name(name)
{
    m_money = 80000;
    m_meats = 0;
    m_seeds = 0;
}


string Zoo::getName(){ return m_name; }
int Zoo::GetMoney() { return m_money; }
int Zoo::GetMeatsStock() { return m_meats; }
int Zoo::GetSeedsStock() { return m_seeds; }

void Zoo::PrintZooInfo()
{
    cout << "*************************" << endl;
    cout << "Info du Zoo :" << endl;
    cout << "Money : " << m_money << endl;
    cout << "Food : " << "meat : " << GetMeatsStock() << ", seed : " << GetSeedsStock() << endl;
    //cout << "Nombre d'animaux : " << GetCount() << endl;
    cout << "Nombre de Tigre -> m : " << "f : " << "t : " << endl;
    cout << "Nombre de Poule -> m : " << "f : " << "t : " << endl;
    cout << "Nombre d'Aigle -> m : " << "f : " << "t : " << endl;
    cout << "*************************" << endl;
}

void Zoo::addAnimal(IAnimal* animal)
{
    m_animals.push_back(animal);
    //count++;
    //m_money--
}

/*int Zoo::GetCount()
{
    return count;
}*/

void Zoo::fire()
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end()) {
        (*it)->fire();
        //count--;
        it++;
    }
}

int Zoo::BuyMeats()
{
    // int qtt = 0;
    // cout << "How many do you want?" << endl;
    // cin >> qtt;
    // m_meats += qtt;
    // m_money -= (5 * qtt);
    m_meats++;
    // m_money -= 5;
    return m_meats;
}

int Zoo::BuySeeds()
{
    // int qtt = 0;
    // cout << "How many do you want?" << endl;
    // cin >> qtt;
    // m_seeds += qtt;
    // m_money -= (5 * qtt);
    m_seeds++;
    // m_money -= 2,5;
    return m_seeds;
}