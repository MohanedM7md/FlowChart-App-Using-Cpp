#ifndef AddConnect_H
#define AddConnect_H
#include "..\Statements\Statement.h"
#include "..\Connector.h"
#include "Action.h"



class AddConnect : public Action
{
private:
	Point pointIn;
	Point pointOut;
public:
	AddConnect(ApplicationManager *pManager);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif