#include "Paste.h"

Paste::Paste(ApplicationManager* pManager) :Action(pManager) {}
void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Point to paste.");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
	while (Position.y >= (UI.height - UI.ToolBarHeight) || Position.y <= UI.ToolBarHeight || Position.x >= UI.DrawingAreaWidth) {
		if (Position.y <= 50 && Position.x >= UI.MenuItemWidth * ADD_START && Position.x <= UI.MenuItemWidth * (1 + ADD_START)) //if the user want to cancel he can click on the toolbar
			return;
		Pause(100);//wait before show this mesage to make it not apearing as freezed give more dynamicaly
		pOut->PrintMessage("this region is not allowed put it in drwing area!!");
		pIn->GetPointClicked(Position);
		pOut->ClearStatusBar();
	}
}

void Paste::Execute()
{
	Statement* CopiedState = pManager->GetClipboard();
	Output* pOut = pManager->GetOutput();


	if (!CopiedState)
	{
		pOut->PrintMessage("You didn't select a statement to be copied!");
		return;
	}

	ReadActionParameters();
	int statTyp = CopiedState->GetStatementType();

	//According to ActioType, create the corresponding action object
	switch (statTyp)
	{
	case ITM_COND:
		Condtion* CopiedCondState = dynamic_cast<Condtion*>(CopiedState);
		Condtion* Copied = new Condtion(CopiedCondState, Position);
		pManager->AddStatement(Copied);
		break;
	}
}


