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
	sf::RectangleShape button; // kaszat³t przycisku
	sf::Text text; //tekst przycisku 
	sf::Font font; // font przycisk
	int value=0; // wartosc zmiennej

	
public:
	
	Button();
	//~Button();

	/// <summary>
	/// ustawia przycisk jako przycisk dodawania
	/// </summary>
	void upButton();

	/// <summary>
	/// ustawia przycisk jako przycisk odejmowania
	/// </summary>
	void downButton();

	/// <summary>
	/// ustawia pozycje przycisku w oknie
	/// </summary>
	/// <param name="x">szerokoœæ od lewej</param>
	/// <param name="y">wysokosc od góry</param>
	void setPosition(int x, int y);

	/// <summary>
	/// ustawia kolor t³a przycisku wed³ug schemat RGBA
	/// </summary>
	/// <param name="r">RED</param>
	/// <param name="g">GREAN</param>
	/// <param name="b">BLUE</param>
	/// <param name="a">ALPHA</param>
	void setColor(int r, int g, int b, int a);


	/// <summary>
	/// zwraca zmienna kszta³tu przycisku
	/// </summary>
	/// <returns>kszta³t prostok¹ta </returns>
	sf::RectangleShape getButton();

	/// <summary>
	/// zwraca tekst przycisku
	/// </summary>
	/// <returns>tekst przycisku</returns>
	sf::Text getButtonText();

	/// <summary>
	/// ustawiwia pozycje tekstu wzgledem przycisku
	/// </summary>
	void setTextPosition();

	/// <summary>
	/// ustawia przycisk jako pole z wartosci¹ 
	/// </summary>
	void valueFild();

};



