#pragma once
using namespace std;
#include<string>
#include<fstream>
#include "Action.h"
class ApplicationManager; 
class Saveaction : public Action {
public:
	Saveaction(ApplicationManager* pManager);
	bool fileexists(const string filename);
	bool confirmoverwrite()const;
	virtual void ReadActionParameters();
	virtual void Execute();
	//Add rectangle to the ApplicationManager
};