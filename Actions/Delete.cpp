#include "Delete.h"
#include "AddConnect.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
Delete::Delete(ApplicationManager *pManager):Action(pManager),stat(NULL), slctedConn(NULL)
{}

void Delete::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	

	pOut->PrintMessage("Are you Sure you Want to delet that? Write \"CONFIRM\" to complete \"NO\" to discard");
	Confirmation = pIn->GetString(pOut);
	while (Confirmation != "NO" && Confirmation != "CONFIRM") {
		pOut->PrintMessage("Error!!( " + Confirmation + " ) isn't  \"CONFIRM\" or \"NO\" do it again: ");
			Confirmation = pIn->GetString(pOut);
	}
	pOut->ClearStatusBar();
}

//Execute the action
void Delete::Execute()
{
	ReadActionParameters();
	stat = pManager->GetSelectedStatement();
	slctedConn = pManager->GetSelectedConn();
	if (Confirmation == "NO")
		return;

	if (stat != NULL) {
		Connector** StatConnArr = stat->returnConnectors();
		pManager->SetSelectedStatement(NULL);
		for (int i = 0; i < stat->getConnCnt(); i++) {
			if (StatConnArr[i] != NULL) { //Checks if the Statment connected to anny Statment
				StatConnArr[i]->getSrcStat()->SetConnectorOut(NULL);//makes the src free of connectors
				pManager->DeleteConn(StatConnArr[i]); //delete the connected connectors "no free conn remeber?"
			}
		}
		pManager->DeleteStatement(stat); //delete the Statement
	}
	else {
		pManager->SetSelectedConn(NULL);
		slctedConn->getSrcStat()->SetConnectorOut(NULL); //makes the src free of connectors
		pManager->DeleteConn(slctedConn); //delete the connecter
	}
	stat = NULL;
	slctedConn = NULL;
}
