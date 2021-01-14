#pragma once
#include "Creature.h"
class Eggs :
    public Creature
{
public:

    /// <summary>
    /// ³aduje obrazek jajka, ustawia pozycje oraz d³ugoœæ wykluwania jajka
    /// </summary>
    /// <param name="positionX"> - pozycja x robaka</param>
    /// <param name="positionY"> - pozycja y robaka</param>
    /// <param name="lifeTime"> - czas wykluwania sie jajka</param>
    Eggs(int positionX,int positionY,float lifeTime);

    /// <summary>
    /// ustawia czas po jakim ma sie wykluæ jajko
    /// </summary>
    /// <param name="time"> - czas w sekundach po jakim wykluje sie jajko</param>
    void setEggDeath(float time);

    /// <summary>
    /// zwraca prawdê jezeli osi¹gnie czas na wklucie oraz podmienia teksture przy 75% tego czasu
    /// </summary>
    /// <returns> zwraca prawde jezeli osi¹gnie czas na wklucie, fa³sz je¿eli nie </returns>
    bool wormDeath();
};

