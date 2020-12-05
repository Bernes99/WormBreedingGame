#include "Eggs.h"

Eggs::Eggs(int positionX, int positionY, float lifeTime)
{
	loadSprite("../Resources/Textures/egg.png");
	setWormPosition(positionX, positionY);
	setEggDeath(lifeTime);
}

void Eggs::setEggDeath(float time)
{
	maxLifeTime = time;
}

bool Eggs::wormDeath()
{
	if (deathTime.getElapsedTime().asSeconds() >= maxLifeTime)
	{
		return true;
	}
	else if (deathTime.getElapsedTime().asSeconds() > maxLifeTime * 0.75f)
	{
		loadSprite("../Resources/Textures/brokenEgg.png");
	}
	return false;
}
