#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Actions\AddValueAssign.h"
#include "Actions\Select.h"
#include "Actions\AddConnect.h"
#include "Actions\Delete.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Actions/Loadaction.h"
#include "Actions/Saveaction.h"
#include <fstream>
#include <string>
#include "DEFS.h"
#define MaxCount 200
class ApplicationManager {
private:
    Output* pOut;
    Input* pIn;


    int StatCount;
    int ConnCount;

    Statement* pSelectedStat;
    Connector* pSelectedConn;
    Statement* pClipboard;

    // Private member functions
    Statement* StatementFactory(int statementType);
    void LoadStatements(std::ifstream& file);
    void EmptyAllLists();
    void LoadConnectors(std::ifstream& file);

public:
    Statement* StatList[MaxCount];
    Connector* ConnList[MaxCount];
    // Constructor
    ApplicationManager();

    // Destructor
    ~ApplicationManager();

    // Actions Related Functions
    ActionType GetUserAction() const;
    void ExecuteAction(ActionType ActType);

    // Statements Management Functions
    void AddStatement(Statement* pStat);
    Statement* GetStatement(Point P) const;
    void DeleteStatement(Statement* pStat);
    void DeleteConn(Connector* pStat);
    void AddConnector(Connector* pConn);
    Connector* GetConnector(Point P) const;
    void SetSelectedConn(Connector* pStat);
    Connector* GetSelectedConn() const;
    Statement* GetSelectedStatement() const;
    void SetSelectedStatement(Statement* pStat);
    Statement* GetClipboard() const;
    void SetClipboard(Statement* pStat);

    // Interface Management Functions
    void UpdateInterface() const;
    Input* GetInput() const;
    Output* GetOutput() const;
    bool ApplicationManager::CheckValidation() const;
    // Save and Load
    void Saveall(std::string filename);
    void Loadall(std::string filename);
};

#endif // APPLICATION_MANAGER_H
