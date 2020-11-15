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
	int food=0;
	

public:
	Ground();
	void setPosition(int x, int y);
	sf::RectangleShape getGround();


};

