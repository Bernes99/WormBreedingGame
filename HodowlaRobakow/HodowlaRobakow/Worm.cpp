#include "Worm.h"



void Worm::movment(int worldSizeX, int worldSizeY,float dt)
{
	
	if (allowMove)
	{
		/*Losowanie kierunku poruszania sie robaka i zmiana kierunku chodzenia */
		if (allowRandom)
		{
			prevX = xMove;
			prevY = yMove;
			xMove = 0;
			yMove = 0;

			xMove = rand() % (worldSizeX   -5);
			while (prevX == xMove)
			{
				xMove = rand() % (worldSizeX  -5 );
			}

			yMove = rand() % (worldSizeY  );
			while (prevY == yMove)
			{
				yMove = rand() % (worldSizeY   );
			}
			//std::cout << yMove;

			allowRandom = false;
			/* obs³uga zmiany kierunku robaka*/
			if (checker.getPosition().x < xMove)
			{
				int x= sprite.getPosition().x;
				sprite.setScale(-abs(sprite.getScale().x), sprite.getScale().y);
				if (!isPrevRight)
				{
					sprite.setPosition(x + abs(sprite.getScale().x)*sprite.getTexture()->getSize().x,
						sprite.getPosition().y);
					
				}
				//checkerFixPosition();
				isPrevRight = true;
			}
			else
			{
				int x = sprite.getPosition().x;
				sprite.setScale(abs(sprite.getScale().x), sprite.getScale().y);
				if (isPrevRight)
				{
					sprite.setPosition(x - abs(sprite.getScale().x) * sprite.getTexture()->getSize().x,
						sprite.getPosition().y);
					
				}
				//checkerFixPosition();
				isPrevRight = false;
			}
			//std::cout << yMove << "aaaaaa" << xMove;
		}

		/*zabezpieczenie wyjscia poza plansze z prawej*/
		if (checker.getPosition().x > worldSizeX )
		{
			//std::cout << sprite.getPosition().x;
			sprite.move(-4, 0);
			checker.move(-4, 0);
			allowRandom = true;
			//sprite.move(0, 0);
		}

		/*zabezpieczenie wyjscia poza plansze z dolu*/
		else if (checker.getPosition().y > worldSizeY )
		{
			//std::cout << sprite.getPosition().x;
			sprite.move(0, -4);
			checker.move(0, -4);
			allowRandom = true;
			//sprite.move(0, 0);
		}

		/*zabezpieczenie wyjscia poza plansze z gory*/
		else if (checker.getPosition().y <0)
		{
			//std::cout << sprite.getPosition().x;
			sprite.move(0, 4);
			checker.move(0, 4);
			allowRandom = true;
			//sprite.move(0, 0);
		}
		
		/*zabezpieczenie wyjscia poza plansze z lewej*/
		else if (checker.getPosition().x < 0)
		{
			//std::cout << sprite.getPosition().x;
			sprite.move(4, 0);
			checker.move(4, 0);
			allowRandom = true;
			//sprite.move(0, 0);
		}
		
		/*gdy robak jest poza zakresem wylosowanego x i y z dopuszczalnym b³êdem*/
		else if (checker.getPosition().x > xMove+0.5f || checker.getPosition().x < xMove - 0.5f||
			checker.getPosition().y > yMove + 0.5f || checker.getPosition().y < yMove - 0.5f)
		{

			if (dt*speed< worldSizeX && dt*speed < (worldSizeY - sprite.getTexture()->getSize().y / 2))
			{
				if (checker.getPosition().x < xMove)
				{
					sprite.move(speed * dt, 0);
					checker.move(speed * dt, 0);
				}
				else
				{
					sprite.move(-speed * dt, 0);
					checker.move(-speed * dt, 0);
				}
				if (checker.getPosition().y < yMove)
				{
					sprite.move(0, speed * dt);
					checker.move(0, speed * dt);
				}
				else
				{
					sprite.move(0, -speed * dt);
					checker.move(0, -speed * dt);
				}
			}
			
			
			//std::cout << dt << std::endl;
		}
		/* gdy robak jest juz w przedziale to sie zatrzymuje*/
		else
		{
			sprite.move(0, 0);
			checker.move(0, 0);
			allowMove = false;
			timer.restart();	
			allowRandom = true;
			
		}
	}
	else if (timer.getElapsedTime().asSeconds() > howLongStay)
	{
		allowMove = true;
	}
	
}

