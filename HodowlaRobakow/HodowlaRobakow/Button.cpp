#include "Button.h"




Button::Button()
{
	font.loadFromFile("../Resources/Font/arial.ttf");
	text.setFont(font);

}

void Button::upButton()
{
	button.setSize(sf::Vector2f(20.0f, 15.f));
	button.setOrigin(button.getSize().x / 2.0f, button.getSize().y / 2.0f);
	button.setOutlineThickness(1.0f);
	button.setOutlineColor(sf::Color::Black);
	button.setOrigin(button.getPosition().x / 2.0f, button.getPosition().y / 2.0f);

	text.setString(">");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(20);

}

void Button::downButton()
{
	button.setSize(sf::Vector2f(20.0f, 15.f));
	button.setOrigin(button.getSize().x / 2.0f, button.getSize().y / 2.0f);
	button.setOutlineThickness(1.0f);
	button.setOutlineColor(sf::Color::Black);
	button.setOrigin(button.getPosition().x / 2.0f, button.getPosition().y / 2.0f);

	text.setString("<");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(20);
}

void Button::setPosition(int x, int y)
{
	button.setPosition(sf::Vector2f(x, y));
}

void Button::setColor(int r, int g, int b, int a)
{
	button.setFillColor(sf::Color(r, g, b, a));
}

sf::RectangleShape Button::getButton()
{
	return button;
}

sf::Text Button::getButtonText()
{
	setTextPosition();
	return text;
}

void Button::setTextPosition()
{
	text.setPosition(
		button.getPosition().x + (button.getGlobalBounds().width / 2.0f) - 1.25f*text.getGlobalBounds().width / 2.0f,
		button.getPosition().y + (button.getGlobalBounds().height / 2.0f) - 2.5f*text.getGlobalBounds().height / 2.0f);
}

void Button::valueFild()
{
	button.setSize(sf::Vector2f(30.0f, 20.f));
	button.setOrigin(button.getSize().x / 2.0f, button.getSize().y / 2.0f);
	button.setOutlineThickness(1.0f);
	button.setOutlineColor(sf::Color::Black);
	button.setOrigin(button.getPosition().x / 2.0f, button.getPosition().y / 2.0f);

	text.setString(std::to_string(value));
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(15);
	
}


