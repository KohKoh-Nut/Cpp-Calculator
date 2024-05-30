#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "IOError.h"
#include "Condition.h"
#include <string>

//a class to take the expression
class Expression
{
private:
	/* variables */
	//current position of the for-each loop
	int posOfFor{};
	int stringSize{};
	int numOfOptr{}, optrDone{}; //number of operators
	int optr_1{}, optr_2{}, optr_3{}; //position of operators

	//the result evaluated from the expression
	double result{};

	//the result evaluated from the sub-expression
	double resultBrac{};

public:
	Condition MyCondition;
	IOError MyIOError;

	//the string for expression
	std::string expression;


	/* others */
	//method to reset the variables
	void reset();
	void resetPOF();

	//method to format the expression
	void format();

	//method combined: input, evaluate and output
	void evaluate();


	/* store */
	//method to store new expression
	void storeExp(int optr_bef, int optr_af, std::string num);

	//method to store new expression after formatting two consecutive negatives
	void storeExpCons(int optr_bef, int optr_af);

	//method to store new expression after formatting signs right after * & / & ^
	void storeExpConsMultDivOrders(int optr_bef, int optr_af, int mode);

	//method to store new expression after formatting brackets without operator right before
	void storeExpBracOptr(int optr_bef, int optr_af);

	//method to store a sub-expression inside the brackets
	std::string storeExpBrac(int optr_bef, int optr_af);

	//method to store a result inside the brackets
	std::string storeExpBracAf(int optr_bef, int optr_af, std::string exp, int stringSizeAf);

	//method to store string
	std::string storeString(int optr_bef, int optr_af);


	/* calculate */
	//method to calculate number of operator
	int calNumOfOptr(char optr);

	//method to calculate number of consecutive operator for formatting the expression
	int calNumOfConsOptr(int j);

	//method to calculate number of brackets without operator right before for formatting
	int calNumOfBracOptr();

	//method to calculate the string size of the expression
	int calStringSize();


	/* set and find */
	//method to find the position of operator
	int setAndFind(int POForigin, int actAfterFor, int forMode, int ifmode);

	//method to take in numbers & operator and return an evaluated value
	std::string processOptr(std::string num1, std::string num2);

	//method combined: find operator position & store it to the class variable
	void optrAddSub(int optr_1a, int optr_2a, int mode);


	/* addSubForLoop */
	//method for the if repeating
	void forLoopAddSub(int optr_1a, int optr_2a, int mode, int brac);

	//method for the if repeating
	int forLoopAddSubFormat(int optr_1a, int optr_2a, int mode, int consOptrDone);


	/* evaluate */
	//method to undergo addtion & subtraction
	void addSub(int brac);

	//method to undergo multiplication & division
	void multDiv();

	//method to process orders 
	void orders();

	void brackets();
};

#endif
