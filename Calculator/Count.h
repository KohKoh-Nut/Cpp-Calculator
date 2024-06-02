#ifndef COUNT_H
#define COUNT_H

#include "Condition.h"
#include "Variables.h"

class Count
{
public:
	//method to calculate number of operator
	static int calNumOfOptr(char optr);

	//method to calculate number of consecutive operators for formatting the expression
	static int calNumOfConsOptr(int j);

	//method to calculate number of front brackets without operator right before for formatting
	static int calNumOfBracFroOptr();

	//method to calculate number of back brackets without operator right after for formatting
	static int calNumOfBracBacOptr();

	//prevent the detection of back brackets being the first character of the string
	static int bacBracFirst(int j);

	//method to calculate the string size of the expression
	static void calStringSize();
};

#endif