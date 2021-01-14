#pragma once
struct variable
{
	/*World*/

	/// ilosc robaków z 1 jajka 
	float countNewWorms = 2.f; 
	/// szybkosc odnawiania sie podloza
	float restoreFoodTime = 10.0f;
	/// co jaki czas spada najedzenie
	float hungerSpan = 2.f;  
	/// predkosc z jak jedz¹ robaki
	float eatSpeed = 1.f; 

	/*Worm*/

	/// maksymalny rozmiar jaki moze urosn¹æ robak
	float maxScale = 2.f; 
	/// % zycie gdy robak sie nie rozmanaz
	float notMature = 0.1f; 
	/// maksymalny czas na g³odzie 
	float maxHungerTime = 1.f; 
	///ile jajko bedzie sie wykluwaæ 
	float eggIncubate = 10.f; 
	/// odstep pomiêdzy mozliwoscia kolejnego jajka
	float leyEggSpan = 3.f; 
	///maxymalny czas zycia
	float maxLifeTime = 120.f; 
	

	/*Ground*/

	/// max ilosc jedzenia na podlozu
	float maxFood = 100.f; 


	
};