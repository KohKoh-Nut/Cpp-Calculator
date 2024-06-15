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
	/*	method to undergo addtion & subtraction
		brac:
		0 = not brackets
		1 = for brackets	*/
	static void doAddSub(int brac);

	/*	method for the if repeating
		optr_1a: current operator
		optr_2a: next operator
		mode:
		0 = 1st loop
		1 = 2nd loop
		brac:
		0 = not brackets
		1 = for brackets	*/
	static void forLoopAddSub(int optr_1a, int optr_2a, int mode, int brac);

	/*	method combined: find operator position & store it to the class variable
		optr_1a: current operator
		optr_2a: next operator
		mode:
		0 = 1st loop
		1 = 2nd loop	*/
	static void optrAddSub(int optr_1a, int optr_2a, int mode);
};

#endif