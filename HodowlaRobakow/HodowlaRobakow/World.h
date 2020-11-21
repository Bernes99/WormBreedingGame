#pragma once
#include "Ground.h"
#include <vector>
#include "Worm.h"

class World
{
	std::vector <Ground*> floor;
	Worm *worm;
	sf::Clock timer;
	sf::Time elapseTime;

	void floorInit();

	Ground* checker();
public:
	World();
	~World();
	void update();
	/// <summary>
	/// rysowanie swiata
	/// </summary>
	/// <param name="window">okno na którym jest rysowanie</param>
	void drawWorld(sf::RenderWindow* window);
};

