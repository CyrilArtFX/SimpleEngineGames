#pragma once

class ITurnBasedActor
{
public:
	virtual ~ITurnBasedActor() {}

	virtual void TurnAction() = 0;
};

