#include "Expression.h"
#include "Variables.h"
#include <string>
#include <iostream>

void Expression::evaluate()
{
	MyVariables.expression = MyVariables.MyIOError.input();
	MyVariables.MyFormat.format();
	MyVariables.MyBrackets.doBrackets();
	MyVariables.MyOrders.doOrders();
	MyVariables.MyMultDiv.multDiv();
	MyVariables.MyAddSub.doAddSub(0);
	MyVariables.MyIOError.output();
}

int Expression::setAndFind(int POForigin, int actAfterFor, int forMode, int ifmode)
{
	MyVariables.stringSize = MyVariables.stringSize;

	for (MyVariables.posOfFor = POForigin; MyVariables.MyCondition.checkForCondition(forMode); MyVariables.posOfFor += actAfterFor)
	{
		char i = MyVariables.expression[MyVariables.posOfFor];

		//make detecting the last number possible
		if (MyVariables.posOfFor == MyVariables.stringSize && ifmode != 6)
			return MyVariables.stringSize + 1;

		//detect whether it's at the beginning of the expression or not
		if (MyVariables.posOfFor == 0 && forMode == 2)
			return -1;

		if (MyVariables.MyCondition.checkIfCondition(ifmode, i))
			return MyVariables.posOfFor;
	}

	MyVariables.MyIOError.error();
	return 0;
}

std::string Expression::processOptr(std::string num1, std::string num2)
{
	std::string numResult;
	
	switch (MyVariables.expression[MyVariables.optr_1])
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
		MyVariables.MyIOError.error();
		break;
	}

	return numResult;
}