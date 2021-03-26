
#pragma once

class Agent;

// A class for decisions
class Decision
{
public:
	virtual void makeDecision(Agent* agent, float deltaTime) = 0;
};