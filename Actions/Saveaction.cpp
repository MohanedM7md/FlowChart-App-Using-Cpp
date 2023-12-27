#include "Saveaction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

Saveaction::Saveaction(ApplicationManager* pManager) : Action(pManager) {};

bool Saveaction::fileexists(const string filename) {
    ifstream file(filename);
    return file.good();
}

bool Saveaction::confirmoverwrite() const {
    string input;
    Output* pOut = pManager->GetOutput();
    Input* pIn =  pManager->GetInput();

    while (true) {
        pOut->PrintMessage("File already exists, do you want to overwrite it? Enter (Yes/No): ");
        input = pIn->GetString(pOut);
        if (input == "yes" || input == "Yes" || input == "No" || input == "no")
            break;
    }
    return (input == "Yes" || input == "yes");
}
void  Saveaction::ReadActionParameters(){
}
void Saveaction::Execute() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    string filename;

    pOut->PrintMessage("Enter filename to save the flowchart: ");
    filename = pIn->GetString(pOut);    

    if (fileexists(filename)) {
        if (!confirmoverwrite())
            pOut->PrintMessage("Save operation canceled");
    }
   
        pManager->Saveall(filename);
  
        pOut->PrintMessage("Flowchart is saved to file: " + filename);
    }

