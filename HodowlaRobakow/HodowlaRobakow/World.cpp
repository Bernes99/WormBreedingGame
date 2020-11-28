#include "World.h"

void World::floorInit()
{
	for (int i = 0; i < 16; i++)
	{
		floor.push_back(new Ground());
		floor[i]->setPosition(i*64,400);
	}
	
}

void World::wormsInit()
{
	for (int i = 0; i < 2; i++)
	{
		worms.push_back(new Worm((int)floor[3]->getGround().getPosition().x,
						(int)floor[3]->getGround().getPosition().y - (int)floor[3]->getGround().getSize().y));

	}

}

Ground* World::checker(int wormNumber)
{
	for (int i = 0; i < 16; i++)
	{
		if (worms[wormNumber]->getChecker().getGlobalBounds().intersects(floor[i]->getGround().getGlobalBounds()))
		{
			std::cout << "zawiera" << i;
			return floor[i];
		}
	}

}

Worm* World::foodEaten(int wormNumber)
{
	worms[wormNumber]->eaten++;
	worms[wormNumber]->reScale();
	return worms[wormNumber];
}

World::World()
{
	floorInit();

	wormsInit();
	//okreslenie nowego robaka oraz przypisanie mu pozycji
}

World::~World()
{
	for (int i = 0; i < floor.size(); i++)
	{
		delete(floor[i]);
	}
	floor.clear();
	for (int i = 0; i < worms.size(); i++)
	{
		delete(worms[i]);
	}
	worms.clear();
}


void World::update()
{	
	if (eatTimer.getElapsedTime().asSeconds() >.2f)
	{
		for (int i = 0; i < worms.size(); i++) //sprawdzam dla kazdego robaka podloge
		{
			checker(i)->eatFood();
			foodEaten(i);
		}
		eatTimer.restart();
	}
	if (groundTimer.getElapsedTime().asSeconds() > restoreFoodTime)
	{
		for (int i = 0; i < 16; i++)
		{
			floor[i]->restoreFood();
		}
		groundTimer.restart();
	}
	
	
}


void World::drawWorld(sf::RenderWindow* window,float dt)
{
	for (int i = 0; i < 16; i++)
	{
		window->draw(floor[i]->getGround());
	}
	for (int i = 0; i < 2; i++)
	{
		worms[i]->movment(window->getSize().x);
		window->draw(worms[i]->getWorm());
		window->draw(worms[i]->checker);
	}

}
