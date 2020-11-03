#pragma once
#include "Menu.h"


class Button:Menu
{

private:
	sf::RectangleShape button;
	
	Button();
	~Button();


	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);

};

