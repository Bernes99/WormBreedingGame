#pragma once


#include "Button.h"


class Menu
{
private:

	/// <summary>
	/// inicjalizacja przycisków ca³ego menu
	/// </summary>
	void initButtons();
	
	
	Button set0[3] = {Button(),Button(),Button() }; // tablica przycisków pierwszego zerowej zmiennej gdzie indeks 0 to zmienna ,1 to przycisk zwiekszania, 2 przycisk zmniejszania 

	/// <summary>
	/// sk³ada w sobie rysowanie tekstu oraz obszaru przycisku
	/// </summary>
	/// <param name="window">- okno na ktorym rysowane bed¹ przyciski</param>
	/// <param name="button">- rysowany przycisk</param>
	void drawButton(sf::RenderWindow* window, Button button);
	
	/// <summary>
	/// funkcaj inicjuje set 0 zmiennej przycisków 
	/// </summary>
	void initSet0();

public:
	
	Menu();
	
	/// <summary>
	/// jeszcze nwm
	/// </summary>
	void update();

	/// <summary>
	/// funkcja rysuje przyciski na podanym oknie
	/// </summary>
	/// <param name="window"> - okno na ktorym rysowane bed¹ przyciski </param>
	void drawMenu(sf::RenderWindow* window);

};

