#include "Loadaction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Loadaction::Loadaction(ApplicationManager* pManager) : Action(pManager) {};

bool Loadaction::fileexists(const string filename) {
    ifstream file(filename);
    return file.good();
}

void Loadaction::ReadActionParameters() {
}

void Loadaction::Execute() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    string filename;

    pOut->PrintMessage("Enter filename to load the flowchart: ");
    filename = pIn->GetString(pOut);

    if (!fileexists(filename)) {
        pOut->PrintMessage("File not found. Load operation canceled.");
        return;
    }

    pManager->Loadall(filename);

    pOut->PrintMessage("Flowchart is loaded from file: " + filename);
}