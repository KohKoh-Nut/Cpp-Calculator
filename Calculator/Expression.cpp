#include "Expression.h"

void Expression::evaluate()
{
	Variables::expression = IOError::input();
	Format::format();
	Brackets::doBrackets();
	Orders::doOrders();
	MultDiv::multDiv();
	AddSub::doAddSub(0);
	IOError::output();
}

int Expression::find(int POForigin, int actAfterFor, int forMode, int ifmode)
{
	for (Variables::posOfFor = POForigin; Condition::checkForCondition(forMode); Variables::posOfFor += actAfterFor)
	{
		//detecting the last character of the expression
		if (Variables::posOfFor == Variables::stringSize && ifmode != 6)
			return Variables::stringSize + 1;

		//detecting the first character of the expression for addition and subtraction
		if (Variables::posOfFor == 0 && forMode == 2)
			return -1;

		if (Condition::checkIfCondition(ifmode, Variables::expression[Variables::posOfFor]))
			return Variables::posOfFor;
	}

	IOError::error();
	return 0;
}

std::string Expression::processOptr(std::string num1, std::string num2)
{
	std::string numResult;
	
	//take the arguments and evaluate the numbers
	switch (Variables::expression[Variables::optr_1])
	{
	case '*':
		numResult = std::to_string(std::stod(num1) * std::stod(num2));
		break;

	case '/':
		numResult = std::to_string(std::stod(num1) / std::stod(num2));
		break;

	case '%':
		numResult = std::to_string(std::stoi(num1) % std::stoi(num2));
		break;

	case '^':
		numResult = std::to_string(pow(std::stod(num1), std::stod(num2)));
		break;

	default:
		IOError::error();
		break;
	}

	return numResult;
}