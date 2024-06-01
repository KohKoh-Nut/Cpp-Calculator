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

	//method for the if repeating
	static int forLoopAddSubFormat(int optr_1a, int optr_2a, int mode, int consOptrDone);
};

#endif