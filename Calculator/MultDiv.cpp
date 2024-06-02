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
		Count::calStringSize();
		
		//find the positions of operator
		Expression::findMultDivOrders(3);

		//store the expression after the numbers being evaluated
		Store::storeMultDivOrders();
	}
}