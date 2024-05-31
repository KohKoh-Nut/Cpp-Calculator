#include "Count.h"
#include "Variables.h"

int Count::calNumOfOptr(char optr)
{
	MyVariables.resetPOF();
	int numOfOptr{};

	for (char i : MyVariables.expression)
	{
		if (i == optr)
			numOfOptr++;

		MyVariables.posOfFor++;
	}

	return numOfOptr;
}

int Count::calNumOfConsOptr(int j)
{
	MyVariables.resetPOF();
	int numOfConsOptr{};

	for (char i : MyVariables.expression)
	{
		if (MyVariables.MyCondition.checkIfCondition(j, i) && MyVariables.MyCondition.checkIfCondition(2, MyVariables.expression[MyVariables.posOfFor + 1]))
			numOfConsOptr++;

		MyVariables.posOfFor++;
	}

	return numOfConsOptr;
}

int Count::calNumOfBracFroOptr()
{
	MyVariables.resetPOF();
	int numOfBracOptr{};

	for (char i : MyVariables.expression)
	{
		if (!MyVariables.MyCondition.checkIfCondition(1, i) && MyVariables.MyCondition.checkIfCondition(5, MyVariables.expression[MyVariables.posOfFor + 1]))
			numOfBracOptr++;

		MyVariables.posOfFor++;
	}

	return numOfBracOptr;
}

int Count::calNumOfBracBacOptr()
{
	int numOfBracOptr{}, j{};
	MyVariables.posOfFor = 1;

	for (char i : MyVariables.expression)
	{
		if (MyVariables.MyCondition.checkIfCondition(7, MyVariables.expression[MyVariables.posOfFor - 1]) && !MyVariables.MyCondition.checkIfCondition(1, i))
			numOfBracOptr++;

		//prevent the detection of back brackets being the first element of the string
		if (j == 0)
		{
			MyVariables.posOfFor--;
			j++;
		}

		MyVariables.posOfFor++;
	}

	return numOfBracOptr;
}

int Count::calStringSize()
{
	MyVariables.resetPOF();
	int stringSize{ -1 };

	//find the size of the expression
	for (char i : MyVariables.expression)
		stringSize++;

	return stringSize;
}