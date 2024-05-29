#include "Expression.h"
#include "Condition.h"
#include <string>
#include <iostream>

/* others */
void Expression::reset()
{
	posOfFor = 0, stringSize = 0;
	numOfOptr = 0, optrDone = 0;
	optr_1 = 0, optr_2 = 0, optr_3 = 0;
}

void Expression::resetPOF()
{
	posOfFor = 0;
}

void Expression::input()
{
	std::cout << "Enter an expression: ";
	std::cin >> expression;
}

void Expression::output()
{
	std::cout << result;
}

void Expression::format()
{
	int consOptrMultDivDone{}, numOfConsOptrMultDiv{ calNumOfConsOptr(3) };
	stringSize = calStringSize();

	//format the signs after * & /
	for (consOptrMultDivDone; consOptrMultDivDone < numOfConsOptrMultDiv; consOptrMultDivDone++)
	{
		for (char i : expression)
		{
			if (MyCondition.checkOptrMultDiv(i) && MyCondition.checkOptrAddSub(expression[posOfFor + 1]))
			{
				optr_1 = posOfFor;
				optr_2 = setAndFind(optr_1 - 1, -1, 2, 1);
				optr_3 = posOfFor + 1;

				storeExpConsMultDivOrders(optr_2, optr_3, 0);
				break;
			}

			posOfFor++;
		}
	}

	int consOptrDone{}, numOfConsOptr{ calNumOfConsOptr(2) };
	int j{};

	//formatting the original expression by processing the consecutive signs
	for (consOptrDone; consOptrDone < numOfConsOptr;)
	{
		reset();
		stringSize = calStringSize();
		if (j == 0)
		{
			consOptrDone = forLoopAddSubFormat(optr_1, optr_2, 0, consOptrDone);
			j = 1;
		}
		else if (j == 1)
		{
			consOptrDone = forLoopAddSubFormat(optr_2, optr_1, 1, consOptrDone);
			j = 0;
		}
	}

	int consOptrOrdersDone{}, numOfConsOptrOrders{ calNumOfConsOptr(4) };
	stringSize = calStringSize();

	//format the signs after ^
	for (consOptrOrdersDone; consOptrOrdersDone < numOfConsOptrOrders; consOptrOrdersDone++)
	{
		for (char i : expression)
		{
			if (MyCondition.checkOptrOrders(i) && MyCondition.checkOptrAddSub(expression[posOfFor + 1]))
			{
				optr_1 = posOfFor;
				optr_2 = setAndFind(optr_1 - 1, -1, 2, 1);
				optr_3 = posOfFor + 1;

				storeExpConsMultDivOrders(optr_2, optr_3, 1);
				break;
			}

			posOfFor++;
		}
	}
}

void Expression::error()
{
	std::cout << "Error";
	exit(0);
}


/* store */
void Expression::storeExp(int optr_bef, int optr_af, std::string num)
{
	//string to store the new expression after evaluation
	std::string expMultDiv;
	
	//the process of storing the new expression
	for (posOfFor = 0; posOfFor <= optr_bef; posOfFor++)
		expMultDiv += expression[posOfFor];

	expMultDiv += num;

	for (posOfFor = optr_af; posOfFor <= stringSize; posOfFor++)
		expMultDiv += expression[posOfFor];

	//putting the new expression back to expression for further evaluation
	expression = expMultDiv;
}

void Expression::storeExpCons(int optr_bef, int optr_af)
{
	//string to store the new expression after evaluation
	std::string expCons;

	//the process of storing the new expression
	for (posOfFor = 0; posOfFor < optr_bef ; posOfFor++)
		expCons += expression[posOfFor];

	if(expression[optr_bef] == '-' && expression[optr_af] == '-'
		|| expression[optr_bef] == '+' && expression[optr_af] == '+')
		expCons += '+';
	else if (expression[optr_bef] == '+' && expression[optr_af] == '-'
		|| expression[optr_bef] == '-' && expression[optr_af] == '+')
		expCons += '-';

	for (posOfFor = optr_af + 1; posOfFor<= stringSize; posOfFor++)
		expCons += expression[posOfFor];

	//putting the new expression back to expression for further evaluation
	expression = expCons;
}

