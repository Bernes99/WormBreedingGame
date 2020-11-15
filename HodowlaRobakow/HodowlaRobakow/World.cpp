#include "World.h"

void World::floorInit()
{
	for (int i = 0; i < 16; i++)
	{
		floor.push_back(new Ground());
		floor[i]->setPosition(i*64,400);
	}
	
}

World::World()
{
	floorInit();
}

World::~World()
{
	for (int i = 0; i < floor.size(); i++)
	{
		delete(floor[i]);

	}
	floor.clear();
}


void World::update()
{
	
}


void World::drawWorld(sf::RenderWindow* window)
{
	for (int i = 0; i < 16; i++)
	{
		window->draw(floor[i]->getGround());
	}
	
}
