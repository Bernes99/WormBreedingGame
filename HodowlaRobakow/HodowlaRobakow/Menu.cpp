#include "Menu.h"



void Menu::initButtons()
{
	button1.upButton();
	//aaa.setSize(sf::Vector2f(20.0f, 20.f));

}

Menu::Menu()
{
	this->initButtons();

}

void Menu::update()
{
	std::cout << "siemanko";
}

void Menu::renderMenu(sf::RenderWindow* window)
{
	window->draw(button1.button);
	
}
