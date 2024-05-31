#include "Variables.h"
#include "AddSub.h"

void AddSub::doAddSub(int brac)
{
	//formating the original expression by adding a sign
	if (MyVariables.expression[0] != '+' && MyVariables.expression[0] != '-')
		MyVariables.expression = '+' + MyVariables.expression;

	MyVariables.reset();
	MyVariables.numOfOptr = MyVariables.MyCount.calNumOfOptr('+') + MyVariables.MyCount.calNumOfOptr('-');
	MyVariables.stringSize = MyVariables.MyCount.calStringSize();
	int j{};

	//for loop to undergo addition & subtraction
	for (MyVariables.optrDone; MyVariables.optrDone < MyVariables.numOfOptr; MyVariables.optrDone++)
	{
		if (j == 0)
		{
			forLoopAddSub(MyVariables.optr_1, MyVariables.optr_2, 0, brac);
			j = 1;
		}
		else
		{
			forLoopAddSub(MyVariables.optr_2, MyVariables.optr_1, 1, brac);
			j = 0;
		}
	}
}

void AddSub::forLoopAddSub(int optr_1a, int optr_2a, int mode, int brac)
{
	optrAddSub(optr_1a, optr_2a, mode);

	if (mode == 0)
	{
		optr_1a = MyVariables.optr_1;
		optr_2a = MyVariables.optr_2;
	}
	else if (mode == 1)
	{
		optr_2a = MyVariables.optr_1;
		optr_1a = MyVariables.optr_2;
	}

	//storing the current number as a string
	std::string num{ MyVariables.MyStore.storeString(optr_1a, optr_2a) };

	//converting the number to integer and adding to result
	if (!num.empty())
	{
		if (brac == 0)
		{
			if (MyVariables.expression[optr_1a] == '+')
				MyVariables.result += std::stod(num);
			else if (MyVariables.expression[optr_1a] == '-')
				MyVariables.result -= std::stod(num);
		}
		else if (brac == 1)
		{
			if (MyVariables.expression[optr_1a] == '+')
				MyVariables.resultBrac += std::stod(num);
			else if (MyVariables.expression[optr_1a] == '-')
				MyVariables.resultBrac -= std::stod(num);
		}
	}
}

void AddSub::optrAddSub(int optr_1a, int optr_2a, int mode)
{
	optr_2a = optr_1a;

	//find the position of next operator
	optr_1a = MyVariables.MyExpression.setAndFind(optr_2a, 1, 1, 2);
	optr_2a = MyVariables.MyExpression.setAndFind(optr_1a + 1, 1, 1, 2);

	if (mode == 0)
	{
		MyVariables.optr_1 = optr_1a;
		MyVariables.optr_2 = optr_2a;
	}
	else if (mode == 1)
	{
		MyVariables.optr_2 = optr_1a;
		MyVariables.optr_1 = optr_2a;
	}
}