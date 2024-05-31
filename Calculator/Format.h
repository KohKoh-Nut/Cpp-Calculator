#ifndef FORMAT_H
#define FORMAT_H

#include "Variables.h"

//a class to handle the formatting of the expression
class Format
{
public:
	Variables MyVariables;

	//method to format the expression
	void format();

	//method for the if repeating
	int forLoopAddSubFormat(int optr_1a, int optr_2a, int mode, int consOptrDone);
};

#endif