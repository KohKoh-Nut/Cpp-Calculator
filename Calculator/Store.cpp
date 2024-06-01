#include "Store.h"

void Store::storeExp(int optr_bef, int optr_af, std::string num)
{
	//string to store the new expression after evaluation
	std::string expMultDiv;

	//the process of storing the new expression
	for (Variables::posOfFor = 0; Variables::posOfFor <= optr_bef; Variables::posOfFor++)
		expMultDiv += Variables::expression[Variables::posOfFor];

	expMultDiv += num;

	for (Variables::posOfFor = optr_af; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
		expMultDiv += Variables::expression[Variables::posOfFor];

	//putting the new expression back to expression for further evaluation
	Variables::expression = expMultDiv;
}

void Store::storeExpCons(int optr_bef, int optr_af)
{
	std::string expCons;

	for (Variables::posOfFor = 0; Variables::posOfFor < optr_bef; Variables::posOfFor++)
		expCons += Variables::expression[Variables::posOfFor];

	if (Variables::expression[optr_bef] == '-' && Variables::expression[optr_af] == '-'
		|| Variables::expression[optr_bef] == '+' && Variables::expression[optr_af] == '+')
		expCons += '+';
	else if (Variables::expression[optr_bef] == '+' && Variables::expression[optr_af] == '-'
		|| Variables::expression[optr_bef] == '-' && Variables::expression[optr_af] == '+')
		expCons += '-';

	for (Variables::posOfFor = optr_af + 1; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
		expCons += Variables::expression[Variables::posOfFor];

	Variables::expression = expCons;
}

void Store::storeExpConsMultDivOrders(int optr_bef, int optr_af, int mode)
{
	std::string expConsMultDivOrders;

	for (Variables::posOfFor = 0; Variables::posOfFor <= optr_bef; Variables::posOfFor++)
		expConsMultDivOrders += Variables::expression[Variables::posOfFor];

	if (mode == 0)
		expConsMultDivOrders += Variables::expression[optr_af];
	else if (mode == 1)
		expConsMultDivOrders += "1/";

	for (; Variables::posOfFor < optr_af; Variables::posOfFor++)
		expConsMultDivOrders += Variables::expression[Variables::posOfFor];

	for (Variables::posOfFor = optr_af + 1; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
		expConsMultDivOrders += Variables::expression[Variables::posOfFor];

	Variables::expression = expConsMultDivOrders;
}

void Store::storeExpBracOptr(int optr_bef, int optr_af)
{
	std::string expBrac;

	for (Variables::posOfFor = 0; Variables::posOfFor <= optr_bef; Variables::posOfFor++)
		expBrac += Variables::expression[Variables::posOfFor];

	expBrac += '*';

	for (Variables::posOfFor = optr_af; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
		expBrac += Variables::expression[Variables::posOfFor];

	Variables::expression = expBrac;
}

void Store::storeExpConsBracOptr(int optr_bef, int optr_af, int mode)
{
	std::string expBrac;

	for (Variables::posOfFor = 0; Variables::posOfFor <= optr_bef; Variables::posOfFor++)
		expBrac += Variables::expression[Variables::posOfFor];

	if (mode == 0)
		expBrac += "1*";
	else if (mode == 1)
		expBrac += "*1";

	for (Variables::posOfFor = optr_af; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
		expBrac += Variables::expression[Variables::posOfFor];

	Variables::expression = expBrac;
}

std::string Store::storeExpBrac(int optr_bef, int optr_af)
{
	std::string expBrac;

	for (Variables::posOfFor = optr_bef + 1; Variables::posOfFor < optr_af; Variables::posOfFor++)
		expBrac += Variables::expression[Variables::posOfFor];

	return expBrac;
}

std::string Store::storeExpBracAf(int optr_bef, int optr_af, std::string exp, int stringSizeAf)
{
	std::string expBracAf;

	for (Variables::posOfFor = 0; Variables::posOfFor < optr_bef; Variables::posOfFor++)
		expBracAf += exp[Variables::posOfFor];

	expBracAf += std::to_string(Variables::resultBrac);
	Variables::resultBrac = 0;

	for (Variables::posOfFor = optr_af + 1; Variables::posOfFor <= stringSizeAf; Variables::posOfFor++)
		expBracAf += exp[Variables::posOfFor];

	return expBracAf;
}

std::string Store::storeString(int optr_bef, int optr_af)
{
	std::string num;

	for (Variables::posOfFor = optr_bef + 1; Variables::posOfFor < optr_af || Variables::posOfFor == Variables::stringSize; Variables::posOfFor++)
		num += Variables::expression[Variables::posOfFor];

	return num;
}