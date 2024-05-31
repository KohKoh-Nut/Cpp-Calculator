#include "Store.h"
#include "Variables.h"

void Store::storeExp(int optr_bef, int optr_af, std::string num)
{
	//string to store the new expression after evaluation
	std::string expMultDiv;

	//the process of storing the new expression
	for (MyVariables.posOfFor = 0; MyVariables.posOfFor <= optr_bef; MyVariables.posOfFor++)
		expMultDiv += MyVariables.expression[MyVariables.posOfFor];

	expMultDiv += num;

	for (MyVariables.posOfFor = optr_af; MyVariables.posOfFor <= MyVariables.stringSize; MyVariables.posOfFor++)
		expMultDiv += MyVariables.expression[MyVariables.posOfFor];

	//putting the new expression back to expression for further evaluation
	MyVariables.expression = expMultDiv;
}

void Store::storeExpCons(int optr_bef, int optr_af)
{
	std::string expCons;

	for (MyVariables.posOfFor = 0; MyVariables.posOfFor < optr_bef; MyVariables.posOfFor++)
		expCons += MyVariables.expression[MyVariables.posOfFor];

	if (MyVariables.expression[optr_bef] == '-' && MyVariables.expression[optr_af] == '-'
		|| MyVariables.expression[optr_bef] == '+' && MyVariables.expression[optr_af] == '+')
		expCons += '+';
	else if (MyVariables.expression[optr_bef] == '+' && MyVariables.expression[optr_af] == '-'
		|| MyVariables.expression[optr_bef] == '-' && MyVariables.expression[optr_af] == '+')
		expCons += '-';

	for (MyVariables.posOfFor = optr_af + 1; MyVariables.posOfFor <= MyVariables.stringSize; MyVariables.posOfFor++)
		expCons += MyVariables.expression[MyVariables.posOfFor];

	MyVariables.expression = expCons;
}

void Store::storeExpConsMultDivOrders(int optr_bef, int optr_af, int mode)
{
	std::string expConsMultDivOrders;

	for (MyVariables.posOfFor = 0; MyVariables.posOfFor <= optr_bef; MyVariables.posOfFor++)
		expConsMultDivOrders += MyVariables.expression[MyVariables.posOfFor];

	if (mode == 0)
		expConsMultDivOrders += MyVariables.expression[optr_af];
	else if (mode == 1)
		expConsMultDivOrders += "1/";

	for (; MyVariables.posOfFor < optr_af; MyVariables.posOfFor++)
		expConsMultDivOrders += MyVariables.expression[MyVariables.posOfFor];

	for (MyVariables.posOfFor = optr_af + 1; MyVariables.posOfFor <= MyVariables.stringSize; MyVariables.posOfFor++)
		expConsMultDivOrders += MyVariables.expression[MyVariables.posOfFor];

	MyVariables.expression = expConsMultDivOrders;
}

void Store::storeExpBracOptr(int optr_bef, int optr_af)
{
	std::string expBrac;

	for (MyVariables.posOfFor = 0; MyVariables.posOfFor <= optr_bef; MyVariables.posOfFor++)
		expBrac += MyVariables.expression[MyVariables.posOfFor];

	expBrac += '*';

	for (MyVariables.posOfFor = optr_af; MyVariables.posOfFor <= MyVariables.stringSize; MyVariables.posOfFor++)
		expBrac += MyVariables.expression[MyVariables.posOfFor];

	MyVariables.expression = expBrac;
}

void Store::storeExpConsBracOptr(int optr_bef, int optr_af, int mode)
{
	std::string expBrac;

	for (MyVariables.posOfFor = 0; MyVariables.posOfFor <= optr_bef; MyVariables.posOfFor++)
		expBrac += MyVariables.expression[MyVariables.posOfFor];

	if (mode == 0)
		expBrac += "1*";
	else if (mode == 1)
		expBrac += "*1";

	for (MyVariables.posOfFor = optr_af; MyVariables.posOfFor <= MyVariables.stringSize; MyVariables.posOfFor++)
		expBrac += MyVariables.expression[MyVariables.posOfFor];

	MyVariables.expression = expBrac;
}

std::string Store::storeExpBrac(int optr_bef, int optr_af)
{
	std::string expBrac;

	for (MyVariables.posOfFor = optr_bef + 1; MyVariables.posOfFor < optr_af; MyVariables.posOfFor++)
		expBrac += MyVariables.expression[MyVariables.posOfFor];

	return expBrac;
}

std::string Store::storeExpBracAf(int optr_bef, int optr_af, std::string exp, int stringSizeAf)
{
	std::string expBracAf;

	for (MyVariables.posOfFor = 0; MyVariables.posOfFor < optr_bef; MyVariables.posOfFor++)
		expBracAf += exp[MyVariables.posOfFor];

	expBracAf += std::to_string(MyVariables.resultBrac);
	MyVariables.resultBrac = 0;

	for (MyVariables.posOfFor = optr_af + 1; MyVariables.posOfFor <= stringSizeAf; MyVariables.posOfFor++)
		expBracAf += exp[MyVariables.posOfFor];

	return expBracAf;
}

std::string Store::storeString(int optr_bef, int optr_af)
{
	std::string num;

	for (MyVariables.posOfFor = optr_bef + 1; MyVariables.posOfFor < optr_af || MyVariables.posOfFor == MyVariables.stringSize; MyVariables.posOfFor++)
		num += MyVariables.expression[MyVariables.posOfFor];

	return num;
}
