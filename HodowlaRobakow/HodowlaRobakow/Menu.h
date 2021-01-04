#pragma once

#include "Button.h"
#include <vector>
#include "data.h"

class Menu
{
private:
	variable* data; /// wskaŸnik na zmienne odzia³uj¹ce na symulacje na bierz¹co 

	/// <summary>
	/// inicjalizacja przycisków ca³ego menu
	/// </summary>
	void initButtons();

	/// <summary>
	/// inicjalizacja przycisków nemy pierwszego okna s³u¿¹cego do ustalenia rozmiaru œwiata symulacji
	/// </summary>
	void initWorldSizeButtons();
	
	int setsNumber = 11; /// liczba zestawów przycisków do zmiennych
	std::vector<std::vector<Button*>> sets;/// tablica przycisków zestawów przycisków gdzie indeks 0 to zmienna ,1 to przycisk zwiekszania, 2 przycisk zmniejszania, 3 teks który mówi co to za zmienna
	Button *send; /// przycisk potwierdzenia wielkoœci œwiata w pierwszym oknie symulacji
	
	/// <summary>
	/// funkcaj inicjuje set 0 zmiennej przycisków 
	/// </summary>
	void initSet();

	/// <summary>
	/// inicjalizacja wartoœci domyœlnych przycisków
	/// </summary>
	void initValues(int i);

public:

	
	/// <summary>
	/// konstruktor do tworzenia menu w³aœciwego
	/// </summary>
	Menu(variable* pData);

	/// <summary>
	/// konstruktor do tworzenia menu w pierwszym oknie
	/// </summary>
	Menu(variable* pData,bool worldSize);
	
	/// <summary>
	/// aktualizuje wartoœci zmiennych w strukturze data gdzie przechowywane s¹ aktualne wartoœci ustawionych zmiennych
	/// </summary>
	void update();

	/// <summary>
	/// funkcja rysuje przyciski na podanym oknie
	/// </summary>
	/// <param name="window"> - wskaŸnik na okno na ktorym rysowane bed¹ przyciski </param>
	void drawMenu(sf::RenderWindow* window);


	/// <summary>
	/// funkca rysuje przyciski pocz¹tkowe na podanym oknie
	/// </summary>
	/// <param name="window"> - wskaŸnik na okno na ktorym rysowane bed¹ przyciski </param>
	void drawWorldSizeMenu(sf::RenderWindow* window);

	/// <summary>
	/// funkcja sprawdza czy zosta³ klikniêty przycisk do zmiany wartoœci
	/// </summary>
	/// <param name="mousePos"> - pozycja myszki na oknie </param>
	void isClicked(sf::Vector2i mousePos);

	/// <summary>
	/// funkcja sprawdza czy zosta³ klikniêty przycisk na menu pocz¹tkowym
	/// </summary>
	/// <param name="mousePos"> - pozycja myszki na oknie </param>
	/// <param name="worldSize"> - wskaŸnik na sfml Vektor intów przechowuj¹cy rozmiar ustawionego œwiata </param>
	bool isClickedWorldSize(sf::Vector2i mousePos, sf::Vector2i *worldSize);

	
};

