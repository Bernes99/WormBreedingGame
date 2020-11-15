#pragma once
#include "Ground.h"
#include <vector>

class World
{
	std::vector <Ground*> floor;
	void floorInit();
	

public:
	World();
	~World();
	void update();
	void drawWorld(sf::RenderWindow* window);
};

