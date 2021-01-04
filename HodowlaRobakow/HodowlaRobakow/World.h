#pragma once
#include "Ground.h"
#include <vector>

#include "Worm.h"
#include "Eggs.h"




class World
{
	std::vector<std::vector<Ground*>> floor; ///vektor vektrów pod³o¿a
	std::vector <Worm*> worms; /// vektor robaków
	std::vector <Eggs*> eggs; /// wektor jajek
	
	
	std::vector<Ground*> whereIsWorm; /// vektor pomocniczy który przechowuje pod³o¿a na których w danej klatce stoj¹ robaki 

	variable* data; /// wskaŸnik na zmienne odzia³uj¹ce na symulacje na bierz¹co


	sf::Clock eatTimer; /// zegar odpowiadajacy za za obliczannie przerwy miedzy jedzeniem przez robaka

	sf::Clock groundTimer; /// zegar odpowiedzialny za odnawianie sie jedzneia na powierzchni
	
	sf::Clock hungerTimer; /// zegar odpowiedzialny za czas skladania jaja
	float hungerSpan; /// dostêp czasu w sekundach miêdzy spadkiem najedzenia robaka

	float eatSpeed; ///predkosc z jak jedz¹ robaki

	float restoreFoodTime; /// szybkosc odnawiania sie podloza

	/// <summary>
	/// inicjalizuje pod³o¿e symulacji
	/// </summary>
	void floorInit();

	/// <summary>
	/// inicjuje startowe robaki w symulacji
	/// </summary>
	void wormsInit();

	int xWorldSize; /// rozmiar x planszy symulacji
	int yWorldSize; /// rozmiar y planszy symulacji

	/// <summary>
	/// sprawdza ktrórego fragmentu pod³ogi dotyka robak
	/// </summary>
	/// <param name="wormNumber"> - indeks robaka w wektorze</param>
	/// <returns> - zwraca wskaŸnik na obiekt Ground</returns>
	Ground* checker(int wormNumber);

	/// <summary>
	/// zwiêksza zmienna odpowiedzialna za ilosc pozywiena jaka zjadl robak
	/// oraz wywoluje funkcje zwiekszajaca jego rozmiar(o ile zjad³ wystarczajaco)
	/// </summary>
	/// <param name="wormNumber"> - indeks robaka</param>
	/// <returns> - zwraca wskaŸnik na obiekt robaka</returns>
	Worm* foodEaten(int wormNumber);
protected:


	int countNewWorms; /// ilosc robaków z 1 jajka 

public:

	/// <summary>
	/// konstruktor ustawiaj¹cy do zmiennych rozmiar œwiata i zmiene dzia³aj¹ce na symulacje oraz wywo³uje inicjalizacje terenu i robaków
	/// </summary>
	/// <param name="worldSize"> - rozmiar œwiata jako vektor </param>
	/// <param name="data"> - wskaŸnik na strukture z zmiennymi oddzia³uj¹cymi na bie¿¹co ns symulacje</param>
	World(sf::Vector2i worldSize, variable* data);

	
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

	/// <summary>
	/// funkcja aktualizuje zmienne odzia³uj¹ce na symulacje na bierz¹co
	/// </summary>
	void updateVariable();
	
	/// <summary>
	/// sprawdza czy podana pozycja myszki zawiera sie w œwiecie symulacji
	/// </summary>
	/// <param name="mousePos"> - pozycja myszki na oknie </param>
	void isClicked(sf::Vector2i mousePos);
	
};

