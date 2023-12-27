#include "AddValueAssign.h"
#include "Loadaction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>
#include "..\ApplicationManager.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddValueAssign::AddValueAssign(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddValueAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	//Read the (Position) parameter
	pOut->PrintMessage("Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();		

	//TODO: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Please Enter Variable Name then press Enter: ");
	LHS = pIn->GetVariable(pOut);
	pOut->PrintMessage("Please Enter the "+ LHS + " Value then press Enter : ");
	RHS = pIn->GetValue(pOut);
	//TODO: Ask the user in the status bar to enter the RHS and set the data member

	//Note: You should validate the LHS to be variable name and RHS to be a value
	//      Call the appropriate functions for this.
}
void ValueAssign::Save(std::ofstream& outputfile) {
	// Save the size of the LHS string
	int statementType = ITM_VALUE_ASSIGN;
	outputfile.write(reinterpret_cast<const char*>(&statementType), sizeof(int));
	outputfile.write(reinterpret_cast<const char*>(&LeftCorner), sizeof(Point));
	size_t Lsize = LHS.size();
	outputfile.write(reinterpret_cast<const char*>(&Lsize), sizeof(size_t));


	outputfile.write(LHS.c_str(), Lsize);

	outputfile.write(reinterpret_cast<const char*>(&RHS), sizeof(double));
}
	void ValueAssign::Load(std::ifstream& file) {

	// Read the position (coordinates) of the statement
		// Read the position (coordinates) of the statement
		file.read(reinterpret_cast<char*>(&LeftCorner), sizeof(Point));

		// Read the size of the LHS string
		size_t Lsize;
		file.read(reinterpret_cast<char*>(&Lsize), sizeof(size_t));

		// Validate Lsize to ensure it's within a reasonable range
		const size_t MAX_ALLOWED_SIZE = 1000;  // Adjust as needed

		if (Lsize <= MAX_ALLOWED_SIZE) {
			char* buffer = new char[Lsize];
			file.read(buffer, Lsize);
			LHS.assign(buffer, Lsize);
			delete[] buffer;
		}
		else {
			
			// Handle the error (skip or abort loading, etc.)
		}

		// Read the RHS value
		file.read(reinterpret_cast<char*>(&RHS), sizeof(double));

	
		ValueAssign::UpdateStatementText();
	
}
void AddValueAssign::Execute()
{
	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH/2;
	Corner.y = Position.y ;

	ValueAssign *pAssign = new ValueAssign(Corner, LHS, RHS);

	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}

