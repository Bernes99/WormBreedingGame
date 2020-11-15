#include "Ground.h"

Ground::Ground()
{
	ground.setSize(sf::Vector2f(64.0f, 20.f));
	ground.setOutlineThickness(1.f);
	ground.setOutlineColor(sf::Color(0, 102, 0, 255));
	ground.setFillColor(sf::Color::Green);
}

void Ground::setPosition(int x, int y)
{
	ground.setPosition(sf::Vector2f(x, y));
}

sf::RectangleShape Ground::getGround()
{
	return ground;
}
