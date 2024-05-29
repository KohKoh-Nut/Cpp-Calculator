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
	
	//current position of the for-each loop
	int posOfFor{};
	int stringSize{};
	int numOfOptr{}, optrDone{}; //number of operators
	int optr_1{}, optr_2{}, optr_3{}; //position of operators

	//the result evaluated from the expression
	double result{};

	//method to reset the variables
	void reset();

	//method to get input from user
	void getInput();

	//method to store new expression
	void storeExpression(int optr_bef, int optr_af, std::string num);

	//method to store new expression after processing two consecutive negatives
	void storeExpressionNeg(int optr_bef, int optr_af);

	//method to store string
	std::string storeString(int optr_bef, int optr_af);

	//WIP
	//method take in string and convert it to double
	double doubleConvert(std::string num);

	//method to calculate number of operator
	int calNumOfOptr(char optr);

	//method to calculate number of consecutive operator for formatting the expression
	int calNumOfConsOptr();

	//method to calculate the string size of the expression
	int calStringSize();

	//method to find the position of operator
	int findPosOfOptr(int POForigin, int actAfterFor, int forMode, int ifmode);
	void setMyCondition();
	int setAndFind(int POForigin, int actAfterFor, int forMode, int ifmode);

	//method to take in numbers & operator and return an evaluated value
	std::string processOptr(std::string num1, std::string num2);

	//method to undergo addtion & subtraction
	void addSub();

	//method to undergo multiplication & division
	void multDiv();
};

#endif
