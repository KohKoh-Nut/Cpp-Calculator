#include "Orders.h"

void Orders::doOrders()
{
	Variables::reset();
	Variables::numOfOptr = Count::calNumOfOptr('^');

	if (Variables::numOfOptr == 0)
		return;

	for (Variables::optrDone = 0; Variables::optrDone < Variables::numOfOptr; Variables::optrDone++)
	{
		Count::calStringSize();

		Variables::optr_1 = Expression::find(0, 1, 1, 4);
		Variables::optr_2 = Expression::find(Variables::optr_1 - 1, -1, 2, 1);
		Variables::optr_3 = Expression::find(Variables::optr_1 + 1, 1, 1, 1);

		std::string num1, num2;
		num1 = Store::storeString(Variables::optr_2, Variables::optr_1);
		num2 = Store::storeString(Variables::optr_1, Variables::optr_3);

		std::string num3{ Expression::processOptr(num1, num2) };

		Store::storeExp(Variables::optr_2, Variables::optr_3, num3);
	}
}