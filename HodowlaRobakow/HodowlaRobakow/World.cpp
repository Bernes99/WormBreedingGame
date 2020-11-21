#include "World.h"

void World::floorInit()
{
	for (int i = 0; i < 16; i++)
	{
		floor.push_back(new Ground());
		floor[i]->setPosition(i*64,400);
	}
	
}

Ground* World::checker()
{
	for (int i = 0; i < 16; i++)
	{
		if (worm->getChecker().getGlobalBounds().intersects(floor[i]->getGround().getGlobalBounds()))
		{
			std::cout << "zawiera" << i;
			return floor[i];
		}
	}

}

World::World()
{
	floorInit();
	//okreslenie nowego robaka oraz przypisanie mu pozycji
	worm = new Worm((int)floor[3]->getGround().getPosition().x,
					(int)floor[3]->getGround().getPosition().y - (int)floor[3]->getGround().getSize().y);
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
	elapseTime = timer.getElapsedTime();
	if (elapseTime.asSeconds()>2.0f)
	{
		checker()->eatFood();
		timer.restart();
	}
	
	
}


void World::drawWorld(sf::RenderWindow* window)
{
	for (int i = 0; i < 16; i++)
	{
		window->draw(floor[i]->getGround());
	}
	worm->movment(window->getSize().x);
	window->draw(worm->getWorm());
	
}
