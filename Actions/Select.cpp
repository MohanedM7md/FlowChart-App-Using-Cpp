#include "Select.h"
#include "AddConnect.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager *pManager):Action(pManager){}

void Select::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click to on the statement you want to select");
	pIn->GetPointClicked(Postion);
	pOut->ClearStatusBar();
}

//Execute the action
void Select::Execute() 
{
	ReadActionParameters();

	Statement* oldstat = pManager->GetSelectedStatement();
	Statement* newstat = pManager->GetStatement(Postion);

	Connector* oldconn = pManager->GetSelectedConn();
	Connector* newconn = pManager->GetConnector(Postion);

	
	if (newstat == NULL && newconn == NULL) { //Checks if the user didn't select any of connector
		pManager->GetOutput()->PrintMessage("You didn't select any Statment of connector");//or Statment to print this message
		return;
	}

	if (oldstat != NULL) { //this sets the old Statment to Null and make the selcted 
		oldstat->SetSelected(false);// member in AppManager to NULL
		pManager->SetSelectedStatement(NULL);
	}
	if (oldconn != NULL) {//Same as the above but for connector
		oldconn->SetSelected(false);
		pManager->SetSelectedConn(false);
	}
	
	if (newstat != NULL) {
		if (newstat == oldstat)//if the user clicked on the same Statment then return
			return;//we don't need to make make it selected again after unselect it

		pManager->SetSelectedStatement(newstat);
		newstat->SetSelected(true);//else if it another one then select it 
	}
	else {
		if (newconn == oldconn)//the same for connector
			return;

		pManager->SetSelectedConn(newconn);
		newconn->SetSelected(true);
	}
}
