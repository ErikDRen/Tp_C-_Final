#include "game.h"

Game::Game()
{
	m_zoo = Zoo("Zoo de la Montagne");
	m_zoo.addAnimal(new Tigre(&m_zoo,"Tigre", "Jey-Jey", m_zoo.GetCount(),12,false,false,false,false));
	m_zoo.addAnimal(new Tigre(&m_zoo, "Tigre", "Jeanine", m_zoo.GetCount(),12,true,false,false,false));
	m_zoo.addAnimal(new Tigre(&m_zoo, "Tigre", "Michou", m_zoo.GetCount(), 12, false, false, false, false));
	m_zoo.addAnimal(new Tigre(&m_zoo, "Tigre", "Milia", m_zoo.GetCount(), 12, true, false, false, false));

	for (int i = 0; i < 10; i++) {
		m_zoo.addAnimal(new Poule(&m_zoo, "Poule","POULE" , m_zoo.GetCount(), 1,true,false,false,false));
	}
	m_zoo.addAnimal(new Poule(&m_zoo, "Poule", "COQ", m_zoo.GetCount(), 12, false, false, false, false));
	//zoo.addAnimal(new Poule("poule 2"));
	m_zoo.addAnimal(new Aigle(&m_zoo, "Aigle", "Gerard", m_zoo.GetCount(), 12,false,false,false,false));
	m_zoo.addAnimal(new Aigle(&m_zoo, "Aigle", "Marie", m_zoo.GetCount(), 12,true,false,false,false));
	m_zoo.addAnimal(new Aigle(&m_zoo, "Aigle", "Jean", m_zoo.GetCount(), 12, false, false, false, false));
	m_zoo.addAnimal(new Aigle(&m_zoo, "Aigle", "Noel", m_zoo.GetCount(), 12, true, false, false, false));

	gameLoop();
}

Game::~Game() {}

void Game::gameLoop()
{

	int choice = 0;
	for (int years = 0; years < 10; years++)
	{
		for (int months = 1; months < 13; months++)
		{
			cout << "years: " << years << " "
				 << "months: " << months << endl;
			cout << "Choose 1 to continue or anithig else to end game." << endl;
			cin >> choice;
			if (choice == 1)
			{
				m_zoo.PrintZooInfo();
				RollsEvent();
				//Game::situationOfTheGame();
				chooseAnAction();
				if (CheckIfLoosed(m_zoo.GetMoney()))
				{
					cout << "Your loose try again" << endl;
					return;
				}
				if (CheckIfWin(months, years))
				{
					cout << "Gz your win your score is: " << m_zoo.GetMoney() << endl;
					return;
				}
				if (months == 12)
				{
					m_zoo.GetSubvention();
				}
				m_zoo.UpdateZoo();
				continue;
			}
			else
			{
				GetZoo().fire();
				cout << "end of the game, see ya next time" << endl;
				return;
			}
		}
	}
}

void Game::chooseAnAction()
{
	int choice;
	do
	{
		cout << "Choose an action" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "1. Animal		2.Food		3.Habitat		4.Zoo Info		5.stop here for this month" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			// buy or sell an animal
			chooseAnimal();
			break;
		case 2:
			// buy food
			chooseFood();
			break;
		case 3:
			// buy or sell habitat

			break;
		case 4:
			// zoo info
			m_zoo.PrintZooInfo();
			break;
		case 5:
			// next round
			return;
			break;
		default:
			break;
		}
	} while (true);
}

void Game::chooseFood()
{
	int meetsOrseeds;
	cout << "1: for meats, 2: for  seeds" << endl;
	cin >> meetsOrseeds;
	if (meetsOrseeds == 1)
	{

		m_zoo.BuyMeats();
		cout << "you have now : " << m_zoo.GetMeatsStock() << endl;
	}
	if (meetsOrseeds == 2)
	{
		m_zoo.BuySeeds();
	}
}

bool Game::buyAnimal(int price) {
	int accept = 0;
	cout << "It will cost you " << price << "$ : 1: accept, 2:oops nvm" << endl;
	cin >> accept;
	if (accept == 1) {
		m_zoo.decreaseMoney(price);
	}
	else {
		return false;
	}
	return true;
}

