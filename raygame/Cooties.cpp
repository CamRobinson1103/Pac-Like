#include "Cooties.h"
#include "Ghost.h"

void Cooties::makeDecision(Agent* agent, float deltaTime)
{
	ABDecision::makeDecision(agent, deltaTime);
}

bool Cooties::checkCondition(Agent* agent, float deltaTime)
{
	Ghost* ghost = dynamic_cast<Ghost*>(agent);
	if (ghost->checkCollision(ghost->getTarget()))
	{
		if (ghost->getgotCooties())
		{
			ghost->setgotCooties(false);
			return false;
		}
		else if (!ghost->getgotCooties())
		{
			ghost->setgotCooties(true);
			return true;
		}
	}
	return false;
}
