#pragma once
using namespace std;
#include<string>
#include<fstream>
#include "Action.h"
class ApplicationManager;
class Loadaction : public Action {
public:
	Loadaction(ApplicationManager* pManager);
	bool fileexists(const string filename);
	virtual void Execute();
	 void ReadActionParameters();
};