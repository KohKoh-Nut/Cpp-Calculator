#include "Expression.h"
#include "Condition.h"
#include <string>
#include <iostream>

void Expression::getInput()
{
	std::cout << "Enter an expression: ";
	std::cin >> expression;
}

void Expression::storeExpression(int optr_bef, int optr_af, int stringSize, std::string num)
{
	//current position of the for-each loop
	int posOfFor;

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

void Expression::storeExpressionNeg(int optr_bef, int optr_af, int stringSize)
{
	//current position of the for-each loop
	int posOfFor;

	//string to store the new expression after evaluation
	std::string expression_neg;

	//the process of storing the new expression
	for (posOfFor = 0; posOfFor < optr_bef ; posOfFor++)
		expression_neg += expression[posOfFor];

	if(expression[optr_bef] == '-' && expression[optr_af] == '-')
		expression_neg += '+';
	else if (expression[optr_bef] == '+' && expression[optr_af] == '-')
		expression_neg += '-';
	else if (expression[optr_bef] == '-' && expression[optr_af] == '+')
		expression_neg += '-';
	else if (expression[optr_bef] == '+' && expression[optr_af] == '+')
		expression_neg += '+';

	for (posOfFor = optr_af + 1; posOfFor<= stringSize; posOfFor++)
		expression_neg += expression[posOfFor];

	//putting the new expression back to expression for further evaluation
	expression = expression_neg;
}

std::string Expression::storeString(int optr_bef, int optr_af, int stringSize)
{
	int posOfFor{};
	std::string num;

	for (posOfFor = optr_bef + 1; posOfFor < optr_af || posOfFor == stringSize; posOfFor++)
		num += expression[posOfFor];

	return num;
}

int Expression::calNumOfOptr(char optr)
{
	int posOfFor{}, numOfOptr{};

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
	int posOfFor{}, numOfConsOptr{};

	for (char i : expression)
	{
		if (MyCondition.checkOptrAddSub(i) && MyCondition.checkOptrAddSub(expression[posOfFor + 1]))
			numOfConsOptr++;

		posOfFor++;
	}

	return numOfConsOptr;
}

int Expression::calStringSize()
{
	int stringSize{ -1 };

	//find the size of the expression
	for (char i : expression)
		stringSize++;

	return stringSize;
}

int Expression::findPosOfOptr(int POForigin, int actAfterFor, int forMode, int ifmode)
{
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

void Expression::setMyCondition(int posOfFor, int stringSize)
{
	MyCondition.posOfFor = posOfFor;
	MyCondition.stringSize = stringSize;
}

void Expression::addSub()
{
	//formating the original expression by adding a sign
	if (expression[0] != '+' && expression[0] != '-')
		expression = '+' + expression;

	//current position of the for-each loop
	int posOfFor{}, stringSize{ calStringSize() };
	int consOptrDone{}, numOfConsOptr{ calNumOfConsOptr() };
	int optr_1{}, optr_2{}; //position of operators
	int j{};

	//formatting the original expression by processing the consecutive signs
	for(consOptrDone; consOptrDone < numOfConsOptr;)
	{
		if (j == 0)
		{
			optr_2 = optr_1;
			optr_2 = setAndFind(posOfFor, stringSize, optr_1 + 1, 1, 1, 2);

			if (optr_1 == optr_2 - 1)
			{
				storeExpressionNeg(optr_1, optr_2, stringSize);
				consOptrDone++;
			}

			j = 1;
		}
		else if (j ==1)
		{
			optr_1 = optr_2;
			optr_1 = setAndFind(posOfFor, stringSize, optr_2 + 1, 1, 1, 2);

			if (optr_2 == optr_1 - 1)
			{
				storeExpressionNeg(optr_2, optr_1, stringSize);
				consOptrDone++;
			}

			j = 0;
		}
	}

	//number of operator done calculating, number of operator
	int optrDone{}, numOfOptr{ calNumOfOptr('+') + calNumOfOptr('-') };

	stringSize = calStringSize();
	optr_1 = 0, optr_2 = 0, posOfFor = 0;
	j = 0;

	//for loop to undergo addition & subtraction
	for (optrDone; optrDone < numOfOptr; optrDone++)
	{
		if (j == 0)
		{
			optr_2 = optr_1;

			//find the position of next operator
			optr_2 = setAndFind(posOfFor, stringSize, optr_1 + 1, 1, 1, 2);

			//storing the current number as a string
			std::string num{ storeString(optr_1, optr_2, stringSize) };
			
			//converting the number to integer and adding to result
			if(!num.empty())
			{
				if (expression[optr_1] == '+')
					result += std::stoi(num);
				else if (expression[optr_1] == '-')
					result -= std::stoi(num);
			}

			j = 1;
		}
		else
		{
			optr_1 = optr_2;
			optr_1 = setAndFind(posOfFor, stringSize, optr_2 + 1, 1, 1, 2);

			std::string num{ storeString(optr_2, optr_1, stringSize) };
			
			if (!num.empty())
			{
				if (expression[optr_2] == '+')
					result += std::stoi(num);
				else if (expression[optr_2] == '-')
					result -= std::stoi(num);
			}

			j = 0;
		}
	}
}

void Expression::multDiv()
{
	//number of operator in the expression, current position of the for-each loop, operator done calculating
	int numOfOptr{}, posOfFor{}, optrDone{};

	//find the number of '*' and '/' in the expression
	numOfOptr = calNumOfOptr('*') + calNumOfOptr('/') + calNumOfOptr('%');

	if (numOfOptr == 0)
		return;

	for (optrDone = 0; optrDone < numOfOptr; optrDone++)
	{
		int stringSize{ calStringSize() };

		//position of operators
		int optr_1{}, optr_2{}, optr_3{};

		//find the position of operator
		optr_1 = setAndFind(posOfFor, stringSize, 0, 1, 1, 3);

		//find the position of operator before
		optr_2 = setAndFind(posOfFor, stringSize, optr_1 - 1, -1, 2, 1);

		//detect whether it's at the beginning of the expression or not
		if (optr_2 == 0)
			optr_2 = -1;

		//find the position of operator after
		optr_3 = setAndFind(posOfFor, stringSize, optr_1 + 1, 1, 1, 1);

		//storing the numbers as string
		std::string num1, num2;
		num1 = storeString(optr_2, optr_1, stringSize);
		num2 = storeString(optr_1, optr_3, stringSize);

		//converting the numbers to integer and evaluate
		//then storing the result as a string
		std::string num3;
		if (expression[optr_1] == '*')
			num3 = std::to_string(std::stoi(num1) * std::stoi(num2));
		else if (expression[optr_1] == '/')
			num3 = std::to_string(std::stoi(num1) / std::stoi(num2));
		else if (expression[optr_1] == '%')
			num3 = std::to_string(std::stoi(num1) % std::stoi(num2));

		storeExpression(optr_2, optr_3, stringSize, num3);
	}
}