#ifndef FORMAT_H
#define FORMAT_H

#include "Count.h"
#include "Store.h"
#include "Condition.h"
#include "AddSub.h"
#include "IOError.h"
#include "Expression.h"
#include "Variables.h"
#include "Constants.h"
#include "Functions.h"
#include <cctype>
#include <string>

//a class to handle the formatting of the expression
class Format
{
public:
	//method to format the expression
	static void format();

	static void formFunc(); //format functions
	static void formConstants(); //format constants
	static void formFroBrac(); //format front brackets
	static void formBacBrac(); //format back brackets
	static void formMultDiv(); //format the signs after * and /
	static void formCons(); //formatting the original expression by processing the consecutive signs
	static void formOrders(); //format the signs after ^

	//method to set the positions of operator for the formatting of brackets
	static void setOptr();

	/*	method for the if repeating
		optr_1a: current operator
		optr_2a: next operator
		mode:
		0 = 1st loop
		1 = 2nd loop	*/
	static int forLoopAddSubFormat(int optr_1a, int optr_2a, int mode, int consOptrDone);

	/*	method for the if repeating
		mode:
		0: multiplication & division
		1: orders	*/
	static void forLoopMultDivOrdersFormat(int ifMode, int mode);

	//method for the if repeating
	static void forLoopConstFormat();

	//method for the if repeating to find back bracket, >
	static void forLoopConstFormatBacBrac();

	//method for the if repeating
	static int forLoopFuncFormat(int funcDone);
};

#endif