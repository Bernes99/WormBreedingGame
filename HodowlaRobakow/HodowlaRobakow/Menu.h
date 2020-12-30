#pragma once

#include "Button.h"
#include <vector>
#include "data.h"

class Menu
{
private:
	variable* data;

	/// <summary>
	/// inicjalizacja przycisków ca³ego menu
	/// </summary>
	void initButtons();
	
	int setsNumber = 11;
	std::vector<std::vector<Button*>> sets;// tablica przycisków pierwszego zerowej zmiennej gdzie indeks 0 to zmienna ,1 to przycisk zwiekszania, 2 przycisk zmniejszania 

	
	/// <summary>
	/// funkcaj inicjuje set 0 zmiennej przycisków 
	/// </summary>
	void initSet();

	void initValues(int i);

public:
	int wroldSize;

	

	Menu(int wroldSize, variable* pData);
	
	/// <summary>
	/// jeszcze nwm
	/// </summary>
	void update();

	/// <summary>
	/// funkcja rysuje przyciski na podanym oknie
	/// </summary>
	/// <param name="window"> - okno na ktorym rysowane bed¹ przyciski </param>
	void drawMenu(sf::RenderWindow* window);

	void isClicked(sf::Vector2i mousePos);

	
};

