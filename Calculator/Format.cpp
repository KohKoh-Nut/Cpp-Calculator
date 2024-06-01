#include "Format.h"

void Format::format()
{
	/* format front brackets */

	int consOptrBracFroDone{}, numOfConsOptrFroBrac{ Count::calNumOfBracFroOptr() };
	Variables::stringSize = Count::calStringSize();

	for (; consOptrBracFroDone < numOfConsOptrFroBrac; consOptrBracFroDone++)
	{
		for (char i : Variables::expression)
		{
			if (!Condition::checkIfCondition(1, i) && !Condition::checkIfCondition(5, i) && Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			{
				Variables::optr_1 = Variables::posOfFor;
				Variables::optr_2 = Variables::posOfFor + 1;

				int posOfForA{ Variables::posOfFor };
				Store::storeExpBracOptr(Variables::optr_1, Variables::optr_2);
				Variables::posOfFor = posOfForA;
				break;
			}
			else if (Condition::checkIfCondition(5, i) && Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			{
				Variables::optr_1 = Variables::posOfFor;
				Variables::optr_2 = Variables::posOfFor + 1;

				int posOfForA{ Variables::posOfFor };
				Store::storeExpConsBracOptr(Variables::optr_1, Variables::optr_2, 0);
				Variables::posOfFor = posOfForA;
				break;
			}

			Variables::posOfFor++;
		}
	}

	/* format back brackets */

	int consOptrBracBacDone{}, numOfConsOptrBacBrac{ Count::calNumOfBracBacOptr() };
	Variables::stringSize = Count::calStringSize();

	for (; consOptrBracBacDone < numOfConsOptrBacBrac; consOptrBracBacDone++)
	{
		for (char i : Variables::expression)
		{
			if (Condition::checkIfCondition(7, i) && !Condition::checkIfCondition(1, Variables::expression[Variables::posOfFor + 1]) && !Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor + 1]))
			{
				Variables::optr_1 = Variables::posOfFor;
				Variables::optr_2 = Variables::posOfFor + 1;

				int posOfForA{ Variables::posOfFor };
				Store::storeExpBracOptr(Variables::optr_1, Variables::optr_2);
				Variables::posOfFor = posOfForA;
				break;
			}
			else if (Condition::checkIfCondition(7, i) && Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor + 1]))
			{
				Variables::optr_1 = Variables::posOfFor;
				Variables::optr_2 = Variables::posOfFor + 1;

				int posOfForA{ Variables::posOfFor };
				Store::storeExpConsBracOptr(Variables::optr_1, Variables::optr_2, 1);
				Variables::posOfFor = posOfForA;
				break;
			}

			Variables::posOfFor++;
		}
	}

	/* format the signs after * and / */

	int consOptrMultDivDone{}, numOfConsOptrMultDiv{ Count::calNumOfConsOptr(3) };
	Variables::stringSize = Count::calStringSize();

	for (; consOptrMultDivDone < numOfConsOptrMultDiv; consOptrMultDivDone++)
	{
		for (; Condition::checkForCondition(1); Variables::posOfFor++)
		{
			if (Condition::checkIfCondition(3, Variables::expression[Variables::posOfFor]) && Condition::checkIfCondition(2, Variables::expression[Variables::posOfFor + 1]))
			{
				Variables::optr_1 = Variables::posOfFor;
				Variables::optr_3 = Variables::posOfFor + 1;
				Variables::optr_2 = Expression::setAndFind(Variables::optr_1 - 1, -1, 2, 1);

				int posOfForA{ Variables::posOfFor };
				Store::storeExpConsMultDivOrders(Variables::optr_2, Variables::optr_3, 0);
				Variables::posOfFor = posOfForA;
				break;
			}
		}
	}

	/* formatting the original expression by processing the consecutive signs */

	int consOptrDone{}, numOfConsOptr{ Count::calNumOfConsOptr(2) };
	int j{};

	Variables::reset();

	for (; consOptrDone < numOfConsOptr;)
	{
		Variables::resetPOF();
		Variables::stringSize = Count::calStringSize();
		if (j == 0)
		{
			consOptrDone = forLoopAddSubFormat(Variables::optr_1, Variables::optr_2, 0, consOptrDone);
			j = 1;
		}
		else if (j == 1)
		{
			consOptrDone = forLoopAddSubFormat(Variables::optr_2, Variables::optr_1, 1, consOptrDone);
			j = 0;
		}
	}

	/* format the signs after ^ */

	int consOptrOrdersDone{}, numOfConsOptrOrders{ Count::calNumOfConsOptr(4) };
	Variables::stringSize = Count::calStringSize();

	for (; consOptrOrdersDone < numOfConsOptrOrders; consOptrOrdersDone++)
	{
		for (; Condition::checkForCondition(1); Variables::posOfFor++)
		{
			if (Condition::checkIfCondition(4, Variables::expression[Variables::posOfFor]) && Condition::checkIfCondition(2, Variables::expression[Variables::posOfFor + 1]))
			{
				Variables::optr_1 = Variables::posOfFor;
				Variables::optr_3 = Variables::posOfFor + 1;
				Variables::optr_2 = Expression::setAndFind(Variables::optr_1 - 1, -1, 2, 1);

				int posOfForA{ Variables::posOfFor };
				Store::storeExpConsMultDivOrders(Variables::optr_2, Variables::optr_3, 1);
				Variables::posOfFor = posOfForA;
				break;
			}
		}
	}
}

int Format::forLoopAddSubFormat(int optr_1a, int optr_2a, int mode, int consOptrDone)
{
	AddSub::optrAddSub(optr_1a, optr_2a, mode);

	if (mode == 0)
	{
		optr_1a = Variables::optr_1;
		optr_2a = Variables::optr_2;
	}
	else if (mode == 1)
	{
		optr_2a = Variables::optr_1;
		optr_1a = Variables::optr_2;
	}

	if (optr_1a == optr_2a - 1)
	{
		Store::storeExpCons(optr_1a, optr_2a);
		return consOptrDone + 1;
	}

	return consOptrDone;
}