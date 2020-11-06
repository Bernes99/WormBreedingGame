#pragma once

#include "Menu.h"


class Simulation
{
private:

	//zmienne
	sf::RenderWindow* window; //okno symulacji
	sf::RenderWindow* optionWindow; // okno opcji 
	sf::Event sfEvent; //fsml event

	Menu *menu; //menu opcji

	// delta time 
	sf::Clock dtClock; // delta time clock
	float dt; // deltaTime


	/// <summary>
	/// inicjalizacja obu okien
	/// </summary>
	void initWindow();


public:

	// kosntruktor / dekonstruktor
	Simulation();
	virtual ~Simulation();

	//funkcje

	/// <summary>
	/// aktualizowanie zdazen obsblugujacych grafike
	/// </summary>
	void updateSFMLEvents();

	/// <summary>
	/// uruchamianie programu
	/// </summary>
	void run();

	/// <summary>
	/// aktualizowanie ekranu
	/// </summary>
	void update();

	/// <summary>
	/// weswietlanie ekranu
	/// </summary>
	void render();

	/// <summary>
	/// aktualizuje zmienna dt o czas jaki jest potrzebny do wygenerowania klatki
	/// </summary>
	void updateDt();

};

