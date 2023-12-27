#include "ValueAssign.h"
#include <sstream>
#include <fstream>
#include "..\ApplicationManager.h"
#include <string>
using namespace std;

ValueAssign::ValueAssign(Point Lcorner, string LeftHS , double RightHS ) :pOutConn(NULL)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	RHS = RightHS;
	for (int i = 0; i < 2; i++) {
		Connectors[i] = NULL;
	}
	connectedCnt = 2;
	UpdateStatementText();

	LeftCorner = Lcorner;
	//No connectors yet

	Inlet[0].x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet[0].y = LeftCorner.y;

	Inlet[1].x = LeftCorner.x;
	Inlet[1].y = LeftCorner.y + UI.ASSGN_HI / 2;
	
	Inlet[2].x = LeftCorner.x + UI.ASSGN_WDTH;
	Inlet[2].y = LeftCorner.y + UI.ASSGN_HI / 2;

	Outlet.x = Inlet[0].x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
	 // Adjust this based on how your code is structured

}
ValueAssign::ValueAssign() : pOutConn(NULL), LHS(""), RHS(0.0) {
	for (int i = 0; i < 2; i++) {
		Connectors[i] = NULL;
	}
	connectedCnt = 2;
	UpdateStatementText();

	// Initialize other members with default values
	LeftCorner = Point(0, 0);

	Inlet[0] = Point(0, 0);
	Inlet[1] = Point(0, 0);
	Inlet[2] = Point(0, 0);

	Outlet = Point(0, 0);
}

void ValueAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void ValueAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}


void ValueAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

bool ValueAssign::IsPointInMe(Point clickedPoint)
{
	//if the point in the area of the assign return true
	return (LeftCorner.x <= clickedPoint.x && LeftCorner.y <= clickedPoint.y &&
		clickedPoint.x <= LeftCorner.x + UI.ASSGN_WDTH &&
		clickedPoint.y <= LeftCorner.y + UI.ASSGN_HI);
}
void ValueAssign::SetConnectorIn(Connector* cn)
{
	pInConn = cn;
	Connectors[0] = pInConn;
}

Connector** ValueAssign::returnConnectors()
{
	return Connectors;
}
int ValueAssign::getConnCnt()
{
	return this->connectedCnt;
}


void ValueAssign::SetConnectorOut(Connector* cn)
{
	pOutConn = cn;
	Connectors[1] = pOutConn;
}

char ValueAssign::returnPointIn(Point& pIn)
{
	Point Nearest;
	Nearest.x = Inlet[0].x;
	Nearest.y = Inlet[0].y;
	if (pIn.y > Nearest.y)
		if (abs(pIn.x - Inlet[2].x) < abs(pIn.x - Inlet[1].x)) {
			pIn = Inlet[2];
			return 'L';
		}
		else {
			pIn = Inlet[1];
			return 'R';
		}
	pIn.x = Inlet[0].x;
	pIn.y = Inlet[0].y;
	return 'U';
}

void ValueAssign::returnPointOut(Point& pOut)
{
	pOut = Outlet;
}
bool ValueAssign::IsOutletFull()
{
	return pOutConn != NULL;
}
ValueAssign::~ValueAssign()
{
		
}
//This function should be called when LHS or RHS changes
void ValueAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<LHS<<" = "<<RHS;	
	Text = T.str();	 
}