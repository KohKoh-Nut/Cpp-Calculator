#include "Brackets.h"

void Brackets::doBrackets()
{
	Variables::reset();
	Variables::numOfOptr = Count::calNumOfOptr('(');

	if (Variables::numOfOptr == 0)
		return;

	Variables::stringSize = Count::calStringSize();
	Variables::optr_1 = Expression::setAndFind(0, 1, 1, 5);
	Variables::optr_2 = Expression::setAndFind(Variables::optr_1 + 1, 1, 1, 6);

	for (; Variables::optrDone < Variables::numOfOptr;)
	{
		if (Variables::expression[Variables::optr_1] == '(' && Variables::expression[Variables::optr_2] == '(')
		{
			Variables::stringSize = Count::calStringSize();
			Variables::optr_1 = Variables::optr_2;
			Variables::optr_2 = Expression::setAndFind(Variables::optr_1 + 1, 1, 1, 6);
		}
		else if (Variables::expression[Variables::optr_1] == '(' && Variables::expression[Variables::optr_2] == ')')
		{
			std::string expression_brackets{ Variables::expression };
			int optr_1a{ Variables::optr_1 }, optr_2a{ Variables::optr_2 }, stringSizeAf{ Variables::stringSize };
			int optrDoneAf{ Variables::optrDone }, numOfOptrAf{ Variables::numOfOptr };

			Variables::expression = Store::storeExpBrac(Variables::optr_1, Variables::optr_2);

			Format::format();
			Orders::doOrders();
			MultDiv::multDiv();
			AddSub::doAddSub(1);

			Variables::expression = Store::storeExpBracAf(optr_1a, optr_2a, expression_brackets, stringSizeAf);
			Variables::optrDone = optrDoneAf + 1;
			Variables::numOfOptr = numOfOptrAf;

			if (Variables::optrDone != Variables::numOfOptr)
			{
				Variables::stringSize = Count::calStringSize();
				Variables::optr_1 = Expression::setAndFind(0, 1, 1, 5);
				Variables::optr_2 = Expression::setAndFind(Variables::optr_1 + 1, 1, 1, 6);
			}
		}
	}
}

