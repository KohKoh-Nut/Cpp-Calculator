#include "Condition.h"
#include "IOError.h"
#include <iostream>

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
		MyIOError.error();
		return 0;
		break;
	}
}

bool Condition::checkIfCondition(int i, char j)
{
	switch (i)
	{
	case 1:
		return (j == '+' || j == '-' || j == '*' || j == '/' || j == '%');
		break;

	case 2:
		return (j == '+' || j == '-');
		break;

	case 3:
		return (j == '*' || j == '/' || j == '%');
		break;

	case 4:
		return (j == '^');
		break;

	case 5:
		return (j == '(');
		break;

	case 6:
		return (j == '(' || j == ')');
		break;

	case 7:
		return (j == ')');
		break;

	default:
		MyIOError.error();
		return 0;
		break;
	}
}