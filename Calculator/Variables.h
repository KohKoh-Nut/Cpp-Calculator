#ifndef VARIABLES_H
#define VARIABLES_H

#include <string>

class Variables
{
public:
	static int posOfFor; //current position of for loop
	static int stringSize;
	static int numOfOptr, optrDone; //number of operators
	static int optr_1, optr_2, optr_3; //position of operators

	static double result; //the result evaluated from the expression

	static double resultBrac;//the result evaluated from the sub-expression

	static std::string expression;//the string for expression

	//method to reset all variables except result
	static void reset();

	//method to reset current position of for loop
	static void resetPOF();
};

#endif