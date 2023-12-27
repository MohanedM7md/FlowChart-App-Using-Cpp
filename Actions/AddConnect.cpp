#include "AddConnect.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddConnect::AddConnect(ApplicationManager *pManager):Action(pManager){}

void AddConnect::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on the start Point");
	pIn->GetPointClicked(pointOut);
	while (pManager->GetStatement(pointOut) == NULL) {
		pOut->PrintMessage("Error you have to choose a statment try again.");
		pIn->GetPointClicked(pointOut);
	}
	pOut->PrintMessage("Click on the End Point");
	pIn->GetPointClicked(pointIn);
	pOut->ClearStatusBar();
	while (pManager->GetStatement(pointIn) == NULL) {
		pOut->PrintMessage("Error you have to choose a statment try again.");
		pIn->GetPointClicked(pointIn);
		pOut->ClearStatusBar();
	}
}

//Execute the action
void AddConnect::Execute()
{
	ReadActionParameters();
	Statement* Stout = pManager->GetStatement(pointOut);

	if (Stout->IsOutletFull()){
		pManager->GetOutput()->PrintMessage("Error!! this Statment Already \
			Have outlet connector.");//checks
		return;																			//if the Statment not already have outlet
	}
	Statement* Stin = pManager->GetStatement(pointIn);
	Point pout;
	Stout->returnPointOut(pout);
	Point pin = pout;
	char arrowDir = Stin->returnPointIn(pin);
	
	Connector* Cadd = new Connector(Stout, Stin, pout, pin, arrowDir);
	pManager->AddConnector(Cadd);
	Stout->SetConnectorOut(Cadd);
	Stin->SetConnectorIn(Cadd);
}
