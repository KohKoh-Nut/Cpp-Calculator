#include "Expression.h"

void Expression::evaluate()
{
	IOError::input();
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
		//detecting double
		if (Variables::posOfFor != 0
			&& Condition::checkIfCondition(8, Variables::expression[Variables::posOfFor - 1])
			&& Condition::checkIfCondition(ifmode, Variables::expression[Variables::posOfFor]))
			continue;

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

void Expression::findMultDivOrders(int ifMode)
{
	Variables::optr_1 = Expression::find(0, 1, 1, ifMode); //find the position of operator
	Variables::optr_2 = Expression::find(Variables::optr_1 - 1, -1, 2, 1); //find the position of operator before
	Variables::optr_3 = Expression::find(Variables::optr_1 + 1, 1, 1, 1); //find the position of operator after
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