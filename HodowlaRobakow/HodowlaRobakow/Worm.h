#pragma once


#include "Creature.h"
#include "Eggs.h"


class Worm : public Creature
{
private:

	/// maksymalny rozmiar jaki moze urosn¹æ robak
	int maxScale; 

	/// wskaŸnik na zmienne odzia³uj¹ce na symulacje na bierz¹co
	variable* data;  
	
	/// zegar odpowiedzialny za zatrzymywanie sie robaków w miejscu
	sf::Clock timer; 
	/// jak d³ugo robak stoi w miejscu
	float howLongStay = 2.0f; 

	/// czy robak moze sie poruszaæ
	bool allowMove = true; 
	/// czy robak poprzednio porusza³ sie w prawo
	bool isPrevRight; 
	
	///czy pozwolic na losowanie pozycji
	bool allowRandom = false; 
	/// wylosowana pozycja x do której porusza sie robak
	float xMove; 
	/// poprzedna wylosowana pozycja x
	float prevX=0; 
	/// wylosowana pozycja y do której porusza sie robak
	float yMove;
	/// poprzedna wylosowana pozycja y
	float prevY = 0;

	/// predkosc poruszania sie robaka
	float speed = 100.f;

	/// % zycie gdy robak sie nie rozmanaz
	float notMature; 

	/// czy robak przymiera g³odem
	bool hungerDie = false; 
	/// czas jaki robak przymiera glodem
	sf::Clock hungerTimer; 
	/// maksymalny czas na g³odzie 
	float maxHungerTime; 

	/// wskaŸnik do przekazywania vektora jajek
	std::vector <Eggs*>* eggs; 

	/// ile jajko bedzie sie wykluwaæ 
	float eggIncubate; 

public:
	/// aktualnie zjedzone jedzenie
	float eaten=3.f; 
	/// zegar odpowiedzialny za czas sk³adania jaja
	sf::Clock leyEggTimer; 
	/// odstep pomiêdzy mozliwoscia kolejnego jajka
	float leyEggSpan; 


	/// <summary>
	/// poruszanie sie robaka
	/// </summary>
	/// <param name="windowSizeX">okno w którym porusza sie robak(takie samo jak rysowanie)</param>
	void movment(int worldSizeX,int worldSizeY,float dt);
	
	/// <summary>
	/// konstruktor domyslny
	/// </summary>
	Worm() = default;

	/// <summary>
	/// konstruktor robaka
	/// </summary>
	/// <param name="wormPosX">startowa pozycja x robaka</param>
	/// <param name="wormPosY">startowa pozycja y robaka</param>
	Worm(int wormPosX,int wormPosY, std::vector <Eggs*>* egg, variable* data);


	/// <summary>
	/// sprawdza czy robak zjad³ dostatecznie duzo jedzenia
	/// a jesli tak to zwieksza jego rozmiar
	/// </summary>
	void reScale();

	/// <summary>
	/// ustawia maksymaln¹ skale do jakiej moze urosn¹æ robak
	/// </summary>
	/// <param name="maxScale"> - max skala robaka (liczba ca³kowita)</param>
	void setMaxScale(int maxScale);

	/// <summary>
	/// sprawdza ile czy robak nie przekroczy³ swojej max dlugosci zycia
	/// jezeli zosta³o robakowi malo czasu zmienia jego kolor
	/// </summary>
	/// <returns> zwraca prawde jezeli robak przekroczy³ max d³ugoœæ zycia</returns>
	bool wormDeath();

	/// <summary>
	/// sprawdza czy robak jest doros³y
	/// </summary>
	/// <returns> zwraca prawdê jezeli robak jest doras³y, fa³sz je¿eli nie jest </returns>
	bool isMature();


	/// <summary>
	/// spawnuije jajko na pozycji robaka o ile czas od ostatniego jaja nie jest zbyt ma³y
	/// </summary>
	/// <param name="count"> - liczba robaków z jednego jaja</param>
	void layEggs(int count);


	/// <summary>
	/// aktualizuje zmienne odzia³uj¹ce na symulacje na bierz¹co 
	/// </summary>
	void updateVariable();
};

