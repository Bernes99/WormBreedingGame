#pragma once

#include "Menu.h"
#include "World.h"
#define SIM_WINDOW_X 1024
#define SIM_WINDOW_Y 768
#define MENU_WINDOW_X 200
#define MENU_WINDOW_Y 200

class Simulation
{
private:

	//zmienne
	sf::RenderWindow* window; //okno symulacji
	sf::RenderWindow* optionWindow; // okno opcji 
	sf::Event sfEvent; //fsml event

	Menu *menu; //menu opcji
	World *world;

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

