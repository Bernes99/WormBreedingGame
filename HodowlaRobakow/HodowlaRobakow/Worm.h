#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>


class Worm
{
private:
	sf::Texture texture; // tekstura robaka
	sf::Sprite sprite; //obiekt robaka z tekstur¹
	sf::RectangleShape checker;//obiekt porzebny do sprawdzania kolizji z pod³og¹
	int maxScale=10;
	
	/// <summary>
	/// za³adowuje teksture i tworzy sprita
	/// </summary>
	void loadSprite(); 
	bool allowRandom = false; //czy pozwolic na losowanie pozycji
	int xMove; // wylosowana pozycja x do której porusza sie robak

public:
	int eaten = 0;
	/// <summary>
	/// poruszanie sie robaka
	/// </summary>
	/// <param name="windowSizeX">okno w którym porusza sie robak(takie samo jak rysowanie)</param>
	void movment(int windowSizeX);
	/// <summary>
	/// konstruktor robaka
	/// </summary>
	/// <param name="wormPosX">startowa pozycja x robaka</param>
	/// <param name="wormPosY">startowa pozycja y robaka</param>
	Worm(int wormPosX,int wormPosY);
	
	/// <summary>
	/// zwraca spirta robaka
	/// </summary>
	/// <returns>sprite robaka</returns>
	sf::Sprite getWorm();

	sf::RectangleShape getChecker();

	void reScale();


};

