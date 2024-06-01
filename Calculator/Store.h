#ifndef STORE_H
#define STORE_H

#include "Variables.h"
#include <string>

class Store
{
public:
	//method to store new expression
	static void storeExp(int optr_bef, int optr_af, std::string num);

	//method to store new expression after formatting two consecutive negatives
	static void storeExpCons(int optr_bef, int optr_af);

	//method to store new expression after formatting signs right after * & / & ^
	static void storeExpConsMultDivOrders(int optr_bef, int optr_af, int mode);

	//method to store new expression after formatting brackets without operator right before
	static void storeExpBracOptr(int optr_bef, int optr_af);

	//method to store new expression after formatting consecutive brackets
	static void storeExpConsBracOptr(int optr_bef, int optr_af, int mode);

	//method to store new expression after formatting brackets with orders right before
	static void storeExpBracOrdersOptr(int optr_bef, int optr_af);

	//method to store a sub-expression inside the brackets
	static std::string storeExpBrac(int optr_bef, int optr_af);

	//method to store a result inside the brackets
	static std::string storeExpBracAf(int optr_bef, int optr_af, std::string exp, int stringSizeAf);

	//method to store string
	static std::string storeString(int optr_bef, int optr_af);
};

#endif