#include "AddSub.h"

void AddSub::doAddSub(int brac)
{
	//formating the original expression by adding a sign
	if (Variables::expression[0] != '+' && Variables::expression[0] != '-')
		Variables::expression = '+' + Variables::expression;

	Variables::reset();
	Variables::numOfOptr = Count::calNumOfOptr('+') + Count::calNumOfOptr('-');
	Variables::stringSize = Count::calStringSize();
	int j{};

	//for loop to undergo addition & subtraction
	for (Variables::optrDone; Variables::optrDone < Variables::numOfOptr; Variables::optrDone++)
	{
		if (j == 0)
		{
			forLoopAddSub(Variables::optr_1, Variables::optr_2, 0, brac);
			j = 1;
		}
		else
		{
			forLoopAddSub(Variables::optr_2, Variables::optr_1, 1, brac);
			j = 0;
		}
	}
}

void AddSub::forLoopAddSub(int optr_1a, int optr_2a, int mode, int brac)
{
	optrAddSub(optr_1a, optr_2a, mode);

	if (mode == 0)
	{
		optr_1a = Variables::optr_1;
		optr_2a = Variables::optr_2;
	}
	else if (mode == 1)
	{
		optr_2a = Variables::optr_1;
		optr_1a = Variables::optr_2;
	}

	//storing the current number as a string
	std::string num{ Store::storeString(optr_1a, optr_2a) };

	//converting the number to integer and adding to result
	if (!num.empty())
	{
		if (brac == 0)
		{
			if (Variables::expression[optr_1a] == '+')
				Variables::result += std::stod(num);
			else if (Variables::expression[optr_1a] == '-')
				Variables::result -= std::stod(num);
		}
		else if (brac == 1)
		{
			if (Variables::expression[optr_1a] == '+')
				Variables::resultBrac += std::stod(num);
			else if (Variables::expression[optr_1a] == '-')
				Variables::resultBrac -= std::stod(num);
		}
	}
}

void AddSub::optrAddSub(int optr_1a, int optr_2a, int mode)
{
	optr_2a = optr_1a;

	//find the position of next operator
	optr_1a = Expression::setAndFind(optr_2a, 1, 1, 2);
	optr_2a = Expression::setAndFind(optr_1a + 1, 1, 1, 2);

	if (mode == 0)
	{
		Variables::optr_1 = optr_1a;
		Variables::optr_2 = optr_2a;
	}
	else if (mode == 1)
	{
		Variables::optr_2 = optr_1a;
		Variables::optr_1 = optr_2a;
	}
}