Worm::Worm(int wormPosX, int wormPosY, std::vector <Eggs*>* egg, variable* data)
{

	this->data = data;
	updateVariable();

	this->eggs = egg;

	loadSprite("../Resources/Textures/worm.png");

	srand(time(NULL));
	allowRandom = true;
	//sprite.setPosition(wormPosX, wormPosY);
	setWormPosition(wormPosX, wormPosY);

	xMove = sprite.getPosition().x;
	yMove = sprite.getPosition().y;

	checker.setSize(sf::Vector2f(1,1));
	//checker.setPosition(wormPosX - sprite.getTexture()->getSize().x / 2,
						//wormPosY + 4*sprite.getTexture()->getSize().y/5);
	
	timer.restart();
	
	checker.setFillColor(sf::Color::Blue);
	//checkerFixPosition();
}






void Worm::reScale()
{
	if (sprite.getScale().x>0)
	{
		if (eaten >= 10 && maxScale > abs(sprite.getScale().x))
		{
			sprite.setScale(sprite.getScale().x + 0.25f, sprite.getScale().y + 0.25f);
			sprite.setPosition(sprite.getPosition().x,
				sprite.getPosition().y - sprite.getTexture()->getSize().y / 4);

			checkerFixPosition();

			eaten = 1;
		}
	}
	else // gdzy robak bedzie w lewo trzeba skalowanie robic dla ujemnych
	{
		if (eaten >= 10 && maxScale > abs(sprite.getScale().x))
		{
			sprite.setScale(sprite.getScale().x - 0.25f, sprite.getScale().y + 0.25f);
			sprite.setPosition(sprite.getPosition().x,
				sprite.getPosition().y - sprite.getTexture()->getSize().y / 4);

			checkerFixPosition();

			eaten = 1;
		}
	}
	

}

void Worm::setMaxScale(int maxScale)
{
	this->maxScale = maxScale;
}

bool Worm::wormDeath()
{
	
	if (deathTime.getElapsedTime().asSeconds() >=maxLifeTime)
	{
		return true;
	}
	else if(deathTime.getElapsedTime().asSeconds() >= maxLifeTime*0.90f)
	{
		sprite.setColor(sf::Color(255,0,0));
	}
	if (eaten <= 0 && !hungerDie)
	{
		hungerDie = true;
		sprite.setColor(sf::Color(255, 0, 0));
		hungerTimer.restart();
		std::cout << "prawie umiera \n";

	}
	else if (eaten >= 0) // jak jest '=' to jest miganie xD
	{
		hungerDie = false;
		sprite.setColor(sf::Color(255, 255, 255));
	}
	if (hungerDie && hungerTimer.getElapsedTime().asSeconds()>=maxHungerTime)
	{
		return true;
	}
	return false;
}

bool Worm::isMature()
{
	if (deathTime.getElapsedTime().asSeconds() >= maxLifeTime * notMature)
	{
		return true;
	}
	return false;
}


void Worm::layEggs(int count)
{
	if (leyEggTimer.getElapsedTime().asSeconds() >leyEggSpan)
	{
		for (int j = 0; j < count; j++)
		{
			eggs->push_back(new Eggs(this->checker.getPosition().x,
				this->checker.getPosition().y,
				eggIncubate));
		}
		this->eaten = this->eaten - 5;
		leyEggTimer.restart();
		std::cout << "mamy jajo \n";
	}
	

}

void Worm::updateVariable()
{
	maxScale = data->maxScale;
	notMature = data->notMature;
	maxHungerTime = data->maxHungerTime;
	eggIncubate = data->eggIncubate;
	leyEggSpan = data->leyEggSpan;
	maxLifeTime = data->maxLifeTime;

}

