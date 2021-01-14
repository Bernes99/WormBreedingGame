#include "Creature.h"
void Creature::loadSprite(std::string path)
{
	if (!texture.loadFromFile(path))
	{
		std::cout << "blad zaladowaia tekstury robaka";
		system("pause");
	}
	sprite.setTexture(texture);

}

void Creature::setWormPosition(int positionX, int positionY)
{
	sprite.setPosition(positionX, positionY);
	checker.setPosition(sprite.getPosition().x + sprite.getTexture()->getSize().x / 2,
		sprite.getPosition().y + 4 * sprite.getTexture()->getSize().y / 5);

}

sf::Sprite* Creature::getCreature()
{
	return &sprite;
}

sf::RectangleShape Creature::getChecker()
{
	return checker;
}

void Creature::checkerFixPosition()
{
	checker.setPosition(sprite.getPosition().x + sprite.getScale().x * sprite.getTexture()->getSize().x / 2,
		checker.getPosition().y);
}