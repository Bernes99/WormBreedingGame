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

void Worm::movment(int windowSizeX)
{
	timer.restart();
	if (allowRandom)
	{
		xMove = 0;
		xMove = rand() % windowSizeX + 1 - sprite.getTexture()->getSize().x;
		std::cout << xMove;
		allowRandom = false;
	}

	if (checker.getPosition().x > windowSizeX - sprite.getTexture()->getSize().x)
	{
		std::cout << sprite.getPosition().x;
		sprite.move(-1, 0);
		checker.move(-1, 0);
		//sprite.move(0, 0);
	}
	else if (checker.getPosition().x < 0)
	{
		std::cout << sprite.getPosition().x;
		sprite.move(1, 0);
		checker.move(1, 0);
		//sprite.move(0, 0);
	}
	else if(checker.getPosition().x != xMove)
	{
		if (checker.getPosition().x < xMove)
		{
			sprite.move(1, 0);
			checker.move(1, 0);
		}
		else
		{
			sprite.move(-1, 0);
			checker.move(-1, 0);
		}
	}
	else
	{
		sprite.move(0, 0);
		/*while (timer.getElapsedTime().asSeconds() < 4)
		{

		}
		timer.restart();*/
		allowRandom = true;
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
	checker.setPosition(sprite.getPosition().x + sprite.getTexture()->getSize().x,
						sprite.getPosition().y + sprite.getTexture()->getSize().y);
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
	if (eaten >= 10 && maxScale > sprite.getScale().x)
	{
		sprite.setScale(sprite.getScale().x+0.25f, sprite.getScale().y+ 0.25f);
		sprite.setPosition(sprite.getPosition().x,
						   sprite.getPosition().y - sprite.getTexture()->getSize().y/4);
		eaten = 0;
	}
	
}


