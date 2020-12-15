#pragma once
#include "Creature.h"
class Eggs :
    public Creature
{
public:
    Eggs(int positionX,int positionY,float lifeTime);
    void setEggDeath(float time);

    bool wormDeath() ;
};

