#pragma once
#include "ABDecision.h"

class Cooties : public ABDecision
{
public:
	using ABDecision::ABDecision;

	//Decides the decision
	void makeDecision(Agent* agent, float deltaTime) override;

	bool checkCondition(Agent* agent, float deltaTime) override;
};

