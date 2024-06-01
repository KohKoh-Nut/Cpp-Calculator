#ifndef COUNT_H
#define COUNT_H

#include "Condition.h"
#include "Variables.h"

class Count
{
public:
	//method to calculate number of operator
	static int calNumOfOptr(char optr);

	//method to calculate number of consecutive operator for formatting the expression
	static int calNumOfConsOptr(int j);

	//method to calculate number of brackets without operator right before for formatting
	static int calNumOfBracFroOptr();

	//method to calculate number of brackets without operator right after for formatting
	static int calNumOfBracBacOptr();

	//method to calculate the string size of the expression
	static int calStringSize();
};

#endif