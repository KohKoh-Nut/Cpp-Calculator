#ifndef CONDITION_H
#define CONDITION_H

#include "IOError.h"

//a class to process conditions
class Condition
{
public:
	IOError MyIOError;

	int posOfFor{};
	int stringSize{};

	//check the condition for the method to find position of operator
	bool checkForCondition(int i);
	bool checkIfCondition(int i,char j);
};

#endif