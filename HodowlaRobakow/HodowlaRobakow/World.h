#pragma once
#include "Ground.h"
#include <vector>
#include "Worm.h"

class World
{
	std::vector <Ground*> floor;
	std::vector <Worm*> worms;
	//Worm *worm;

	sf::Clock eatTimer; /// zegar odpowiadajacy za za obliczannie przerwy miedzy jedzeniem przez robaka

	sf::Clock groundTimer; /// zegar odpowiedzialny za odnawianie sie jedzneia na powierzchni

	float restoreFoodTime=10.0f;

	void floorInit();
	void wormsInit();

	/// <summary>
	/// sprawdza ktrórego fragmentu pod³ogi dotyka robak
	/// </summary>
	/// <param name="wormNumber"> - indeks robaka w wektorze</param>
	/// <returns>zwraca wskacnik na obiekt Ground</returns>
	Ground* checker(int wormNumber);

	/// <summary>
	/// zwiêksza zmienna odpowiedzialna za ilosc pozywiena jaka zjadl robak
	/// oraz wywoluje funkcje zwiekszajaca jego rozmiar(o ile zjad³ wystarczajaco)
	/// </summary>
	/// <param name="wormNumber"> - indeks robaka</param>
	/// <returns>zwraca wskaŸnik na obiekt robaka</returns>
	Worm* foodEaten(int wormNumber);
public:
	World();
	~World();


	/// <summary>
	/// aktualizuje stan swiata
	/// </summary>
	void update();

	/// <summary>
	/// rysowanie swiata
	/// </summary>
	/// <param name="window">okno na którym jest rysowanie</param>
	/// <param name="dt">delta time</param>
	void drawWorld(sf::RenderWindow* window,float dt);

	
};

