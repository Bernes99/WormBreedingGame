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
	//sf::RectangleShape checker;//obiekt porzebny do sprawdzania kolizji z pod³og¹
	int maxScale=10; // maksymalny rozmiar jaki moze urosn¹æ robak

	sf::Clock timer;
	bool allowMove = true;
	//sf::Time elapseTime;
	
	/// <summary>
	/// za³adowuje teksture i tworzy sprita
	/// </summary>
	void loadSprite(); 

	bool allowRandom = false; //czy pozwolic na losowanie pozycji
	int xMove; // wylosowana pozycja x do której porusza sie robak

public:
	int eaten = 0; // zjedzone jedzienie do nastepnego wzrostu
	sf::RectangleShape checker;
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
	/// zwraca sprita robaka
	/// </summary>
	/// <returns>sprite robaka</returns>
	sf::Sprite getWorm();

	/// <summary>
	/// zwraca checkera cztyli specjalny obiekt stworzony 
	/// pod robakiem do sprawdzzaania kolizji z podlog¹
	/// </summary>
	/// <returns> zwraca obiekt prostok¹ta 1 na 1 przeznaczony do sprawdzania</returns>
	sf::RectangleShape getChecker();

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
};

