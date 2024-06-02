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

		//find the positions of operator
		Expression::findMultDivOrders(4);

		//store the expression after the numbers being evaluated
		Store::storeEvaStrings();
	}
}