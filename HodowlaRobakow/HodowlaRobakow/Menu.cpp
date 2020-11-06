#include "Menu.h"



void Menu::initButtons()
{
	initSet0();
}

void Menu::drawButton(sf::RenderWindow* window, Button button)
{
	
	window->draw(button.getButton());
	window->draw(button.getButtonText());
}

void Menu::initSet0()
{
	set0[0].valueFild();
	set0[0].setColor(120, 120, 120, 255);
	set0[0].setPosition(30, 30);

	set0[1].upButton();
	set0[1].setColor(60, 60, 60, 255);
	set0[1].setPosition(
		set0[0].getButton().getPosition().x + set0[0].getButton().getSize().x +2,
		set0[0].getButton().getPosition().y - set0[0].getButton().getSize().y /2 );

	set0[2].downButton();
	set0[2].setColor(60, 60, 60, 255);
	set0[2].setPosition(
		set0[0].getButton().getPosition().x + set0[0].getButton().getSize().x + 2,
		set0[0].getButton().getPosition().y + set0[0].getButton().getSize().y / 2 );
}

Menu::Menu()
{
	initButtons();
	
}

void Menu::update()
{
	std::cout << "siemanko";
}

void Menu::drawMenu(sf::RenderWindow* window)
{
	for (int i = 0; i < 3; i++)
	{
		drawButton(window, set0[i]);
	}
}
