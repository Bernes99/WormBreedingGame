#pragma once

#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Worm
{
private:
	sf::Texture texture; // tekstura robaka
	sf::Sprite sprite; //obiekt robaka z tekstur¹
	sf::RectangleShape checker;//obiekt porzebny do sprawdzania kolizji z pod³og¹
	
	int maxScale=10; // maksymalny rozmiar jaki moze urosn¹æ robak
	
	sf::Clock timer; // zegar odpowiedzialny za zatrzymywanie sie robaków w miejscu
	float howLongStay = 2.0f; // jak d³ugo robak stoi w miejscu

	sf::Clock deathTime;// zegar odlczajacy do œmeirci robaka
	float maxLifeTime = 120.f; //maxymalny czas zycia
	
	bool allowMove = true; // czy robak moze sie poruszaæ
	//sf::Time elapseTime;
	
	bool allowRandom = false; //czy pozwolic na losowanie pozycji
	float xMove; // wylosowana pozycja x do której porusza sie robak
	float prev=0; // poprzedna wylosowana pozycja

	/// <summary>
	/// za³adowuje teksture i tworzy sprita
	/// </summary>
	void loadSprite();

public:
	int eaten = 0; // zjedzone jedzienie do nastepnego wzrostu
	
	/// <summary>
	/// poruszanie sie robaka
	/// </summary>
	/// <param name="windowSizeX">okno w którym porusza sie robak(takie samo jak rysowanie)</param>
	void movment(int windowSizeX,float dt);

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

	/// <summary>
	/// sprawdza ile czy robak nie przekroczy³ swojej max dlugosci zycia
	/// jezeli zosta³o robakowi malo czasu zmienia jego kolor
	/// </summary>
	/// <returns> zwraca prawde jezeli robak przekroczy³ max d³ugoœæ zycia</returns>
	bool wormDeath();
};

