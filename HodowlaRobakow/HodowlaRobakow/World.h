#pragma once
#include "Ground.h"
#include <vector>

#include "Worm.h"
#include "Eggs.h"




class World
{
	std::vector<std::vector<Ground*>> floor;
	std::vector <Worm*> worms;
	std::vector <Eggs*> eggs;
	//Worm *worm;
	
	std::vector<Ground*> whereIsWorm; ///


	sf::Clock eatTimer; /// zegar odpowiadajacy za za obliczannie przerwy miedzy jedzeniem przez robaka

	sf::Clock groundTimer; /// zegar odpowiedzialny za odnawianie sie jedzneia na powierzchni
	
	sf::Clock hungerTimer; /// zegar odpowiedzialny za czas skladania jaja
	float hungerSpan = 2;


	float restoreFoodTime=10.0f; /// szybkosc odnawiania sie podloza

	void floorInit();
	void wormsInit();

	int xWorldSize; /// rozmiar x planszy symulacji
	int yWorldSize; /// rozmiar y planszy symulacji

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
protected:
	int countNewWorms = 2; /// ilosc robaków z 1 jajka 
public:
	World(int x,int y);
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

	void worldReSize(int x, int y);

	
};

