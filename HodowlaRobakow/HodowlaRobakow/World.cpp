#include "World.h"

void World::floorInit()
{
	for (int i = 0; i < yWorldSize; i++)
	{
		std::vector<Ground*> horizontalFloor;

		for (int j = 0; j < xWorldSize; j++)
		{
			horizontalFloor.push_back(new Ground());
			horizontalFloor[j]->setPosition(j * horizontalFloor[j]->getGround().getSize().x,
										i* horizontalFloor[j]->getGround().getSize().y);
		}
		floor.push_back(horizontalFloor);
		horizontalFloor.clear();
	}
	
}

void World::wormsInit()
{
	for (int i = 0; i < 7; i++)
	{
		worms.push_back(new Worm((int)floor[0][0]->getGround().getPosition().x,
						(int)floor[0][0]->getGround().getPosition().y - (int)floor[0][0]->getGround().getSize().y, &eggs));

	}

}

Ground* World::checker(int wormNumber)
{
	for (int i = 0; i < yWorldSize; i++)
	{
		for (int j = 0; j < xWorldSize; j++)
		{
			if (worms[wormNumber]->getChecker().getGlobalBounds().intersects(floor[j][i]->getGround().getGlobalBounds()))
			{
				//std::cout << "Robak o numerze " << wormNumber << " jest na pod³odze o wspolzednych " << i << ","<<j<< std::endl;
				return floor[j][i];

			}
		}
	}

}

Worm* World::foodEaten(int wormNumber)
{
	worms[wormNumber]->eaten++;
	worms[wormNumber]->reScale();
	return worms[wormNumber];
}

World::World(int x, int y)
{
	xWorldSize = x;
	yWorldSize = y;

	floorInit();

	wormsInit();

	//std::cout << ;
	//okreslenie nowego robaka oraz przypisanie mu pozycji
}

World::~World()
{
	for (int i = 0; i < yWorldSize; i++)
	{
		for (int j = 0; j < xWorldSize; j++)
		{
			delete floor[i][j];
		}
		
	}
	floor.clear();
	for (int i = 0; i < worms.size(); i++)
	{
		delete worms[i];
	}
	worms.clear();
}


void World::update()
{	
	if (eatTimer.getElapsedTime().asSeconds() >.2f)
	{
		
		for (int i = 0; i < worms.size(); i++) //sprawdzam dla kazdego robaka podloge
		{
			
			whereIsWorm.push_back(checker(i)); //zczytywanie gdzie stoi robak
			
			if (whereIsWorm[i]->eatFood())
			{
				foodEaten(i);
			}
			

			bool is2Worms = false;
			for (int k = i; k > 0; k--)
			{
				if (whereIsWorm[k]==whereIsWorm[k-1])
				{
					is2Worms = true;
				}
			}
			if (worms[i]->eaten > 7 && worms[i]->isMature() && is2Worms && leyEggTimer.getElapsedTime().asSeconds() > leyEggSpan)
			{
				worms[i]->layEggs(i, countNewWorms);
				leyEggTimer.restart();
			}
			std::cout << worms[i]->eaten << std::endl;


			if (worms[i]->wormDeath()) // sprawdzam czy robak osi¹gn¹ max wiek
			{
				delete worms[i] ;
				worms.erase(worms.begin() + i);
				//worms.resize(worms.size() - 1);
			}
			if (hungerTimer.getElapsedTime().asSeconds() > hungerSpan)
			{
				worms[i]->eaten = worms[i]->eaten--;
				hungerTimer.restart();
			}
			
		}
		whereIsWorm.clear();
		for (int i = 0; i < eggs.size(); i++)
		{
			if (eggs[i]->wormDeath()) // sprawdzam czy jajka osi¹gn¹ max wiek
			{
				worms.push_back(new Worm(eggs[i]->getCreature()->getPosition().x,
					eggs[i]->getCreature()->getPosition().y, &eggs));
				delete eggs[i];
				eggs.erase(eggs.begin() + i);

			}
		}
		
		eatTimer.restart();
	}
	if (groundTimer.getElapsedTime().asSeconds() > restoreFoodTime)
	{
		for (int i = 0; i < yWorldSize; i++)
		{
			for (int j = 0; j < xWorldSize; j++)
			{
				//floor[i][j]->restoreFood();
			}
		}
		groundTimer.restart();
	}
	

}


void World::drawWorld(sf::RenderWindow* window,float dt)
{
	for (int i = 0; i < yWorldSize; i++)
	{
		for (int j = 0; j < xWorldSize; j++)
		{
			window->draw(floor[i][j]->getGround());
		}	
	}
	for (int i = 0; i < worms.size(); i++)
	{
		worms[i]->movment(xWorldSize*floor[0][0]->getGround().getSize().x,
			yWorldSize * floor[0][0]->getGround().getSize().y,
			dt);
		window->draw(*worms[i]->getCreature());
		window->draw(worms[i]->checker);
		
	}
	for (int i = 0; i < eggs.size(); i++)
	{
		window->draw(*eggs[i]->getCreature());
	}

}


