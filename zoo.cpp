#include "zoo.h"

//int Zoo::count = 0;
Zoo::Zoo(string name)
    : m_name(name)
{
    count = 0;
    m_money = 80000;
    m_meats = 0;
    m_seeds = 0;
    tigerHouse = 2;
    eagleHouse = 2;
    chickenHouse = 1;

    // m_Habitat = Habitat("Tigre");
}

void Zoo::UpdateZoo()
{
    deleteTheOldOnes(m_animals);
    auto it = m_animals.begin();
    while (it != m_animals.end())
    {
        (*it)->Update();
        it++;
    }
    visitorEntry();
}

void Zoo::deleteTheOldOnes(AnimalList ListOfAnimal) {
    // Tout est prevue pour simplifier le jeu et permettre au joueur de reagir
    for (int i = 0; i < ListOfAnimal.size(); i++) {
        if (ListOfAnimal[i]->checkAge() == false) {
            destroyAnimal(i);
            break;
        }
    }
}

string Zoo::getName() { return m_name; }
int Zoo::GetMoney() { return m_money; }
int Zoo::GetMeatsStock() { return m_meats; }
int Zoo::GetSeedsStock() { return m_seeds; }
int Zoo::GetCount() { return count; }
int Zoo::GetTigerCount() { return TigerCount; }
void Zoo::GetSubvention() { m_money += (TigerCount * 43800 + AigleCount * 2190); }

AnimalList Zoo::GetAnimalList()
{
    return m_animals;
}

void Zoo::visitorEntry()
{
    int visiteur = 0;
    visiteur += TigerCount * 30;
    visiteur += PouleCount * 2;
    visiteur += AigleCount * 15;
    visiteur = visiteur / 4;
    m_money += 30 * visiteur;
}

void Zoo::PrintZooInfo()
{
    cout << "*************************" << endl;
    cout << "Info du Zoo :" << endl;
    cout << "Money : " << m_money << endl;
    cout << "Food : " << " meat : " << GetMeatsStock() << " seed : " << GetSeedsStock() << endl;
    cout << "Animal Number : " << GetCount() << endl;
    cout << "Number of Tiger -> m : " << " f : " << " t : " << TigerCount << endl;
    cout << "Number of Chicken -> m : " << " f : " << " t : " << PouleCount << endl;
    cout << "Number of Eagle -> m : " << " f : " << " t : " << AigleCount << endl;
    cout << "*************************" << endl;
}

void Zoo::addAnimal(IAnimal *animal)
{
    m_animals.push_back(animal);
    if (animal->m_type == "Tigre")
    {
        m_TigerList.push_back(animal);
        TigerCount++;
    }
    else if (animal->m_type == "Poule")
    {
        m_PouleList.push_back(animal);
        PouleCount++;
    }
    else
    {
        m_AigleList.push_back(animal);
        AigleCount++;
    }
    count++;
}

void Zoo::fire()
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        (*it)->fire();
        //count--;
        it++;
    }
}

void Zoo::BuyMeats()
{
    int qtt = 0;
    cout << "How many do you want?" << endl;
    cin >> qtt;
    if (m_money >= (5 * qtt))
    {
        m_meats += qtt;
        m_money -= (5 * qtt);
    }
    else
    {
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "you dont have enough money..." << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
    }
}

void Zoo::BuySeeds()
{
    int qtt = 0;
    cout << "How many do you want?" << endl;
    cin >> qtt;
    if (m_money >= (2.5 * qtt))
    {
        m_seeds += qtt;
        m_money -= (2.5 * qtt);
    }
    else
    {
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "you dont have enough money..." << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
    }
}

void Zoo::decreaseMeats(int op)
{
    if (m_meats >= op)
    {
        m_meats -= op;
    }
    else
    {
        cout << "you dont have enough meats..." << endl;
        cout << "--------------------------------------------" << endl;
        return;
    }
}

void Zoo::decreaseSeeds(int op)
{
    if (m_meats >= op)
    {
        m_seeds -= op;
    }
    else
    {
        cout << "you dont have enough seeds..." << endl;
        cout << "--------------------------------------------" << endl;
        return;
    }
}

void Zoo::increaseMoney(int op)
{
    m_money += op;
}

void Zoo::decreaseMoney(int op)
{
    if (m_money >= op)
    {
        m_money -= op;
    }
    else
    {
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "you dont have enough money..." << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
        return;
    }
}

void Zoo::sellAnimalByID(int id)
{

}

void Zoo::destroyAnimal(int id)
{
    m_animals.erase(m_animals.begin() + id);
    count--;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "il te reste plus que : " << m_animals.size() << " animaux" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    
}


void Zoo::BuyAnimalHouse()
{
    int choice = 0;
    cout << "1: buy tiger house, 2: buy eagle house, 3: buy chicken house" << endl;
    cin >> choice;
    if (choice == 1 && m_money >= 2000)
    {
        tigerHouse++;
        m_money -= 2000;
    }
    if (choice == 2 && m_money >= 2000)
    {
        eagleHouse++;
        m_money -= 2000;
    }
    if (choice == 3 && m_money >= 500)
    {
        chickenHouse++;
        m_money -= 500;
    }
    else
    {
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "you dont have enough money..." << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
        return;
    }
}

void Zoo::SellAnimalHouse()
{
    int choice = 0;
    cout << "1: sell tiger house, 2: sell eagle house, 3: sell chicken house" << endl;
    cin >> choice;
    if (choice == 1)
    {
        tigerHouse--;
        m_money += 500;
    }
    if (choice == 2)
    {
        eagleHouse--;
        m_money += 500;
    }
    if (choice == 3)
    {
        chickenHouse--;
        m_money += 50;
    }
    else
    {
        return;
    }
}

// Habitat Zoo::GetHabitat()
// {
//     return m_Habitat;
// }

void Zoo::BeingRobbed()
{
    srand(time(NULL));
    int ran = rand() % m_animals.size();
    m_animals.erase(m_animals.begin() + ran);
    count--;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "il te reste plus que : " << m_animals.size() << " animaux" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void Zoo::HarmfulSeed()
{
    m_seeds -= (m_seeds / 10);
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "il te reste plus que : " << GetSeedsStock() << "kg de graine" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void Zoo::RottenMeat()
{
    m_meats -= (m_meats / 5);
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "il te reste plus que : " << GetMeatsStock() << "kg de viande" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void Zoo::Test()
{
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << m_animals.size() << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void Zoo::PocketBonus()
{
    m_money += 5000;
}