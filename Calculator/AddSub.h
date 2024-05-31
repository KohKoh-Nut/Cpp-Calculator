#ifndef ADDSUB_H
#define ADDSUB_H

#include "Variables.h"

//a class to process addition and subtraction
class AddSub
{
public:
	Variables MyVariables;

	//method to undergo addtion & subtraction
	void doAddSub(int brac);

	//method for the if repeating
	void forLoopAddSub(int optr_1a, int optr_2a, int mode, int brac);

	//method combined: find operator position & store it to the class variable
	void optrAddSub(int optr_1a, int optr_2a, int mode);
};

#endif