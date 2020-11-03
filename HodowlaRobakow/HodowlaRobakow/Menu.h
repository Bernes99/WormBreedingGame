#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



class Menu
{
private:
	sf::RenderWindow* menuWindow;
	std::vector<sf::Texture> textures;

public:
	Menu();
	~Menu();

	void update();
	void render();




};

