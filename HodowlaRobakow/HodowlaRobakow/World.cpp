#include "World.h"




void World::floorInit()
{
	for (int i = 0; i < yWorldSize; i++)
	{
		std::vector<Ground*> horizontalFloor;

		for (int j = 0; j < xWorldSize; j++)
		{
			horizontalFloor.push_back(new Ground(data));
			horizontalFloor[j]->setPosition(j * horizontalFloor[j]->getGround().getSize().x,
										i* horizontalFloor[j]->getGround().getSize().y);
		}
		floor.push_back(horizontalFloor);
		horizontalFloor.clear();
	}
	
}

void World::wormsInit()
{
	for (int i = 0; i < 5; i++)
	{
		worms.push_back(new Worm((int)floor[0][0]->getGround().getPosition().x,
						(int)floor[0][0]->getGround().getPosition().y - (int)floor[0][0]->getGround().getSize().y, &eggs,data));

	}

}

Ground* World::checker(int wormNumber)
{
	for (int i = 0; i < yWorldSize; i++)
	{
		for (int j = 0; j < xWorldSize; j++)
		{
			if (worms[wormNumber]->getChecker().getGlobalBounds().intersects(floor[i][j]->getGround().getGlobalBounds()))
			{
				//std::cout << "Robak o numerze " << wormNumber << " jest na pod³odze o wspolzednych " << i << ","<<j<< std::endl;
				return floor[i][j];

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

World::World(sf::Vector2i worldSize, variable* data)
{
	

	xWorldSize = worldSize.x;
	yWorldSize = worldSize.y;

	this->data = data;
	updateVariable();
	floorInit();

	wormsInit();

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
	updateVariable();
	if (eatTimer.getElapsedTime().asSeconds() > eatSpeed)
	{
		std::cout <<std::endl <<eatSpeed;
		for (int i = 0; i < worms.size(); i++) //sprawdzam dla kazdego robaka podloge
		{
			
			whereIsWorm.push_back(checker(i)); //zczytywanie gdzie stoi robak
			
			if (whereIsWorm[i]->eatFood(worms[i]->eaten) && worms[i]->eaten<10)
			{
				foodEaten(i);
			}
			

			bool is2Worms = false;
			for (int k = i; k > 0; k--)
			{
				if (whereIsWorm[i]==whereIsWorm[k-1])
				{
					is2Worms = true;
					worms[k - 1]->leyEggTimer.restart();
				}
			}
			
			if (worms[i]->eaten > 7 && worms[i]->isMature() && is2Worms)
			{
				worms[i]->layEggs(countNewWorms);
			}
			


			if (worms[i]->wormDeath()) // sprawdzam czy robak osi¹gn¹ max wiek
			{
				delete worms[i] ;
				worms.erase(worms.begin() + i);
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
					eggs[i]->getCreature()->getPosition().y, &eggs,data));
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
				floor[i][j]->restoreFood();
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
			floor[i][j]->updateValues();
		}	
	}
	for (int i = 0; i < worms.size(); i++)
	{
		worms[i]->movment(xWorldSize*floor[0][0]->getGround().getSize().x,
			yWorldSize * floor[0][0]->getGround().getSize().y,
			dt);
		worms[i]->updateVariable();
		window->draw(*worms[i]->getCreature());
		//window->draw(worms[i]->checker);
		
	}
	for (int i = 0; i < eggs.size(); i++)
	{
		window->draw(*eggs[i]->getCreature());
	}

}

void World::updateVariable()
{
	hungerSpan = data->hungerSpan;
	restoreFoodTime = data->restoreFoodTime;
	countNewWorms = data->countNewWorms;
	eatSpeed = data->eatSpeed;
}

void World::isClicked(sf::Vector2i mousePos)
{
	mousePos.x -= 50;
	mousePos.y -= 50;
	for (int i = 0; i < yWorldSize; i++)
	{
		for (int j = 0; j < xWorldSize; j++)
		{
			if (floor[i][j]->getGround().getGlobalBounds().contains(sf::Vector2f(mousePos)))
			{
				worms.push_back(new Worm(mousePos.x,mousePos.y-20, &eggs, data));
			}
		}
	}
	
}


