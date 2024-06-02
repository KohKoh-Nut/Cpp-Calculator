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

void Store::storeExpFormConsNegatives(int optr_bef, int optr_af)
{
	std::string expCons;

	for (Variables::posOfFor = 0; Variables::posOfFor < optr_bef; Variables::posOfFor++)
		expCons += Variables::expression[Variables::posOfFor];

	//applying the rule of two negatives get a positive
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

void Store::storeExpFormConsMultDivOrders(int optr_bef, int optr_af, int mode)
{
	std::string expConsMultDivOrders;

	for (Variables::posOfFor = 0; Variables::posOfFor <= optr_bef; Variables::posOfFor++)
		expConsMultDivOrders += Variables::expression[Variables::posOfFor];

	if (mode == 0) //multiplication and division
		expConsMultDivOrders += Variables::expression[optr_af];
	
	if (mode == 1) //orders
		expConsMultDivOrders += "(1/";

	for (; Variables::posOfFor < optr_af; Variables::posOfFor++)
		expConsMultDivOrders += Variables::expression[Variables::posOfFor];

	for (Variables::posOfFor = optr_af + 1; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
		expConsMultDivOrders += Variables::expression[Variables::posOfFor];

	if (mode == 1)
		expConsMultDivOrders += ')';

	Variables::expression = expConsMultDivOrders;
}

void Store::storeExpFormBrac(int optr_bef, int optr_af, int mode)
{
	std::string expBrac;

	for (Variables::posOfFor = 0; Variables::posOfFor <= optr_bef; Variables::posOfFor++)
		expBrac += Variables::expression[Variables::posOfFor];

	if (mode == 0) //brackets without operator
		expBrac += '*';
	if (mode == 1) //consecutive front brackets
		expBrac += "1*";
	if (mode == 2) //consecutive back brackets
		expBrac += "*1";
	
	for (Variables::posOfFor = optr_af; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
		expBrac += Variables::expression[Variables::posOfFor];

	Variables::expression = expBrac;
}

std::string Store::storeSubExpBrac(int optr_bef, int optr_af)
{
	std::string expBrac;

	//storing the sub-expression
	for (Variables::posOfFor = optr_bef + 1; Variables::posOfFor < optr_af; Variables::posOfFor++)
		expBrac += Variables::expression[Variables::posOfFor];

	return expBrac;
}

std::string Store::storeSubExpBracResult(int optr_bef, int optr_af, std::string exp, int stringSizeAf)
{
	std::string expBracAf;

	//for loop until just before the front bracket
	for (Variables::posOfFor = 0; Variables::posOfFor < optr_bef; Variables::posOfFor++)
		expBracAf += exp[Variables::posOfFor];
	
	//for the precision of small number
	std::ostringstream result;
	result << std::setprecision(100) << Variables::resultBrac;

	//put in the result of the sub-expression
	expBracAf += result.str();
	Variables::resultBrac = 0; //resetting the result

	//for loop starts from just after the back bracket
	for (Variables::posOfFor = optr_af + 1; Variables::posOfFor <= stringSizeAf; Variables::posOfFor++)
		expBracAf += exp[Variables::posOfFor];

	return expBracAf;
}

void Store::storeEvaStrings()
{
	//storing the numbers as string
	std::string num1, num2;
	num1 = Store::storeString(Variables::optr_2, Variables::optr_1);
	num2 = Store::storeString(Variables::optr_1, Variables::optr_3);

	//converting the numbers to integer and evaluate
	//then storing the result as a string
	std::string num3{ Expression::processOptr(num1, num2) };

	Store::storeExp(Variables::optr_2, Variables::optr_3, num3);
}

std::string Store::storeString(int optr_bef, int optr_af)
{
	std::string num;

	//for loop to store the string between the operator before and the operator after
	for (Variables::posOfFor = optr_bef + 1; Variables::posOfFor < optr_af || Variables::posOfFor == Variables::stringSize; Variables::posOfFor++)
		num += Variables::expression[Variables::posOfFor];

	return num;
}

double Store::storeResult(double result, char optr, std::string num)
{
	if (optr == '+')
		result += std::stold(num);
	else if (optr == '-')
		result -= std::stold(num);

	return result;
}