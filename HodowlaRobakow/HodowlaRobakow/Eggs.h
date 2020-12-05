#pragma once
#include "Worm.h"
class Eggs :
    public Worm
{

public:
    Eggs(int positionX,int positionY,float lifeTime);
    void setEggDeath(float time);

    bool wormDeath() override;
};

