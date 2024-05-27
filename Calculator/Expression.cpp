#include "Expression.h"
#include <string>
#include <iostream>

//the definition of the expression
void Expression::getInput()
{
	std::cout << "Enter an expression: ";
	std::cin >> expression;
}

void Expression::additionSubtraction()
{
	//formating the original expression by adding a sign
	if (expression[0] != '+' && expression[0] != '-')
		expression = '+' + expression;
		 
	//number of operator in the expression, current position of the for-each loop, operator done calculating
	int numOfOptr{}, posOfFor{}, optrDone{};
	int stringSize{ -1 };

	//find the size of the expression
	//find the number of '+' and '-' in the expression
	for (char i : expression)
	{
		stringSize++;

		if (i == '+' || i == '-')
			numOfOptr++;

		posOfFor++;
	}

	//position of operators
	int optr_1{}, optr_2{};

	//determine whether it's the first for loop or not
	int firstOrNot{};
	int j{};

	//for loop to undergo addition & subtraction
	for (optrDone; optrDone < numOfOptr; optrDone++)
	{
		if (j == 0)
		{
			firstOrNot = 0;

			//for loop to find the position of operator
			for (posOfFor = optr_2 + firstOrNot; posOfFor < stringSize; posOfFor++)
			{
				char i = expression[posOfFor];

				if ((i == '+' || i == '-'))
				{
					optr_1 = posOfFor;
					break;
				}
			}

			firstOrNot = 1;

			//for loop to find the position of next operator
			for (posOfFor = optr_1 + firstOrNot; posOfFor < stringSize; posOfFor++)
			{
				char i = expression[posOfFor];

				if ((i == '+' || i == '-'))
				{
					optr_2 = posOfFor;
					break;
				}
			}

			//make detecting the last number possible
			if (posOfFor == stringSize)
				optr_2 = stringSize;

			//string to store the current number being converted from string
			std::string num;

			//storing the current number as a string
			for (posOfFor = optr_1 + firstOrNot; posOfFor < optr_2 || posOfFor == stringSize; posOfFor++)
				num += expression[posOfFor];

			//converting the number to integer and adding to result
			if(!num.empty())
			{
				if (expression[optr_1] == '+')
					result += std::stoi(num);
				else if (expression[optr_1] == '-')
					result -= std::stoi(num);
			}

			j = 1;
			optr_1 = optr_2;
		}
		else
		{
			firstOrNot = 0;

			for (posOfFor = optr_1 + firstOrNot; posOfFor < stringSize; posOfFor++)
			{
				char i = expression[posOfFor];

				if ((i == '+' || i == '-'))
				{
					optr_2 = posOfFor;
					break;
				}
			}

			firstOrNot = 1;

			for (posOfFor = optr_2 + firstOrNot; posOfFor < stringSize; posOfFor++)
			{
				char i = expression[posOfFor];

				if ((i == '+' || i == '-'))
				{
					optr_1 = posOfFor;
					break;
				}
			}

			if (posOfFor == stringSize)
				optr_1 = stringSize;

			std::string num;

			for (posOfFor = optr_2 + firstOrNot; posOfFor < optr_1 || posOfFor == stringSize; posOfFor++)
				num += expression[posOfFor];

			if (!num.empty())
			{
				if (expression[optr_2] == '+')
					result += std::stoi(num);
				else if (expression[optr_2] == '-')
					result -= std::stoi(num);
			}

			j = 0;
			optr_2 = optr_1;
		}
	}
}