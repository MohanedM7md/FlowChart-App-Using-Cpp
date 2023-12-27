#ifndef Paste_H
#define Paste_H
#include "..\Statements\Statement.h"
#include "..\Statements\Condtion.h"
#include "Action.h"
#include "..\ApplicationManager.h"

//Add Paste Action class

class Paste: public Action
{
private:
	Point Position;
	
public:
	Paste(ApplicationManager* pManager);
	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif