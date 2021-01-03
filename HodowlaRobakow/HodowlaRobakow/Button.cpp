#include "Button.h"


Button::Button()
{
	

	font.loadFromFile("../Resources/Font/arial.ttf");
	text.setFont(font);
	//value = new int{ 0 };
	
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
	text.setOrigin(17 , text.getCharacterSize() - 13);
	text.setRotation(-90);

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
	text.setOrigin(17, text.getCharacterSize() - 13);
	text.setRotation(-90);
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
	
	return text;
}

void Button::setTextFixPosition()
{
	text.setPosition(
		button.getPosition().x + (button.getGlobalBounds().width / 2.0f) - 1.25f*text.getGlobalBounds().width / 2.0f,
		button.getPosition().y + (button.getGlobalBounds().height / 2.0f) - 2.5f*text.getGlobalBounds().height / 2.0f);
}

void Button::valueFild()
{
	button.setSize(sf::Vector2f(45.0f, 20.f));
	button.setOrigin(button.getSize().x / 2.0f, button.getSize().y / 2.0f);
	button.setOutlineThickness(1.0f);
	button.setOutlineColor(sf::Color::Black);
	button.setOrigin(button.getPosition().x / 2.0f, button.getPosition().y / 2.0f);

	text.setString(precision(value, 2));
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(15);
	
}

void Button::nameFild(sf::String text)
{
	
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(15);
}

void Button::setNamePosition(int x,int y)
{

	text.setPosition(sf::Vector2f(x, y));
}

void Button::increasValue(float i , float downLimit, float upLimit)
{
	if ((i<0 && value <= downLimit)||(i > 0 && value >= upLimit))
	{
		return;
	}

	value = value + i;
	text.setString(precision(value,2));
	
}

void Button::setValue(float i)
{
	value = i;
}

float Button::getValue()
{
	return value;
}

std::string Button::precision(float num, int precision)
{
	std::string temp;

	temp = std::to_string(num);
	temp = temp.substr(0, temp.find(".") + precision + 1);

	return temp;
}

void Button::setSize(float x, float y)
{
	button.setSize(sf::Vector2f(x, y));
}




