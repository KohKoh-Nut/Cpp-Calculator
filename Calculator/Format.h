#ifndef FORMAT_H
#define FORMAT_H

#include "Count.h"
#include "Store.h"
#include "Condition.h"
#include "AddSub.h"
#include "IOError.h"
#include "Expression.h"
#include "Variables.h"

//a class to handle the formatting of the expression
class Format
{
public:
	//method to format the expression
	static void format();

	static void formFroBrac(); //format front brackets
	static void formBacBrac(); //format back brackets
	static void formMultDiv(); //format the signs after * and /
	static void formCons(); //formatting the original expression by processing the consecutive signs
	static void formOrders(); //format the signs after ^

	//method to set the positions of operator for the formatting of brackets
	static void setOptr();

	//method for the if repeating
	static int forLoopAddSubFormat(int optr_1a, int optr_2a, int mode, int consOptrDone);

	static void forLoopMultDivOrdersFormat(int ifMode, int mode);
};

#endif