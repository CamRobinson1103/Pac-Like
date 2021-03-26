
#pragma once
#include "Decision.h"

class ABDecision : public Decision
{
public:

	ABDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr);


	//Changes decision depending on what happens 
	virtual void makeDecision(Agent* agent, float deltaTime) override;


	//Checks conditions and returns false
	virtual bool checkCondition(Agent* agent, float deltaTime) { return false; }

private:
	Decision* m_leftChild;
	Decision* m_rightChild;
};
