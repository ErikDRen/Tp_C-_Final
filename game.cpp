#include "game.h"

Game::Game()
{
	m_zoo = Zoo("Zoo de la Montagne");

	m_zoo.addAnimal(new Tigre("Jey-Jey"));
	m_zoo.addAnimal(new Tigre("Jeanine"));

	for (int i = 0; i < 10; i++) {
		m_zoo.addAnimal(new Poule());
	}
	//zoo.addAnimal(new Poule("poule 2"));
	m_zoo.addAnimal(new Aigle("Gérard"));
	m_zoo.addAnimal(new Aigle("Marie"));

	gameLoop();
}

Game::~Game() {}


void Game::gameLoop()
{
	int choice = 0;
	for (int years = 0; years < 10; years++) {
		for (int months = 1; months < 13; months++ ) {
			cout << "years: " << years << " " << "months: " << months << endl;
			cout << "Choose 1 to continue, 2 for buy or 3 for stop" << endl;
			cin >> choice;
			if (choice == 1) {
				m_zoo.PrintZooInfo();
				RollsEvent();
				//Game::situationOfTheGame();
				chooseAnAction();
				if (CheckIfLoosed(m_zoo.GetMoney())) {
					cout << "Your loose try again" << endl;
					return;
				}
				if (CheckIfWin(months, years)) {
					cout << "Gz your win your score is: " << m_zoo.GetMoney() << endl;
					return;
				}
				continue;
			}
			else {
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
	do {
		cout << "Choose an action" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "1. Animal		2.Food		3.Habitat		4.Zoo Info		5.stop here for this month" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

		cin >> choice;
		switch (choice) {
		case 1:
			 // buy or sell an animal
			break;
		case 2:
			// buy food
			ChooseFood();
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

void Game::ChooseFood()
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

Zoo Game::GetZoo()
{
	return m_zoo;
}

void Game::RollsEvent()
{
	srand(time(NULL));
	switch (rand() % 10 + 1) {
	case 5:
		//
		cout << "!!! Epidémie de grippe aviaire !!!" << endl;
		cout << "> Chance de maladie des Aigles et des Poules + 10% pour ce mois-ci<" << endl;
		break;
	case 6:
		cout << "!!! Des nuisibles détruisent nos stocks de graines !!!" << endl;
		cout << "> Perte de 10% de votre stock en graines <" << endl;
		break;
	case 7:
		cout << "!!! La viande stockez a pourries !!!" << endl;
		cout << "> Perte de 20% de votre stock en viande <" << endl;
		break;
	case 8:
		//
		cout << "!!! un incendie c'est déclaré !!!" << endl;
		cout << "> vous perdez un habitat aléatoire et tous les animaux qui si trouvent <" << endl;
		break;
	case 9:
		//
		cout << "!!! AU VOLEUR! AU VOLEUR ! !!!" << endl;
		cout << "> des individues ce sont introduis dans le zoo pendant la nuit et ont dérobé un animal <" << endl;
		cout << "> vous perdez un animal aléatoire <" << endl;
		break;
	case 10:
		cout << "!!! WooW, une star réserve le zoo pour la journée ! !!!" << endl;
		cout << "> Aucune visiteur mais une belle prime d'enpoché <" << endl;
		break;
	default:
		cout << "Nothing particular this month." << endl;
	}
}

bool Game::CheckIfWin(int month, int years)
{
	if (years == 9 && month == 11) {
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