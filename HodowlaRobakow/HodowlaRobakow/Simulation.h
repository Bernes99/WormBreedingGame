#pragma once

#include "Menu.h"


class Simulation
{
private:

	//zmienne
	sf::RenderWindow* window;
	sf::RenderWindow* optionWindow;
	sf::Event sfEvent;

	Menu *menu;

	// delta time 
	sf::Clock dtClock;
	float dt;


	//inicjalizacja
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

