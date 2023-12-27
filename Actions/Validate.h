#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Statements/Statement.h"

class Validate :
	public Action
{
public:
	Validate(ApplicationManager *pAppManager);
	void ReadActionParameters();
	void Execute();
};