void Expression::storeExpConsMultDivOrders(int optr_bef, int optr_af, int mode)
{
	std::string expConsMultDivOrders;

	for (posOfFor = 0; posOfFor <= optr_bef; posOfFor++)
		expConsMultDivOrders += expression[posOfFor];

	if (mode == 0)
		expConsMultDivOrders += expression[optr_af];
	else if (mode == 1)
		expConsMultDivOrders += "1/";

	for (; posOfFor < optr_af; posOfFor++)
		expConsMultDivOrders += expression[posOfFor];

	for (posOfFor = optr_af + 1; posOfFor <= stringSize; posOfFor++)
		expConsMultDivOrders += expression[posOfFor];

	expression = expConsMultDivOrders;
}

std::string Expression::storeString(int optr_bef, int optr_af)
{
	std::string num;

	for (posOfFor = optr_bef + 1; posOfFor < optr_af || posOfFor == stringSize; posOfFor++)
		num += expression[posOfFor];

	return num;
}


/* calculate */
int Expression::calNumOfOptr(char optr)
{
	resetPOF();
	int numOfOptr{};

	for (char i : expression)
	{
		if (i == optr)
			numOfOptr++;

		posOfFor++;
	}

	return numOfOptr;
}

int Expression::calNumOfConsOptr(int j)
{
	resetPOF();
	int numOfConsOptr{};

	for (char i : expression)
	{
		if (MyCondition.checkIfCondition(j, i) && MyCondition.checkOptrAddSub(expression[posOfFor + 1]))
			numOfConsOptr++;

		posOfFor++;
	}

	return numOfConsOptr;
}

int Expression::calStringSize()
{
	resetPOF();
	int stringSize{ -1 };

	//find the size of the expression
	for (char i : expression)
		stringSize++;

	return stringSize;
}


/* set and find */
int Expression::setAndFind(int POForigin, int actAfterFor, int forMode, int ifmode)
{
	MyCondition.posOfFor = posOfFor;
	MyCondition.stringSize = stringSize;

	for (MyCondition.posOfFor = POForigin; MyCondition.checkForCondition(forMode); MyCondition.posOfFor += actAfterFor)
	{
		char i = expression[MyCondition.posOfFor];

		//make detecting the last number possible
		if (MyCondition.posOfFor == MyCondition.stringSize)
			return MyCondition.stringSize + 1;

		//detect whether it's at the beginning of the expression or not
		if (MyCondition.posOfFor == 0 && forMode == 2)
			return -1;

		if (MyCondition.checkIfCondition(ifmode, i))
			return MyCondition.posOfFor;
	}

	error();
	return 0;
}

std::string Expression::processOptr(std::string num1, std::string num2)
{
	std::string numResult;

	switch (expression[optr_1])
	{
	case '*':
		numResult = std::to_string(std::stod(num1) * std::stod(num2));
		break;

	case '/':
		numResult = std::to_string(std::stod(num1) / std::stod(num2));
		break;

	case '%':
		numResult = std::to_string(std::stoi(num1) % std::stoi(num2));
		break;

	case '^':
		numResult = std::to_string(pow(std::stod(num1), std::stod(num2)));
		break;

	default:
		error();
		break;
	}

	return numResult;
}

void Expression::optrAddSub(int optr_1a, int optr_2a, int mode)
{
	optr_2a = optr_1a;

	//find the position of next operator
	optr_1a = setAndFind(optr_2a, 1, 1, 2);
	optr_2a = setAndFind(optr_1a + 1, 1, 1, 2);

	if (mode == 0)
	{
		optr_1 = optr_1a;
		optr_2 = optr_2a;
	}
	else if (mode == 1)
	{
		optr_2 = optr_1a;
		optr_1 = optr_2a;
	}
}