void Game::chooseAnimal()
{
	int buyOrSell = 0;
	int secondChoice = 0;
	int thirdChoice = 0;
	int ageChoice = 0;
	cout << "1: to buy, 2: to sell" << endl;
	cin >> buyOrSell;
	if (buyOrSell == 1)
	{
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "WELCOME TO THE SHOP !" << endl;
		cout << "indicate in order the specificity of the animal you want to buy" << endl;
		cout << "example : 1(entry) 2(entry) 2(entry) 1(entry) for a 4 years old female tiger and to confirm the purchase ! \n" << endl;
		cout << "Witch animal do you want ? 1: Tiger, 2: Eagle, 3: Chicken" << endl;
		cout << "Male or female ? 1: Male, 2: Female" << endl;
		cout << "Age : 1 : 6 month, 2: 4 years, 3: 14 years(Only for tiger and Eagle)" << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cin >> secondChoice >> thirdChoice >> ageChoice;
		if (secondChoice == 3 && ageChoice == 3) {
			cout << "A chicken can't have 14 years" << endl;
			return;
		}
		int age = 6;
		int price = 0;
		bool isFemale = false;
		if (thirdChoice == 1) {
			isFemale = true;
		}
		if (ageChoice == 2) {
			age = 48;
		}
		else if (ageChoice == 3) {
			age = 168;
		}
		if (secondChoice == 1) {

			if (age == 6) { price = 3000; }
			if (age == 48) { price = 120000; }
			if (age == 168) { price = 60000; }
			if (!buyAnimal(price)) { return; }
			m_zoo.addAnimal(new Tigre(&m_zoo, "Tigre", "No Name", m_zoo.GetCount(), age, isFemale, false, false, false));
		}
		else if (secondChoice == 2) {
			if (age == 6) { price = 1000; }
			if (age == 48) { price = 4000; }
			if (age == 168) { price = 2000; }
			if (!buyAnimal(price)) { return; }
			m_zoo.addAnimal(new Aigle(&m_zoo, "Aigle", "No Name", m_zoo.GetCount(), age, isFemale, false, false, false));
		}
		else {
			if (age == 6 && isFemale) { price = 20; }
			if (age == 48 && isFemale) { price = 5; }
			if (age == 6 && !isFemale) { price = 100; }
			if (age == 48 && !isFemale) { price = 25; }
			if (!buyAnimal(price)) { return; }
			m_zoo.addAnimal(new Poule(&m_zoo, "Poule", "No Name", m_zoo.GetCount(), age, isFemale, false, false, false));
		}
	}
	else if (buyOrSell == 2)
	{
		AnimalList Animli = m_zoo.GetAnimalList();
		for (int i = 0; i < Animli.size(); i++) {
			cout << Animli[i]->m_type << " -> : " << "id: " << i << " " << "age: " << "X" << " " << "Price: " << sellPrice(Animli[i]) << endl; // Animli[i]->GetId()
		}
		int id;
		cout << "which one do you want to sell discreetly on the black market when nobody is looking to round off your monthly income ?" << endl;
		cout << "enter his id : " << endl;
		cin >> id;
		m_zoo.sellAnimalByID(id);
		cout << "as promised here is your money..." << endl;
		cout << "Money + " << sellPrice(Animli[id]) << endl;
		m_zoo.increaseMoney(sellPrice(Animli[id]));
		m_zoo.destroyAnimal(id);
		cout << "see you next time... my friend" << endl;
	}
	else {
		cout << "Only accept 1 or 2 !" << endl;
	}
}

int Game::sellPrice(IAnimal* animal) {
	if (animal->m_type == "Tigre") {
		return 10000;
	}
	else if (animal->m_type == "Aigle") {
		return 400;
	}
	else {
		return 10;
	}
}

Zoo Game::GetZoo()
{
	return m_zoo;
}

void Game::RollsEvent()
{
	srand(time(NULL));
	switch (rand() % 50 + 1)
	{
	case 5:
		//
		cout << "!!! We have an epidemic !!!" << endl;
		cout << "> + 10% chance of sickness for Eagle and Chicken this month<" << endl;
		break;
	case 6:
		cout << "!!! OH NOOOOOO! Pests destroy our seed stocks !!!" << endl;
		m_zoo.HarmfulSeed();
		cout << "> loss 10% of your seed stock <" << endl;
		break;
	case 7:
		cout << "!!! OH SO SAD! Meat store has rotten !!!" << endl;
		m_zoo.RottenMeat();
		cout << "> loss 20% of your meat stock <" << endl;
		break;
	case 8:
		//
		cout << "!!! FIRE FIRE FIRE CALL 911 !!!" << endl;
		cout << "> you lose a random habitat and all the animals inside <" << endl;
		break;
	case 9:
		//
		cout << "!!! THIEF! THIEF ! !!!" << endl;
		m_zoo.BeingRobbed();
		cout << "> individuals are introduced into the zoo during the night and have stolen an animal <" << endl;
		cout << "> you lose a random animal <" << endl;
		break;
	case 10:
		cout << "!!! WooW, a star has booked the zoo for the day! !!!" << endl;
		m_zoo.PocketBonus();
		cout << "> No visitors but a nice pocket bonus <" << endl;
		break;
	default:
		cout << "Nothing particular this month." << endl;
	}
}

bool Game::CheckIfWin(int month, int years)
{
	if (years == 9 && month == 11)
	{
		return true;
	}
	return false;
}

bool Game::CheckIfLoosed(int money)
{
	if (money <= 0)
	{
		return true;
	}
	return false;
}
