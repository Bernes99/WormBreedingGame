#pragma once
#include "Creature.h"
class Eggs :
    public Creature
{
public:

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