/* addSubForLoop */
void Expression::forLoopAddSub(int optr_1a, int optr_2a, int mode)
{
	optrAddSub(optr_1a, optr_2a, mode);

	if (mode == 0)
	{
		optr_1a = optr_1;
		optr_2a = optr_2;
	}
	else if (mode == 1)
	{
		optr_2a = optr_1;
		optr_1a = optr_2;
	}

	//storing the current number as a string
	std::string num{ storeString(optr_1a, optr_2a) };

	//converting the number to integer and adding to result
	if (!num.empty())
	{
		if (expression[optr_1a] == '+')
			result += std::stod(num);
		else if (expression[optr_1a] == '-')
			result -= std::stod(num);
	}
}

int Expression::forLoopAddSubFormat(int optr_1a, int optr_2a, int mode, int consOptrDone)
{
	optrAddSub(optr_1a, optr_2a, mode);

	if (mode == 0)
	{
		optr_1a = optr_1;
		optr_2a = optr_2;
	}
	else if (mode == 1)
	{
		optr_2a = optr_1;
		optr_1a = optr_2;
	}

	if (optr_1a == optr_2a - 1)
	{
		storeExpCons(optr_1a, optr_2a);
		return consOptrDone + 1;
	}
	
	error();
	return 0;
}


/* evaluate */
void Expression::addSub()
{
	//formating the original expression by adding a sign
	if (expression[0] != '+' && expression[0] != '-')
		expression = '+' + expression;

	reset();
	numOfOptr = calNumOfOptr('+') + calNumOfOptr('-');
	stringSize = calStringSize();
	int j{};

	//for loop to undergo addition & subtraction
	for (optrDone; optrDone < numOfOptr; optrDone++)
	{
		if (j == 0)
		{
			forLoopAddSub(optr_1, optr_2, 0);
			j = 1;
		}
		else
		{
			forLoopAddSub(optr_2, optr_1, 1);
			j = 0;
		}
	}
}

void Expression::multDiv()
{
	reset();

	//find the number of '*' and '/' in the expression
	numOfOptr = calNumOfOptr('*') + calNumOfOptr('/') + calNumOfOptr('%');

	//skip function if neccessary
	if (numOfOptr == 0)
		return;

	for (optrDone = 0; optrDone < numOfOptr; optrDone++)
	{
		stringSize = calStringSize();

		//find the position of operator
		optr_1 = setAndFind(0, 1, 1, 3);

		//find the position of operator before
		optr_2 = setAndFind(optr_1 - 1, -1, 2, 1);

		//find the position of operator after
		optr_3 = setAndFind(optr_1 + 1, 1, 1, 1);

		//storing the numbers as string
		std::string num1, num2;
		num1 = storeString(optr_2, optr_1);
		num2 = storeString(optr_1, optr_3);

		//converting the numbers to integer and evaluate
		//then storing the result as a string
		std::string num3{ processOptr(num1, num2) };
		
		storeExp(optr_2, optr_3, num3);
	}
}

void Expression::orders()
{
	reset();
	numOfOptr = calNumOfOptr('^');

	if (numOfOptr == 0)
		return;

	for (optrDone = 0; optrDone < numOfOptr; optrDone++)
	{
		stringSize = calStringSize();

		optr_1 = setAndFind(0, 1, 1, 4);
		optr_2 = setAndFind(optr_1 - 1, -1, 2, 1);
		optr_3 = setAndFind(optr_1 + 1, 1, 1, 1);

		std::string num1, num2;
		num1 = storeString(optr_2, optr_1);
		num2 = storeString(optr_1, optr_3);

		std::string num3{ processOptr(num1, num2) };

		storeExp(optr_2, optr_3, num3);
	}
}