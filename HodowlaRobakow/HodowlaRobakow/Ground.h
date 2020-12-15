#pragma once

#include <SFML/Graphics.hpp>
#include "data.h"

class Ground
{
protected:
	sf::RectangleShape ground; /// kszta³t podloza
	float maxFood=100; /// max ilosc jedzenia na podlozu
	float food=maxFood; /// obecna ilosc jedzenia na podlozu
	//float restoreSpeed = 1;
	
	variable *data;

public:
	/// <summary>
	/// konstruktor ground ustawiajacy kolor i rozmiar 
	/// </summary>
	Ground(variable* data);

	/// <summary>
	/// ustawia pozycje pojedynczego pod³oza
	/// </summary>
	/// <param name="x"> - wspolrzedne x </param>
	/// <param name="y"> - wspolrzedne y </param>
	void setPosition(int x, int y);

	/// <summary>
	/// zwraca kszta³t pod³oza
	/// </summary>
	/// <returns> - rysowalny prostokat </returns>
	sf::RectangleShape getGround();

	/// <summary>
	/// odejmuje iloœæ zywanosci na podlozu
	/// </summary>
	/// <returns> zwraca prawde jesli jest jedzenie</returns>
	bool eatFood(int wormFood);

	/// <summary>
	/// przywraca ilosc zywnosci na podlozu
	/// </summary>
	void restoreFood();

	void updateValues();
};

