#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"
#include "..\Connector.h"
//class Output;
#include "..\GUI\Output.h"

//Base class for all Statements
class Statement
{
protected:
	int ID;			//Each Statement has an ID --> must be unique
	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;	//true if the statement is selected on the folwchart
	int connectedCnt;
	const int StateType;

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement(int Type);
	Statement(Statement* CopiedState,int Type);
	void SetSelected(bool s);
	bool IsSelected() const;

	void SetStatementID(int id);
	int GetStatementID();

	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	
	virtual bool IsPointInMe(Point clickedPoint) = 0; //this function checks if the entered point is in it's area

	virtual void SetConnectorOut(Connector* cn) = 0;
	virtual void SetConnectorIn(Connector* cn) = 0;

	virtual Connector** returnConnectors() = 0;
	virtual int getConnCnt()= 0;
	
	virtual char returnPointIn(Point &pIn) = 0;//retrun the inlit Point
	virtual char returnPointOut(Point& pOut) = 0; // Return the Outlet Point location
	
	virtual bool IsOutletFull() = 0; //Add connector to the Statment

	int GetStatementType();
	string GetText();
	void SetText(const string &txt);
	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type

	//virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file

	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void Simulate();	//Execute the statement in the simulation mode

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file


	///TODO: Add more functions if needed

};

#endif