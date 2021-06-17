#pragma once

#include "zoo.h"
#include "aigle.h"
#include "poule.h"
#include "tigre.h"
#include <stdlib.h> 
using namespace std;

class Game
{
	Zoo m_zoo;
	void gameLoop();
	void chooseAnAction();
	void chooseFood();
	void chooseAnimal();
	bool buyAnimal(int price);
	int sellPrice(IAnimal* animal);
public:
	Game();
	~Game();
	Zoo GetZoo();
	void RollsEvent(); // Rolls for game event
	bool CheckIfWin(int month, int years); // win if finished the ten years and your remaining money will be your score
	bool CheckIfLoosed(int money); // loose if after the end of the round your money is under 0
};