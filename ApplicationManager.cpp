#include "ApplicationManager.h"
#include "Actions\AddValueAssign.h"
#include "Actions\Select.h"
#include "Actions\AddConnect.h"
#include "Actions\Delete.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Actions\Delete.h"
#include "Actions\AddVarAssign.h"
#include "Actions\AddStart.h"
#include "Actions\AddOperatorAssign.h"
#include "Actions\AddEnd.h"
#include <iostream>
#include "Actions/Loadaction.h"
#include "Actions/Saveaction.h"
#include <fstream>
#include<string>
//Constructor
Statement* ApplicationManager::StatementFactory(int statementType) {
	switch (statementType) {
	case ITM_VALUE_ASSIGN:
		return new ValueAssign();
		
	default:
		return nullptr; 
	}
}
bool ApplicationManager::CheckValidation() const {

	if (StatCount == 0) {
		pOut->PrintMessage("It looks like there are no statements at all. !!!!");
		return false;
	}

	int startnum = 0, endnum = 0;
	bool valid = true;

	for (int i = 0; i < StatCount; i++) {
		if (dynamic_cast<Start*>(StatList[i]))
			startnum++;
		else if (dynamic_cast<End*>(StatList[i]))
			endnum++;

		//check the statement to be connected as a source
		if (StatList[i]->IsOutletFull() == NULL && !(dynamic_cast<End*>(StatList[i])) && !(dynamic_cast<Conditional*>(StatList[i]))) {
			valid = false;
			break;
		}
		//check the statement to be connected as a destination
		if (!(StatList[i]->IsOutletFull() && !(dynamic_cast<Start*>(StatList[i]))) {
			valid = false;
			break;
		}
		if (dynamic_cast<Conditional*>(StatList[i])) {
			Conditional* p = (Conditional*)StatList[i];
			if (p->get_NConn() == NULL || p->get_YConn() == NULL) {
				valid = false;
				break;
				if (dynamic_cast<ValueAssign*>(StatList[i])) {
					ValueAssign* pValueAssign = static_cast<ValueAssign*>(StatList[i]);

					// Example: Check if the variable is initialized
					if (!pValueAssign->IsVariableInitialized()) {
						valid = false;
						break;
					}

				}
			}
		}
		if (startnum != 1 || endnum != 1) {
			valid = false;
		}

		if (!valid)
			pOut->PrintMessage("Invalid Chart !! check the statements and again.");
		else
			pOut->PrintMessage("Good Work , The Chart is Valid");

		return valid;

	}
}
void ApplicationManager::LoadStatements(std::ifstream& file) {
	for (int i = 0; i < StatCount; ++i) {
		int statementType;
		file.read(reinterpret_cast<char*>(&statementType), sizeof(int));

		
		Statement* loadedStatement = StatementFactory(statementType);

		if (loadedStatement) {
			loadedStatement->Load(file);
	
			StatList[i] = loadedStatement;  
		}
		else {
			std::cerr << "Unknown statement type: " << statementType << std::endl;
		}

	}
}
void ApplicationManager::LoadConnectors(std::ifstream& file) {
	for (int i = 0; i < StatCount; ++i) {
		
		Connector* loadedConnector = new Connector();
		loadedConnector->Load(file, *StatList, StatCount);

		ConnList[i] = loadedConnector;
	}
}
void ApplicationManager::EmptyAllLists()
{
	for (int i = 0; i < ConnCount; i++)
	{
		delete ConnList[i];
	}
	for (int i = 0; i < StatCount; i++)
	{
		delete StatList[i];
	}
	ConnCount = 0;
	StatCount = 0;
}
void ApplicationManager::Saveall(std::string filename) {
	std::ofstream file(filename, std::ios::binary);

	if (file.is_open()) {
		file.write(reinterpret_cast<const char*>(&StatCount), sizeof(int));
		file.write(reinterpret_cast<const char*>(&ConnCount), sizeof(int));
		for (int i = 0; i < StatCount; ++i) {
			std::cout << "Saving statement " << i << std::endl;
			StatList[i]->Save(file);
		}

		for (int i = 0; i < ConnCount; ++i) {
			std::cout << "Saving connector " << i << std::endl;
			ConnList[i]->Save(file);
		}

		file.close();
		std::cout << "Save successful." << std::endl;
	}
	else {
		std::cout << "Unable to open file: " << filename << std::endl;
	}
}

void ApplicationManager:: Loadall(std::string filename) {
	std::ifstream file(filename, std::ios::binary);
EmptyAllLists();
	if (file.is_open()) {
		file.read(reinterpret_cast<char*>(&StatCount), sizeof(int));
		file.read(reinterpret_cast<char*>(&ConnCount), sizeof(int));
		LoadStatements(file);
		LoadConnectors(file);


		

		file.close();
		std::cout << "Load successful." << std::endl;
	}
	else {
		std::cerr << "Unable to open file: " << filename << std::endl;
	}
}

ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;
	pSelectedConn = NULL;	//no Statement is selected yet

	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_VALUE_ASSIGN:
			pAct = new AddValueAssign(this);
			break;
		case ADD_START:
			pAct = new AddStart(this);
			break;
		case ADD_END:
			pAct = new AddEnd(this);
			break;
		case ADD_VAR_ASSIGN:
			pAct = new AddVarAssign(this);
			break;
		case ADD_OPER_ASSIGN:
			pAct = new AddOperatorAssign(this);
			break;

		case ADD_CONDITION:
			///create AddCondition Action here

			break;
		case DEL:
			pAct = new Delete(this);

			break;
		case ADD_CONNECTOR:
			pAct = new AddConnect(this);
			break;
		case SAVE:
			pAct = new Saveaction(this);
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case LOAD:
			pAct = new Loadaction(this);
			break;
		case EXIT:
			///create Exit Action here
			
			break;
		
		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL
	for (int i = 0; i < StatCount; i++)
		if (StatList[i]->IsPointInMe(P))
			return StatList[i];

	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities

	return NULL;
}
void ApplicationManager::DeleteStatement(Statement* pStat)
{
	int i = 0;
	for (; i < StatCount; i++)
		if (StatList[i] == pStat)
			break;
	delete StatList[i];

	StatList[i] = StatList[StatCount-1];
	StatList[StatCount - 1] = NULL;
	StatCount--;
}
void ApplicationManager::DeleteConn(Connector* pStat)
{
	int i = 0;
	for (; i < ConnCount; i++)
		if (ConnList[i] == pStat)
			break;
	delete ConnList[i];

	ConnList[i] = ConnList[ConnCount - 1];
	ConnList[StatCount - 1] = NULL;
	ConnCount--;
}
void ApplicationManager::AddConnector(Connector* pConn)
{
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
}
Connector* ApplicationManager::GetConnector(Point P) const
{
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i]->IsPointOnMe(P)) {
			return ConnList[i];
		}
	}
	return nullptr;
}
void ApplicationManager::SetSelectedConn(Connector* pStat)
{
	pSelectedConn = pStat;
}
Connector* ApplicationManager::GetSelectedConn() const
{
	return pSelectedConn;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
