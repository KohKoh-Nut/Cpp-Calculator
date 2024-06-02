#include "Count.h"

int Count::calNumOfOptr(char optr)
{
	Variables::resetPOF();
	int numOfOptr{};

	for (char i : Variables::expression)
	{
		if (i == optr)
			numOfOptr++;

		Variables::posOfFor++;
	}

	return numOfOptr;
}

int Count::calNumOfConsOptr(int ifMode)
{
	Variables::resetPOF();
	int numOfConsOptr{};

	for (char i : Variables::expression)
	{
		if (Condition::checkIfCondition(ifMode, i) && Condition::checkIfCondition(2, Variables::expression[Variables::posOfFor + 1]))
			numOfConsOptr++;

		Variables::posOfFor++;
	}

	return numOfConsOptr;
}

int Count::calNumOfBracFroOptr()
{
	Variables::resetPOF();
	int numOfBracOptr{};

	for (char i : Variables::expression)
	{
		//if the character right before a front bracket is not an operator
		if (!Condition::checkIfCondition(1, i) && Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			numOfBracOptr++;

		Variables::posOfFor++;
	}

	return numOfBracOptr;
}

int Count::calNumOfBracBacOptr()
{
	Variables::posOfFor = 1;
	int numOfBracOptr{}, firstBacBrac{};

	for (char i : Variables::expression)
	{
		//if the character right after a back bracket is not an operator
		if (Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor - 1]) && !Condition::checkIfCondition(1, i))
			numOfBracOptr++;

		//prevent the detection of back brackets being the first element of the string
		firstBacBrac = bacBracFirst(firstBacBrac);

		Variables::posOfFor++;
	}

	return numOfBracOptr;
}

int Count::bacBracFirst(int firstBacBrac)
{
	if (firstBacBrac == 0)
	{
		Variables::posOfFor--;
		firstBacBrac++;
	}

	return firstBacBrac;
}

void Count::calStringSize()
{
	Variables::resetPOF();
	Variables::stringSize = -1;

	for (char i : Variables::expression)
		Variables::stringSize++;
}