#include "Statement.h"
int Statement::nextid = 0;
Statement::Statement():uniqueid(nextid++)
{ 
	//TODO: set the ID with a unique value
	Text = "";
	Selected = false;		
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

