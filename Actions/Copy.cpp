#include "Copy.h"

Copy::Copy(ApplicationManager* pManager) :Action(pManager) {};
void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();


	Statement* SelectedStatetment = pManager->GetSelectedStatement();
	if (SelectedStatetment == NULL)
	{
		pOut->PrintMessage("You didn't select a statement to be copied!");
		return;
	}

	pManager->SetClipboard(SelectedStatetment);
	pOut->PrintMessage("You selected a statement to be copied!");
}

void Copy::ReadActionParameters()
{
}
