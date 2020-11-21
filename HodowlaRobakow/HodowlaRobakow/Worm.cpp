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
	
	if (allowRandom)
	{
		xMove = 0;
		xMove = rand() % windowSizeX;
		std::cout << xMove;
		allowRandom = false;
	}

	if (sprite.getPosition().x > windowSizeX - sprite.getTexture()->getSize().x)
	{
		std::cout << sprite.getPosition().x;
		sprite.move(-1, 0);
		checker.move(-1, 0);
		//sprite.move(0, 0);
	}
	else if (sprite.getPosition().x < 0)
	{
		std::cout << sprite.getPosition().x;
		sprite.move(1, 0);
		checker.move(1, 0);
		//sprite.move(0, 0);
	}
	else if(sprite.getPosition().x != xMove)
	{
		if (sprite.getPosition().x < xMove)
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
		Sleep(2000);
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

