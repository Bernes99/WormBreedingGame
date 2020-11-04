#include "Button.h"




void Button::upButton()
{
	button.setSize(sf::Vector2f(20.0f, 20.f));
	button.setOrigin(button.getSize().x / 2.0f, button.getSize().y / 2.0f);
	button.setOutlineThickness(1.0f);
	button.setOutlineColor(sf::Color::Black);
	text.setString(">");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(10);
	text.setPosition(
		button.getPosition().x + (button.getGlobalBounds().width / 2.0f) - text.getGlobalBounds().width / 2.0f,
		button.getPosition().x + (button.getGlobalBounds().height / 2.0f) - text.getGlobalBounds().height / 2.0f);
}

void Button::downButton()
{
	button.setSize(sf::Vector2f(20.0f, 20.f));
	button.setOrigin(button.getSize().x / 2.0f, button.getSize().y / 2.0f);
	button.setOutlineThickness(1.0f);
	button.setOutlineColor(sf::Color::Black);
	text.setString("<");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(10);
	text.setPosition(
		button.getPosition().x + (button.getGlobalBounds().width / 2.0f) - text.getGlobalBounds().width / 2.0f,
		button.getPosition().x + (button.getGlobalBounds().height / 2.0f) - text.getGlobalBounds().height / 2.0f);
}

void Button::setPosition(int x, int y)
{
	button.setPosition(x, y);
}

void Button::setColor(int r, int g, int b, int a)
{
	button.setFillColor(sf::Color(r, g, b, a));
}

sf::RectangleShape Button::getButton()
{
	return button;
}


