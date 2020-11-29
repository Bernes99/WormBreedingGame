#include "Worm.h"

void Worm::loadSprite()
{
	if (!texture.loadFromFile("../Resources/Textures/worm.png"))
	{
		std::cout << "blad zaladowaia tekstury robaka";
		system("pause");
	}
	sprite.setTexture(texture);

}

void Worm::checkerFixPosition()
{
	checker.setPosition(sprite.getPosition().x + sprite.getScale().x * sprite.getTexture()->getSize().x / 2,
		checker.getPosition().y);
}

void Worm::movment(int windowSizeX,float dt)
{
	
	if (allowMove)
	{
		if (allowRandom)
		{
			prev = xMove;
			xMove = 0;
			xMove = rand() % windowSizeX  - sprite.getTexture()->getSize().x/2;
			while (prev == xMove)
			{
				xMove = rand() % windowSizeX - sprite.getTexture()->getSize().x / 2;
			}

			std::cout << xMove;

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
		}
		

		if (checker.getPosition().x > windowSizeX - sprite.getTexture()->getSize().x)
		{
			std::cout << sprite.getPosition().x;
			sprite.move(-2, 0);
			checker.move(-2, 0);
			//sprite.move(0, 0);
		}
		else if (checker.getPosition().x < 0)
		{
			std::cout << sprite.getPosition().x;
			sprite.move(2, 0);
			checker.move(2, 0);
			//sprite.move(0, 0);
		}
		else if (checker.getPosition().x > xMove+0.5f || checker.getPosition().x < xMove - 0.5f)
		{
			if (checker.getPosition().x < xMove)
			{
				
				sprite.move(100.f * dt, 0);
				checker.move(100.f * dt, 0);
			}
			else
			{
				sprite.move(-100.f * dt, 0);
				checker.move(-100.f * dt, 0);
			}
			//std::cout << dt << std::endl;
		}
		else
		{
			sprite.move(0, 0);
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

Worm::Worm(int wormPosX, int wormPosY)
{

	loadSprite();

	srand(time(NULL));
	allowRandom = true;
	sprite.setPosition(wormPosX, wormPosY);
	

	xMove = sprite.getPosition().x;

	checker.setSize(sf::Vector2f(1,1));
	checker.setPosition(sprite.getPosition().x - sprite.getTexture()->getSize().x / 2,
						sprite.getPosition().y + sprite.getTexture()->getSize().y);
	
	timer.restart();
	
	checker.setFillColor(sf::Color::Blue);
}

sf::Sprite Worm::getWorm()
{
	return sprite;
}

sf::RectangleShape Worm::getChecker()
{
	return checker;
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

			eaten = 0;
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

			eaten = 0;
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
	else if(deathTime.getElapsedTime().asSeconds() > maxLifeTime*0.75f)
	{
		sprite.setColor(sf::Color::Red);
	}
	return false;
}


