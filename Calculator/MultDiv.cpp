#include "MultDiv.h"
#include "Variables.h"

void MultDiv::multDiv()
{
	MyVariables.reset();

	//find the number of '*' and '/' in the expression
	MyVariables.numOfOptr = MyVariables.MyCount.calNumOfOptr('*') + MyVariables.MyCount.calNumOfOptr('/') + MyVariables.MyCount.calNumOfOptr('%');

	//skip function if neccessary
	if (MyVariables.numOfOptr == 0)
		return;

	for (MyVariables.optrDone = 0; MyVariables.optrDone < MyVariables.numOfOptr; MyVariables.optrDone++)
	{
		MyVariables.stringSize = MyVariables.MyCount.calStringSize();

		//find the position of operator
		MyVariables.optr_1 = MyVariables.MyExpression.setAndFind(0, 1, 1, 3);

		//find the position of operator before
		MyVariables.optr_2 = MyVariables.MyExpression.setAndFind(MyVariables.optr_1 - 1, -1, 2, 1);

		//find the position of operator after
		MyVariables.optr_3 = MyVariables.MyExpression.setAndFind(MyVariables.optr_1 + 1, 1, 1, 1);

		//storing the numbers as string
		std::string num1, num2;
		num1 = MyVariables.MyStore.storeString(MyVariables.optr_2, MyVariables.optr_1);
		num2 = MyVariables.MyStore.storeString(MyVariables.optr_1, MyVariables.optr_3);

		//converting the numbers to integer and evaluate
		//then storing the result as a string
		std::string num3{ MyVariables.MyExpression.processOptr(num1, num2) };

		MyVariables.MyStore.storeExp(MyVariables.optr_2, MyVariables.optr_3, num3);
	}
}