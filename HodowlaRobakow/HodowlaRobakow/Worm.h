#pragma once


#include "Creature.h"
#include "Eggs.h"


class Worm : public Creature
{
private:

	int maxScale; /// maksymalny rozmiar jaki moze urosn¹æ robak

	variable* data; /// wskaŸnik na zmienne odzia³uj¹ce na symulacje na bierz¹co 
	
	sf::Clock timer; /// zegar odpowiedzialny za zatrzymywanie sie robaków w miejscu
	float howLongStay = 2.0f; /// jak d³ugo robak stoi w miejscu

	bool allowMove = true; /// czy robak moze sie poruszaæ
	bool isPrevRight; /// czy robak poprzednio porusza³ sie w prawo
	
	bool allowRandom = false; ///czy pozwolic na losowanie pozycji
	float xMove; /// wylosowana pozycja x do której porusza sie robak
	float prevX=0; /// poprzedna wylosowana pozycja x
	float yMove; /// wylosowana pozycja y do której porusza sie robak
	float prevY = 0;/// poprzedna wylosowana pozycja y

	float speed = 100.f;/// predkosc poruszania sie robaka

	float notMature; /// % zycie gdy robak sie nie rozmanaz

	bool hungerDie = false; /// czy robak przymiera g³odem
	sf::Clock hungerTimer; /// czas jaki robak przymiera glodem
	float maxHungerTime; /// maksymalny czas na g³odzie 

	std::vector <Eggs*>* eggs; /// wskaŸnik do przekazywania vektora jajek

	float eggIncubate; /// ile jajko bedzie sie wykluwaæ 

public:
	float eaten=3.f; /// aktualnie zjedzone jedzenie
	sf::Clock leyEggTimer; /// zegar odpowiedzialny za czas sk³adania jaja
	float leyEggSpan; /// odstep pomiêdzy mozliwoscia kolejnego jajka


	/// <summary>
	/// poruszanie sie robaka
	/// </summary>
	/// <param name="windowSizeX">okno w którym porusza sie robak(takie samo jak rysowanie)</param>
	void movment(int worldSizeX,int worldSizeY,float dt);
	
	
	Worm() = default;

	/// <summary>
	/// konstruktor robaka
	/// </summary>
	/// <param name="wormPosX">startowa pozycja x robaka</param>
	/// <param name="wormPosY">startowa pozycja y robaka</param>
	Worm(int wormPosX,int wormPosY, std::vector <Eggs*>* egg, variable* data);

	~Worm();

	

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

