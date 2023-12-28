#ifndef ADD_END_H
#define ADD_END_H

#include "Action.h"
#include "..\Statements\End.h"

//Add End Statement Action

class AddEnd : public Action
{
private:


	Point Position;	//Position where the user clicks to add the stat.

public:
	AddEnd(ApplicationManager* pAppManager);

	//Read END statements position
	virtual void ReadActionParameters();

	//Create and add an END statement to the list of statements
	virtual void Execute();

};

#endif