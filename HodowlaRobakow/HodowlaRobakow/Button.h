#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Button
{

private:
	
	
	


public:
	sf::RectangleShape button;
	sf::Text text;

	//Button();
	//~Button();

	void upButton();

	void downButton();

	void setPosition(int x, int y);

	void setColor(int r, int g, int b, int a);

	sf::RectangleShape getButton();

};



