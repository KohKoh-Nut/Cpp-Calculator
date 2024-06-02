#include "Condition.h"

bool Condition::checkForCondition(int mode)
{
	switch (mode)
	{
	case 1:
		return Variables::posOfFor <= Variables::stringSize;
		break;
			
	case 2:
		return Variables::posOfFor >= 0;
		break;

	default:
		IOError::error();
		return 0;
		break;
	}
}

bool Condition::checkIfCondition(int mode, char optr)
{
	switch (mode)
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
		IOError::error();
		return 0;
		break;
	}
}