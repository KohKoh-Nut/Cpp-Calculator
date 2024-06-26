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

int Expression::findOptr(int POForigin, int actAfterFor, int forMode, int ifmode)
{
	for (Variables::posOfFor = POForigin; Condition::checkForCondition(forMode); Variables::posOfFor += actAfterFor)
	{
		//detecting double
		if (Variables::posOfFor != 0
			&& Condition::checkIfCondition(8, Variables::expression[Variables::posOfFor - 1])
			&& Condition::checkIfCondition(ifmode, Variables::expression[Variables::posOfFor]))
			continue;

		//detecting the last character of the expression
		if (Variables::posOfFor == Variables::stringSize && ifmode != 6 && ifmode != 10)
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
	Variables::optr_1 = Expression::findOptr(0, 1, 1, ifMode); //find the position of operator
	Variables::optr_2 = Expression::findOptr(Variables::optr_1 - 1, -1, 2, 1); //find the position of operator before
	Variables::optr_3 = Expression::findOptr(Variables::optr_1 + 1, 1, 1, 1); //find the position of operator after
}

std::string Expression::processOptr(std::string num1, std::string num2)
{
	long double numResult{};
	
	//take the arguments and evaluate the numbers
	switch (Variables::expression[Variables::optr_1])
	{
	case '*':
		numResult = std::stold(num1) * std::stold(num2);
		break;

	case '/':
		numResult = std::stold(num1) / std::stold(num2);
		break;

	case '%':
		numResult = std::stoi(num1) % std::stoi(num2);
		break;

	case '^':
		numResult = pow(std::stold(num1), std::stold(num2));
		break;

	default:
		IOError::error();
		break;
	}

	//for the precision of small number
	std::ostringstream result;
	result << std::setprecision(100) << numResult;

	return result.str();
}