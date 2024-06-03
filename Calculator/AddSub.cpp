#include "AddSub.h"

void AddSub::doAddSub(int brac)
{
	//formating the original expression by adding a sign
	if (Variables::expression[0] != '+' && Variables::expression[0] != '-')
		Variables::expression = '+' + Variables::expression;

	Variables::reset();
	Variables::numOfOptr = Count::calNumOfOptr('+') + Count::calNumOfOptr('-') - Count::calNumOfDouble();
	Count::calStringSize();
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

	//for continuous processing of the signs
	if (mode == 0)
	{
		optr_1a = Variables::optr_1;
		optr_2a = Variables::optr_2;
	}
	
	if (mode == 1)
	{
		optr_2a = Variables::optr_1;
		optr_1a = Variables::optr_2;
	}

	//storing the current number as a string
	std::string num{ Store::storeString(optr_1a, optr_2a) };

	//converting the number to integer and adding to result
	if (!num.empty())
	{
		if (brac == 0) //normal addition
			Variables::result = Store::storeResult(Variables::result, Variables::expression[optr_1a], num);
		
		if (brac == 1) //addition for the formatting of brackets
			Variables::resultBrac = Store::storeResult(Variables::resultBrac, Variables::expression[optr_1a], num);
	}
}

void AddSub::optrAddSub(int optr_1a, int optr_2a, int mode)
{
	optr_2a = optr_1a;

	//find the position of next operator
	optr_1a = Expression::findOptr(optr_2a, 1, 1, 2);
	optr_2a = Expression::findOptr(optr_1a + 1, 1, 1, 2);

	//setting the result back to variables
	if (mode == 0)
	{
		Variables::optr_1 = optr_1a;
		Variables::optr_2 = optr_2a;
	}
	
	if (mode == 1)
	{
		Variables::optr_2 = optr_1a;
		Variables::optr_1 = optr_2a;
	}
}