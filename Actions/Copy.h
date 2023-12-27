#ifndef Copy_H
#define Copy_H
#include "..\Statements\Statement.h"
#include "Action.h"
#include "..\ApplicationManager.h"

//Add Copy Action class

class Copy: public Action
{
private:
	
public:
	Copy(ApplicationManager* pManager);
	virtual void Execute();
	virtual void ReadActionParameters();
};

#endif