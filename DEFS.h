#ifndef DEFS_H
#define DEFS_H

//This file contains some global constants and definitions to be used in the project.
//This file contains some global constants and definitions to be used in the project

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

// TODO: Add any action type here
enum ActionType // The actions supported
{
	ADD_START, //Add start statement
	ADD_END,   //Add end statement
	ADD_VALUE_ASSIGN, //Add value assignment statement
	ADD_VAR_ASSIGN,	  //Add variable assignment statement
	ADD_OPER_ASSIGN,  //Add operator assignment statement
	ADD_CONDITION,    //Add a conditional statement (for if and while-loop statements)
	ADD_READ,  //Add read statement
	ADD_WRITE, //Addd write statemetn

	ADD_CONNECTOR, //Add a connector between two statements

	SELECT,		//Select a statement, a connector
	EDIT_STAT,	//Edit a statement

	DEL,   //Delete a figure
	COPY,  //Copy a figure
	CUT,   //Cut a figure
	PASTE, //Paste a figure

	SAVE,		//Save the whole graph to a file
	LOAD,		//Load a graph from a file

	SWITCH_DSN_MODE,	//Switch to Design mode
	SWITCH_SIM_MODE,	//Switch to simulatiom mode

	EXIT,		//Exit the application


	//TODO: ADD THE ACTIONS OF SIMULATION MODE

	RUN,
	VALIDATE,
	DRAWING_AREA,  //A click on the drawing area
	OUTPUT_AREA,   //A click on the output area
	DSN_TOOL,
	SIM_TOOL,//A click on an empty place in the design tool bar
	STATUS 		   //A click on the status bar
};

// TODO: you should add more items
enum DesignMenuItem //The items of the design menu --> THE ORDER MATTERS
{
	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too
	ITM_START,            // ActionType: ADD_START
	ITM_END,            // ActionType: ADD_END
	ITM_VALUE_ASSIGN,     // ActionType: ADD_VALUE_ASSIGN
	ITM_VAR_ASSIGN,       // ActionType: ADD_VAR_ASSIGN
	ITM_OPER_ASSIGN,      // ActionType: ADD_OPER_ASSIGN
	ITM_COND,             // ActionType: ADD_CONDITION
	ITM_READ,             // ActionType: ADD_READ
	ITM_WRITE,            // ActionType: ADD_WRITE
	ITM_CONNECTOR,        // ActionType: ADD_CONNECTOR
	ITM_SELECT,		//Select a statement, a connector
	ITM_EDIT_STAT,	//Edit a statement
	ITM_DEL,   //Delete a figure
	ITM_COPY,  //Copy a figure
	ITM_CUT,   //Cut a figure
	ITM_PASTE, //Paste a figure
	ITM_SAVE,		//Save the whole graph to a file
	ITM_LOAD,		//Load a graph from a file
	ITM_SWITCH_SM,
	ITM_EXIT,             // ActionType: EXIT

	// Add more items if needed

	DSN_ITM_CNT           // Number of design menu items
};

// TODO: you should add more items if needed
enum SimMenuItem //The items of the simulation menu
{
	//Note: Items are ordered here as they appear in menu
	ITM_VALIDATE,	//Validate
	ITM_RUN,	    //Run
	ITM_SWITCH_DS,
	ITM_EXIT1,
	//TODO:Add more items names here

	SIM_ITM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};



#ifndef NULL
#define NULL 0
#endif

#endif