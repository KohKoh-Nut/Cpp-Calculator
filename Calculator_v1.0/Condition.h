#ifndef CONDITION_H
#define CONDITION_H

#include "IOError.h"
#include "Variables.h"
#include <iostream>

//a class to process conditions
class Condition
{
public:
	/*	check the condition for the method to find position of operator
		mode:
		1: Variables::posOfFor <= Variables::stringSize
		2: Variables::posOfFor >= 0	*/
	static bool checkForCondition(int mode);

	/*	check the condition for the method to find position of operator
		mode:
		1: + - * / %	5: (
		2: + -			6: ( )
		3: * / %		7: )
		4: ^			8: e
		9: < >			10: [ ]
		11: [			12: ]
		optr: the operator to be checked*/
	static bool checkIfCondition(int mode,char optr);
};

#endif