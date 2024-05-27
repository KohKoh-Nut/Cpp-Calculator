#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

//a class to take the expression
class Expression
{
public:
	//the string for expression
	std::string expression;

	//the result evaluated from the expression
	int result{};

	//method to get input from user
	void getInput();

	//method to undergo addtion & subtraction
	void additionSubtraction();

};

#endif
