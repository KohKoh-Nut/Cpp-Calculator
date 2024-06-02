#ifndef STORE_H
#define STORE_H

#include "Expression.h"
#include "Variables.h"
#include <iomanip>
#include <sstream>
#include <string>

class Store
{
public:
	//method to store new expression
	static void storeExp(int optr_bef, int optr_af, std::string num);

	//method to store new expression after formatting two consecutive negatives
	static void storeExpFormConsNegatives(int optr_bef, int optr_af);

	/*	method to store new expression after formatting signs right after * & / & ^
		mode:
		0: multiplication and division
		1: orders	*/
	static void storeExpFormConsMultDivOrders(int optr_bef, int optr_af, int mode);

	/*	method to store new expression after formatting brackets
		mode:
		-1 = nothing
		0 = brackets without operators
		1 = consecutive front brackets
		2 = consecutive back brackets	*/
	static void storeExpFormBrac(int optr_bef, int optr_af,int mode);

	//method to store a sub-expression inside the brackets
	static std::string storeSubExpBrac(int optr_bef, int optr_af);

	//method to store a result inside the brackets
	static std::string storeSubExpBracResult(int optr_bef, int optr_af, std::string exp, int stringSizeAf);

	//method to store multiple strings and evaluate
	static void storeEvaStrings();

	//method to store string
	static std::string storeString(int optr_bef, int optr_af);

	/*	method to store result
		result: variable to store to
		optr: the operator + or - 
		num: the number to be stored	*/
	static double storeResult(double result, char optr, std::string num);
};

#endif