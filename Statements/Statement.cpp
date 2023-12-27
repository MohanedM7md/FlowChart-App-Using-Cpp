#include "Statement.h"

Statement::Statement(int Type):StateType(Type)
{ 
	//TODO: set the ID with a unique value
	Text = "";
	Selected = false;		
}

Statement::Statement(Statement* CopiedState, int Type):StateType(Type)
{
	this->Text = CopiedState->GetText();
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

void Statement::SetStatementID(int id)
{
	ID = id;
}

int Statement::GetStatementID()
{
	return ID;
}

int Statement::GetStatementType()
{
	return StateType;
}

string Statement::GetText()
{
	return this->Text;
}

void Statement::SetText(const string& txt)
{
	this->Text = txt;
}
