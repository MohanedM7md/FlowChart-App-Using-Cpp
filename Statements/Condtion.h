#ifndef CONDTION_H
#define CONDTION_H

#include "Statement.h"

//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class Condtion : public Statement
{
private:
	struct pOutConn {
	public:
		Connector* pOutConn;
		string YesNo;
	};
	Point WhichConnectorOut;

	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside (Value)
	string CompOperator;	//Right Handside (Value)

	Connector* Connectors[3];//put the connector in array


	pOutConn R;
	pOutConn L;
	
	//Connector *pOutConn1;	//Value Assignment Stat. has one Connector to next statement
	//Connector *pOutConn2;	//Value Assignment Stat. has one Connector to next statement
	Connector *pInConn;	//Value Assignment Stat. has one Connector to next statement
	                        //Each statement type in flowchart has a predefined number of (output) connectors
	                        //For example, conditional statement always has 2 output connectors


	Point Inlet;	//A point where connections enters this statement 
	                //It's used as the (End) point of the (Input) connectors
	Point OutletR;	//A point a connection leaves this statement
	Point OutletL;	//A point a connection leaves this statement
	                //It's used as the (Start) point of the (Output) connector
	Point TopVertix;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	
public:
	Condtion(Point TVertix, string LeftHS, string Oper, string RightHS);
	Condtion(const Condtion *Cond, Point TVertix);
	
	void setLHS(const string &L);
	void setCompOper(const string &Oper);
	void setRHS(const string &R);

	virtual void Draw(Output* pOut) const;

	virtual bool IsPointInMe(Point clickedPoint);

	virtual void SetConnectorOut(Connector* cn);
	virtual void SetConnectorIn(Connector* cn);

	virtual Connector** returnConnectors();
	virtual int getConnCnt();

	virtual char returnPointIn(Point& pIn); //retrun the inlit Point
	virtual char returnPointOut(Point& pOut); // Return the Outlet Point location
	virtual bool IsOutletFull(); //Check if the Statment already have Outlet connetor

	~Condtion();
};

#endif