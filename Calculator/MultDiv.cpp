#include "MultDiv.h"

void MultDiv::multDiv()
{
	Variables::reset();

	//find the number of '*' and '/' in the expression
	Variables::numOfOptr = Count::calNumOfOptr('*') + Count::calNumOfOptr('/') + Count::calNumOfOptr('%');

	//skip function if neccessary
	if (Variables::numOfOptr == 0)
		return;

	for (Variables::optrDone = 0; Variables::optrDone < Variables::numOfOptr; Variables::optrDone++)
	{
		Variables::stringSize = Count::calStringSize();

		//find the position of operator
		Variables::optr_1 = Expression::setAndFind(0, 1, 1, 3);

		//find the position of operator before
		Variables::optr_2 = Expression::setAndFind(Variables::optr_1 - 1, -1, 2, 1);

		//find the position of operator after
		Variables::optr_3 = Expression::setAndFind(Variables::optr_1 + 1, 1, 1, 1);

		//storing the numbers as string
		std::string num1, num2;
		num1 = Store::storeString(Variables::optr_2, Variables::optr_1);
		num2 = Store::storeString(Variables::optr_1, Variables::optr_3);

		//converting the numbers to integer and evaluate
		//then storing the result as a string
		std::string num3{ Expression::processOptr(num1, num2) };

		Store::storeExp(Variables::optr_2, Variables::optr_3, num3);
	}
}