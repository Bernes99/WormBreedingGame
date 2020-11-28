#pragma once

#include <SFML/Graphics.hpp>


class Ground
{
protected:
	sf::RectangleShape ground;
	float maxFood=100;
	float food=maxFood;
	//float restoreSpeed = 1;
	

public:
	Ground();
	void setPosition(int x, int y);
	sf::RectangleShape getGround();
	void eatFood();
	void restoreFood();


};

