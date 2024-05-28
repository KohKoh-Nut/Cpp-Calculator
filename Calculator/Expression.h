#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Condition.h"
#include <string>

//a class to take the expression
class Expression
{
public:
	Condition MyCondition;

	//the string for expression
	std::string expression;

	//the result evaluated from the expression
	int result{};

	//method to get input from user
	void getInput();

	//method to store new expression
	void storeExpression(int optr_bef, int optr_af, int stringSize, std::string num);

	//method to store new expression after processing two consecutive negatives
	void storeExpressionNeg(int optr_bef, int optr_af, int stringSize);

	//method to store string
	std::string storeString(int optr_bef, int optr_af, int stringSize);

	//method to calculate number of operator
	int calNumOfOptr(char optr);

	//method to calculate number of consecutive operator for formatting the expression
	int calNumOfConsOptr();

	//method to calculate the string size of the expression
	int calStringSize();

	//method to find the position of operator
	int findPosOfOptr(int POForigin, int actAfterFor, int forMode, int ifmode);
	void setMyCondition(int posOfFor, int stringSize);
	int setAndFind(int posOfFor, int stringSize, int POForigin, int actAfterFor, int forMode, int ifmode)
	{
		setMyCondition(posOfFor, stringSize);
		return findPosOfOptr(POForigin, actAfterFor, forMode, ifmode);
	}

	//method to undergo addtion & subtraction
	void addSub();

	//method to undergo multiplication & division
	void multDiv();
};

#endif
