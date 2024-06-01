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

int Expression::setAndFind(int POForigin, int actAfterFor, int forMode, int ifmode)
{
	Variables::stringSize = Variables::stringSize;

	for (Variables::posOfFor = POForigin; Condition::checkForCondition(forMode); Variables::posOfFor += actAfterFor)
	{
		char i = Variables::expression[Variables::posOfFor];

		//make detecting the last number possible
		if (Variables::posOfFor == Variables::stringSize && ifmode != 6)
			return Variables::stringSize + 1;

		//detect whether it's at the beginning of the expression or not
		if (Variables::posOfFor == 0 && forMode == 2)
			return -1;

		if (Condition::checkIfCondition(ifmode, i))
			return Variables::posOfFor;
	}

	IOError::error();
	return 0;
}

std::string Expression::processOptr(std::string num1, std::string num2)
{
	std::string numResult;
	
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