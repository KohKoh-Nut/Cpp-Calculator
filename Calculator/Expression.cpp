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

void Expression::getInput()
{
	std::cout << "Enter an expression: ";
	std::cin >> expression;
}

void Expression::format()
{
	int consOptrMultDivDone{}, numOfConsOptrMultDiv{ calNumOfConsOptrMultDiv() };
	stringSize = calStringSize();

	for (consOptrMultDivDone; consOptrMultDivDone < numOfConsOptrMultDiv; consOptrMultDivDone++)
	{
		for (char i : expression)
		{
			if (MyCondition.checkOptrMultDiv(i) && MyCondition.checkOptrAddSub(expression[posOfFor + 1]))
			{
				optr_1 = posOfFor;
				optr_2 = setAndFind(optr_1 - 1, -1, 2, 1);
				//detect whether it's at the beginning of the expression or not
				if (optr_2 == 0)
					optr_2 = -1;

				optr_3 = posOfFor + 1;

				storeExpressionConsMultDiv(optr_2, optr_3);
				break;
			}

			posOfFor++;
		}
	}

	int consOptrDone{}, numOfConsOptr{ calNumOfConsOptr() };
	int j{};

	//formatting the original expression by processing the consecutive signs
	for (consOptrDone; consOptrDone < numOfConsOptr;)
	{
		reset();
		stringSize = calStringSize();
		if (j == 0)
		{
			consOptrDone = formatAddSubFor(optr_1, optr_2, 0, consOptrDone);
			j = 1;
		}
		else if (j == 1)
		{
			consOptrDone = formatAddSubFor(optr_2, optr_1, 1, consOptrDone);
			j = 0;
		}
	}
}


/* store */
void Expression::storeExpression(int optr_bef, int optr_af, std::string num)
{
	//string to store the new expression after evaluation
	std::string expression_multDiv;
	
	//the process of storing the new expression
	for (posOfFor = 0; posOfFor <= optr_bef; posOfFor++)
		expression_multDiv += expression[posOfFor];

	expression_multDiv += num;

	for (posOfFor = optr_af; posOfFor <= stringSize; posOfFor++)
		expression_multDiv += expression[posOfFor];

	//putting the new expression back to expression for further evaluation
	expression = expression_multDiv;
}

void Expression::storeExpressionCons(int optr_bef, int optr_af)
{
	//string to store the new expression after evaluation
	std::string expression_cons;

	//the process of storing the new expression
	for (posOfFor = 0; posOfFor < optr_bef ; posOfFor++)
		expression_cons += expression[posOfFor];

	if(expression[optr_bef] == '-' && expression[optr_af] == '-')
		expression_cons += '+';
	else if (expression[optr_bef] == '+' && expression[optr_af] == '-')
		expression_cons += '-';
	else if (expression[optr_bef] == '-' && expression[optr_af] == '+')
		expression_cons += '-';
	else if (expression[optr_bef] == '+' && expression[optr_af] == '+')
		expression_cons += '+';

	for (posOfFor = optr_af + 1; posOfFor<= stringSize; posOfFor++)
		expression_cons += expression[posOfFor];

	//putting the new expression back to expression for further evaluation
	expression = expression_cons;
}

void Expression::storeExpressionConsMultDiv(int optr_bef, int optr_af)
{
	//string to store the new expression after evaluation
	std::string expression_consMultDiv;

	//the process of storing the new expression
	for (posOfFor = 0; posOfFor <= optr_bef; posOfFor++)
		expression_consMultDiv += expression[posOfFor];

	expression_consMultDiv += expression[optr_af];

	for (; posOfFor < optr_af; posOfFor++)
		expression_consMultDiv += expression[posOfFor];

	for (posOfFor = optr_af + 1; posOfFor <= stringSize; posOfFor++)
		expression_consMultDiv += expression[posOfFor];

	//putting the new expression back to expression for further evaluation
	expression = expression_consMultDiv;
}

std::string Expression::storeString(int optr_bef, int optr_af)
{
	std::string num;

	for (posOfFor = optr_bef + 1; posOfFor < optr_af || posOfFor == stringSize; posOfFor++)
		num += expression[posOfFor];

	return num;
}

double Expression::doubleConvert(std::string num)
{
	return double(std::stoi(num));
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

int Expression::calNumOfConsOptr()
{
	resetPOF();
	int numOfConsOptr{};

	for (char i : expression)
	{
		if (MyCondition.checkOptrAddSub(i) && MyCondition.checkOptrAddSub(expression[posOfFor + 1]))
			numOfConsOptr++;

		posOfFor++;
	}

	return numOfConsOptr;
}

int Expression::calNumOfConsOptrMultDiv()
{
	resetPOF();
	int numOfConsOptrMultDiv{};

	for (char i : expression)
	{
		if (MyCondition.checkOptrMultDiv(i) && MyCondition.checkOptrAddSub(expression[posOfFor + 1]))
			numOfConsOptrMultDiv++;

		posOfFor++;
	}

	return numOfConsOptrMultDiv;
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

		if (MyCondition.checkIfCondition(ifmode, i))
			return MyCondition.posOfFor;
	}

	return 0;
}

std::string Expression::processOptr(std::string num1, std::string num2)
{
	std::string numResult;

	switch (expression[optr_1])
	{
	case '*':
		numResult = std::to_string(doubleConvert(num1) * doubleConvert(num2));
		break;
	case '/':
		numResult = std::to_string(doubleConvert(num1) / doubleConvert(num2));
		break;
	case '%':
		numResult = std::to_string(std::stoi(num1) % std::stoi(num2));
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


/* addSubForLoop*/
void Expression::addSubFor(int optr_1a, int optr_2a, int mode)
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
			result += doubleConvert(num);
		else if (expression[optr_1a] == '-')
			result -= doubleConvert(num);
	}
}

int Expression::formatAddSubFor(int optr_1a, int optr_2a, int mode, int consOptrDone)
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
		storeExpressionCons(optr_1a, optr_2a);
		return consOptrDone + 1;
	}

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
			addSubFor(optr_1, optr_2, 0);
			j = 1;
		}
		else
		{
			addSubFor(optr_2, optr_1, 1);
			j = 0;
		}
	}
}

void Expression::multDiv()
{
	reset();

	//find the number of '*' and '/' in the expression
	numOfOptr = calNumOfOptr('*') + calNumOfOptr('/') + calNumOfOptr('%') + calNumOfOptr('^');

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

		//detect whether it's at the beginning of the expression or not
		if (optr_2 == 0)
			optr_2 = -1;

		//find the position of operator after
		optr_3 = setAndFind(optr_1 + 1, 1, 1, 1);

		//storing the numbers as string
		std::string num1, num2;
		num1 = storeString(optr_2, optr_1);
		num2 = storeString(optr_1, optr_3);

		//converting the numbers to integer and evaluate
		//then storing the result as a string
		std::string num3{ processOptr(num1, num2) };
		
		storeExpression(optr_2, optr_3, num3);
	}
}