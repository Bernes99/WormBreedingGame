#pragma once


#include "Button.h"



class Menu
{
private:
	//sf::RenderWindow* menuWindow;
	//std::vector<sf::Texture> textures;

	//Button *button1;
	
	void initButtons();

public:
	Button button1;
	sf::RectangleShape aaa;
	Menu();
	~Menu();

	void update();
	void renderMenu(sf::RenderWindow* window);




};

