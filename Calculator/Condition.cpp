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
		return (optr == '+' || optr == '-' || optr == '*' || optr == '/' || optr == '%');
		break;

	case 2:
		return (optr == '+' || optr == '-');
		break;

	case 3:
		return (optr == '*' || optr == '/' || optr == '%');
		break;

	case 4:
		return (optr == '^');
		break;

	case 5:
		return (optr == '(');
		break;

	case 6:
		return (optr == '(' || optr == ')');
		break;

	case 7:
		return (optr == ')');
		break;

	case 8:
		return (optr == 'e' || optr == 'E');
		break;

	case 9:
		return (optr == '<' || optr == '>');
		break;

	case 10:
		return (optr == '[' || optr == ']');
		break;

	default:
		IOError::error();
		return 0;
		break;
	}
}