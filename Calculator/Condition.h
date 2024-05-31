#ifndef CONDITION_H
#define CONDITION_H

#include "Variables.h"

//a class to process conditions
class Condition
{
public:
	Variables MyVariables;

	//check the condition for the method to find position of operator
	bool checkForCondition(int i);
	bool checkIfCondition(int i,char j);
};

#endif