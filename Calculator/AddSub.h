#ifndef ADDSUB_H
#define ADDSUB_H

#include "Count.h"
#include "Store.h"
#include "Expression.h"
#include "Variables.h"

//a class to process addition and subtraction
class AddSub
{
public:
	//method to undergo addtion & subtraction
	static void doAddSub(int brac);

	//method for the if repeating
	static void forLoopAddSub(int optr_1a, int optr_2a, int mode, int brac);

	//method combined: find operator position & store it to the class variable
	static void optrAddSub(int optr_1a, int optr_2a, int mode);
};

#endif