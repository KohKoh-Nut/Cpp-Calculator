#ifndef COUNT_H
#define COUNT_H

#include "Variables.h"

class Count
{
public:
	Variables MyVariables;

	//method to calculate number of operator
	int calNumOfOptr(char optr);

	//method to calculate number of consecutive operator for formatting the expression
	int calNumOfConsOptr(int j);

	//method to calculate number of brackets without operator right before for formatting
	int calNumOfBracFroOptr();

	//method to calculate number of brackets without operator right after for formatting
	int calNumOfBracBacOptr();

	//method to calculate the string size of the expression
	int calStringSize();
};

#endif