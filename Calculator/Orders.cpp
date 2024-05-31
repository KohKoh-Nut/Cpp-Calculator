#include "Orders.h"
#include "Variables.h"

void Orders::doOrders()
{
	MyVariables.reset();
	MyVariables.numOfOptr = MyVariables.MyCount.calNumOfOptr('^');

	if (MyVariables.numOfOptr == 0)
		return;

	for (MyVariables.optrDone = 0; MyVariables.optrDone < MyVariables.numOfOptr; MyVariables.optrDone++)
	{
		MyVariables.stringSize = MyVariables.MyCount.calStringSize();

		MyVariables.optr_1 = MyVariables.MyExpression.setAndFind(0, 1, 1, 4);
		MyVariables.optr_2 = MyVariables.MyExpression.setAndFind(MyVariables.optr_1 - 1, -1, 2, 1);
		MyVariables.optr_3 = MyVariables.MyExpression.setAndFind(MyVariables.optr_1 + 1, 1, 1, 1);

		std::string num1, num2;
		num1 = MyVariables.MyStore.storeString(MyVariables.optr_2, MyVariables.optr_1);
		num2 = MyVariables.MyStore.storeString(MyVariables.optr_1, MyVariables.optr_3);

		std::string num3{ MyVariables.MyExpression.processOptr(num1, num2) };

		MyVariables.MyStore.storeExp(MyVariables.optr_2, MyVariables.optr_3, num3);
	}
}