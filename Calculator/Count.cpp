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

int Count::calNumOfConsOptr(int j)
{
	Variables::resetPOF();
	int numOfConsOptr{};

	for (char i : Variables::expression)
	{
		if (Condition::checkIfCondition(j, i) && Condition::checkIfCondition(2, Variables::expression[Variables::posOfFor + 1]))
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
		if (!Condition::checkIfCondition(1, i) && Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			numOfBracOptr++;

		Variables::posOfFor++;
	}

	return numOfBracOptr;
}

int Count::calNumOfBracBacOptr()
{
	int numOfBracOptr{}, j{};
	Variables::posOfFor = 1;

	for (char i : Variables::expression)
	{
		if (Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor - 1]) && !Condition::checkIfCondition(1, i))
			numOfBracOptr++;

		//prevent the detection of back brackets being the first element of the string
		if (j == 0)
		{
			Variables::posOfFor--;
			j++;
		}

		Variables::posOfFor++;
	}

	return numOfBracOptr;
}

int Count::calStringSize()
{
	Variables::resetPOF();
	int stringSize{ -1 };

	//find the size of the expression
	for (char i : Variables::expression)
		stringSize++;

	return stringSize;
}