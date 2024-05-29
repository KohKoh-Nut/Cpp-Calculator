#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Condition.h"
#include <string>

//a class to take the expression
class Expression
{
public:
	Condition MyCondition;

	/* variables */
	//the string for expression
	std::string expression;
	
	//current position of the for-each loop
	int posOfFor{};
	int stringSize{};
	int numOfOptr{}, optrDone{}; //number of operators
	int optr_1{}, optr_2{}, optr_3{}; //position of operators

	//the result evaluated from the expression
	double result{};


	/* others */
	//method to reset the variables
	void reset();
	void resetPOF();

	//method to get input from user
	void input();

	//method to output the result
	void output();

	//method to format the expression
	void format();

	//method to detect error and stop execution
	void error();


	/* store */
	//method to store new expression
	void storeExpression(int optr_bef, int optr_af, std::string num);

	//method to store new expression after processing two consecutive negatives
	void storeExpressionCons(int optr_bef, int optr_af);

	//method to store new expression after processing signs right after * & /
	void storeExpressionConsMultDiv(int optr_bef, int optr_af);

	//method to store string
	std::string storeString(int optr_bef, int optr_af);

	//WIP
	//method take in string and convert it to double
	double doubleConvert(std::string num);


	/* calculate */
	//method to calculate number of operator
	int calNumOfOptr(char optr);

	//method to calculate number of consecutive operator for formatting the expression
	int calNumOfConsOptr();

	//method to calculate number of consecutive operator for formatting the expression
	int calNumOfConsOptrMultDiv();

	//method to calculate the string size of the expression
	int calStringSize();


	/* set and find */
	//method to find the position of operator
	int setAndFind(int POForigin, int actAfterFor, int forMode, int ifmode);

	//method to take in numbers & operator and return an evaluated value
	std::string processOptr(std::string num1, std::string num2);

	//method combined: find operator position & store it to the class variable
	void optrAddSub(int optr_1a, int optr_2a, int mode);


	/* addSubForLoop*/
	//method for the if repeating
	void addSubFor(int optr_1a, int optr_2a, int mode);
	//method for the if repeating
	int formatAddSubFor(int optr_1a, int optr_2a, int mode, int consOptrDone);


	/* evaluate */
	//method to undergo addtion & subtraction
	void addSub();

	//method to undergo multiplication & division
	void multDiv();
};

#endif
