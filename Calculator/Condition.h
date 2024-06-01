#ifndef CONDITION_H
#define CONDITION_H

#include "IOError.h"
#include "Variables.h"
#include <iostream>

//a class to process conditions
class Condition
{
public:
	//check the condition for the method to find position of operator
	static bool checkForCondition(int i);
	static bool checkIfCondition(int i,char j);
};

#endif