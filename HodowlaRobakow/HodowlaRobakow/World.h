#pragma once
#include "Ground.h"
#include <vector>
#include "Worm.h"

class World
{
	std::vector <Ground*> floor;
	std::vector <Worm*> worms;
	//Worm *worm;
	sf::Clock timer;
	sf::Time elapseTime;
	sf::Clock timer2;
	sf::Time elapseTime2;
	float restoreFoodTime=10.0f;

	void floorInit();
	void wormsInit();

	Ground* checker(int wormNumber);

	Worm* foodEaten(int wormNumber);
public:
	World();
	~World();
	void update();
	/// <summary>
		/// rysowanie swiata
		/// </summary>
		/// <param name="window">okno na którym jest rysowanie</param>
	/// <param name="dt">delta time</param>
	void drawWorld(sf::RenderWindow* window,float dt);

	
};

