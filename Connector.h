#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "GUI\UI_Info.h"
#include "GUI\output.h"
class Statement;
class ApplicationManager;
class Connector	//a connector that connects two statements (Source & Destination)
{
private:
	Statement *SrcStat;	//The source statement of the connector
	Statement *DstStat;	//The destination statement of the connector
	Point Start;	//Start point of the connector
	Point End;		//End point of the connector
	bool Selected;
	char arrowDir;
public:
	Connector(Statement* Src, Statement* Dst,Point start,Point end,char arrowDir);
	Connector();
	void		setSrcStat(Statement *Src);
	Statement*	getSrcStat();	
	void		setDstStat(Statement *Dst);
	Statement*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();
	void Save(ofstream& file);
	void Load(std::ifstream& file, Statement* statList, int statListSize);

	void setEndPoint(Point P);
	Point getEndPoint();

	void Draw(Output* pOut) const;

	bool IsPointOnMe(Point p);
	
	void SetSelected(bool s);
	bool IsSelected() const;
};

#endif