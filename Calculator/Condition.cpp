#include "Condition.h"
#include <iostream>

void Condition::error()
{
	std::cout << "Error";
	exit(0);
}

bool Condition::checkForCondition(int i)
{
	switch (i)
	{
	case 1:
		return posOfFor <= stringSize;
		break;
			
	case 2:
		return posOfFor >= 0;
		break;

	default:
		error();
		return 0;
		break;
	}
}

bool Condition::checkIfCondition(int i, char j)
{
	switch (i)
	{
	case 1:
		return checkOptrAll(j);
		break;

	case 2:
		return checkOptrAddSub(j);
		break;

	case 3:
		return checkOptrMultDiv(j);
		break;

	default:
		error();
		return 0;
		break;
	}
}

bool Condition::checkOptrAll(char i)
{
	return (i == '+' || i == '-' || i == '*' || i == '/' || i == '%');
}

bool Condition::checkOptrAddSub(char i)
{
	return (i == '+' || i == '-');
}

bool Condition::checkOptrMultDiv(char i)
{
	return (i == '*' || i == '/' || i == '%');
}
