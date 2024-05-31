#ifndef STORE_H
#define STORE_H

#include "Variables.h"
#include <string>

class Store
{
public:
	Variables MyVariables;

	//method to store new expression
	void storeExp(int optr_bef, int optr_af, std::string num);

	//method to store new expression after formatting two consecutive negatives
	void storeExpCons(int optr_bef, int optr_af);

	//method to store new expression after formatting signs right after * & / & ^
	void storeExpConsMultDivOrders(int optr_bef, int optr_af, int mode);

	//method to store new expression after formatting brackets without operator right before
	void storeExpBracOptr(int optr_bef, int optr_af);

	//method to store new expression after formatting consecutive brackets
	void storeExpConsBracOptr(int optr_bef, int optr_af, int mode);

	//method to store a sub-expression inside the brackets
	std::string storeExpBrac(int optr_bef, int optr_af);

	//method to store a result inside the brackets
	std::string storeExpBracAf(int optr_bef, int optr_af, std::string exp, int stringSizeAf);

	//method to store string
	std::string storeString(int optr_bef, int optr_af);
};

#endif