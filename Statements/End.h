#ifndef START_H
#define START_H

#include "Statement.h"

//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class End : public Statement
{
private:
	Connector* Connectors[2];//put the connector in array
	Connector* pOutConn;	//Value Assignment Stat. has one Connector to next statement
	Connector* pInConn;	//Value Assignment Stat. has one Connector to next statement
	//Each statement type in flowchart has a predefined number of (output) connectors
	//For example, conditional statement always has 2 output connectors

	//Note: We don't need to keep track with input connectors
	//      Whenever we want to iterate on all statements of the flowchart
	//      we will begin with start statement then its output connector
	//      then the connector's destination statement and so on (follow the connectors)

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (End) point of the (Output) connector

	Point middletop;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	End(Point middletop);

	void setLHS(const string& L);
	void setRHS(double R);

	virtual void Draw(Output* pOut) const;

	virtual bool IsPointInMe(Point clickedPoint);

	virtual void SetConnectorOut(Connector* cn);
	virtual void SetConnectorIn(Connector* cn);

	virtual Connector** returnConnectors();
	virtual int getConnCnt();

	virtual char returnPointIn(Point& pIn); //retrun the inlit Point
	virtual char returnPointOut(Point& pOut); // Return the Outlet Point location
	virtual bool IsOutletFull(); //Check if the Statment already have Outlet connetor

	~End();
};

#endif