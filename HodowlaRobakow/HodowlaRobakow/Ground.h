#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Ground
{
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

