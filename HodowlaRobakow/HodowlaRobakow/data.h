#pragma once
struct variable
{
	/*World*/
	float countNewWorms = 2.f; /// ilosc robaków z 1 jajka 
	float restoreFoodTime = 10.0f;/// szybkosc odnawiania sie podloza
	float hungerSpan = 2.f; /// co jaki czas spada najedzenie 
	float eatSpeed = 1.f; /// predkosc z jak jedz¹ robaki

	/*Worm*/
	float maxScale = 2.f; /// maksymalny rozmiar jaki moze urosn¹æ robak
	float notMature = 0.1f; /// % zycie gdy robak sie nie rozmanaz
	float maxHungerTime = 1.f; /// maksymalny czas na g³odzie 
	float eggIncubate = 10.f; ///ile jajko bedzie sie wykluwaæ 
	float leyEggSpan = 3.f; /// odstep pomiêdzy mozliwoscia kolejnego jajka
	float maxLifeTime = 120.f; ///maxymalny czas zycia
	

	/*Ground*/

	float maxFood = 100.f; /// max ilosc jedzenia na podlozu


	
};