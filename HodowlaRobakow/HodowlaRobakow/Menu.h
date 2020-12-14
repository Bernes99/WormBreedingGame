#pragma once

#include "Button.h"
#include <vector>

class Menu
{
private:


	/// <summary>
	/// inicjalizacja przycisk�w ca�ego menu
	/// </summary>
	void initButtons();
	
	int setsNumber = 5;
	std::vector<std::vector<Button*>> sets;// tablica przycisk�w pierwszego zerowej zmiennej gdzie indeks 0 to zmienna ,1 to przycisk zwiekszania, 2 przycisk zmniejszania 

	
	/// <summary>
	/// funkcaj inicjuje set 0 zmiennej przycisk�w 
	/// </summary>
	void initSet();

	void initValues(int i);

public:
	int wroldSize;



	Menu(int wroldSize);
	
	/// <summary>
	/// jeszcze nwm
	/// </summary>
	void update();

	/// <summary>
	/// funkcja rysuje przyciski na podanym oknie
	/// </summary>
	/// <param name="window"> - okno na ktorym rysowane bed� przyciski </param>
	void drawMenu(sf::RenderWindow* window);

	void isClicked(sf::Vector2i mousePos, int* worldSize);

	
};

