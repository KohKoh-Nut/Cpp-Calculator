#include "Format.h"

void Format::setOptr()
{
	Variables::optr_1 = Variables::posOfFor;
	Variables::optr_2 = Variables::posOfFor + 1;
}

void Format::format()
{
	/* format front brackets */

	int consOptrBracFroDone{}, numOfConsOptrFroBrac{ Count::calNumOfBracFroOptr() };
	Count::calStringSize();

	for (; consOptrBracFroDone < numOfConsOptrFroBrac; consOptrBracFroDone++)
	{
		for (char i : Variables::expression)
		{
			//if it's ^ followed by a front brackets
			if (Condition::checkIfCondition(4, i) && Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormBracOrders(Variables::optr_1, Variables::optr_2);
				Variables::posOfFor = posOfForA;
				break;
			}

			//if it's anything except for operators followed by a front bracket
			if (!Condition::checkIfCondition(1, i) && !Condition::checkIfCondition(5, i) && Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormBracOptr(Variables::optr_1, Variables::optr_2);
				Variables::posOfFor = posOfForA;
				break;
			}

			//if it's two consecutive front brackets
			if (Condition::checkIfCondition(5, i) && Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormConsBrac(Variables::optr_1, Variables::optr_2, 0);
				Variables::posOfFor = posOfForA;
				break;
			}

			Variables::posOfFor++;
		}
	}

	/* format back brackets */

	int consOptrBracBacDone{}, numOfConsOptrBacBrac{ Count::calNumOfBracBacOptr() };
	Count::calStringSize();

	for (; consOptrBracBacDone < numOfConsOptrBacBrac; consOptrBracBacDone++)
	{
		for (char i : Variables::expression)
		{
			//if it's a back bracket followed by anything except for operators 
			if (Condition::checkIfCondition(7, i) && !Condition::checkIfCondition(1, Variables::expression[Variables::posOfFor + 1]) && !Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormBracOptr(Variables::optr_1, Variables::optr_2);
				Variables::posOfFor = posOfForA;
				break;
			}
			
			//if it's two consecutive back brackets
			if (Condition::checkIfCondition(7, i) && Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormConsBrac(Variables::optr_1, Variables::optr_2, 1);
				Variables::posOfFor = posOfForA;
				break;
			}

			Variables::posOfFor++;
		}
	}

	/* format the signs after * and / */

	int consOptrMultDivDone{}, numOfConsOptrMultDiv{ Count::calNumOfConsOptr(3) };

	do
	{
		Count::calStringSize();

		for (; consOptrMultDivDone < numOfConsOptrMultDiv; consOptrMultDivDone++)
		{
			for (; Condition::checkForCondition(1); Variables::posOfFor++)
			{
				if (Condition::checkIfCondition(3, Variables::expression[Variables::posOfFor]) && Condition::checkIfCondition(2, Variables::expression[Variables::posOfFor + 1]))
				{
					Variables::optr_1 = Variables::posOfFor;
					Variables::optr_3 = Variables::posOfFor + 1;
					Variables::optr_2 = Expression::find(Variables::optr_1 - 1, -1, 2, 1);

					int posOfForA{ Variables::posOfFor };
					Store::storeExpFormConsMultDivOrders(Variables::optr_2, Variables::optr_3, 0);
					Variables::posOfFor = posOfForA;
					break;
				}
			}
		}

		numOfConsOptrMultDiv = Count::calNumOfConsOptr(3);
		consOptrMultDivDone = 0;
	} 
	while (numOfConsOptrMultDiv != 0);

	/* formatting the original expression by processing the consecutive signs */

	int consOptrDone{}, numOfConsOptr{ Count::calNumOfConsOptr(2) };
	int j{};

	for (; consOptrDone < numOfConsOptr;)
	{
		Variables::resetPOF();
		Count::calStringSize();
		if (j == 0)
		{
			consOptrDone = forLoopAddSubFormat(Variables::optr_1, Variables::optr_2, 0, consOptrDone);

			Variables::optr_1 = Variables::optr_2;
			j = 1;
		}
		else if (j == 1)
		{
			consOptrDone = forLoopAddSubFormat(Variables::optr_2, Variables::optr_1, 1, consOptrDone);
			j = 0;
			Variables::optr_2 = Variables::optr_1;
		}
	}

	/* format the signs after ^ */

	int consOptrOrdersDone{}, numOfConsOptrOrders{ Count::calNumOfConsOptr(4) };
	Count::calStringSize();

	for (; consOptrOrdersDone < numOfConsOptrOrders; consOptrOrdersDone++)
	{
		for (; Condition::checkForCondition(1); Variables::posOfFor++)
		{
			if (Condition::checkIfCondition(4, Variables::expression[Variables::posOfFor]) && Condition::checkIfCondition(2, Variables::expression[Variables::posOfFor + 1]))
			{
				Variables::optr_1 = Variables::posOfFor;
				Variables::optr_3 = Variables::posOfFor + 1;
				Variables::optr_2 = Expression::find(Variables::optr_1 - 1, -1, 2, 1);

				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormConsMultDivOrders(Variables::optr_2, Variables::optr_3, 1);
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
		Store::storeExpFormConsNegatives(optr_1a, optr_2a);
		return consOptrDone + 1;
	}

	return consOptrDone;
}