#include "Format.h"
#include "Variables.h"

void Format::format()
{
	/* format front brackets */

	int consOptrBracFroDone{}, numOfConsOptrFroBrac{ MyVariables.MyCount.calNumOfBracFroOptr() };
	MyVariables.stringSize = MyVariables.MyCount.calStringSize();

	for (; consOptrBracFroDone < numOfConsOptrFroBrac; consOptrBracFroDone++)
	{
		for (char i : MyVariables.expression)
		{
			if (!MyVariables.MyCondition.checkIfCondition(1, i) && !MyVariables.MyCondition.checkIfCondition(5, i) && MyVariables.MyCondition.checkIfCondition(5, MyVariables.expression[MyVariables.posOfFor + 1]))
			{
				MyVariables.optr_1 = MyVariables.posOfFor;
				MyVariables.optr_2 = MyVariables.posOfFor + 1;

				int posOfForA{ MyVariables.posOfFor };
				MyVariables.MyStore.storeExpBracOptr(MyVariables.optr_1, MyVariables.optr_2);
				MyVariables.posOfFor = posOfForA;
				break;
			}
			else if (MyVariables.MyCondition.checkIfCondition(5, i) && MyVariables.MyCondition.checkIfCondition(5, MyVariables.expression[MyVariables.posOfFor + 1]))
			{
				MyVariables.optr_1 = MyVariables.posOfFor;
				MyVariables.optr_2 = MyVariables.posOfFor + 1;

				int posOfForA{ MyVariables.posOfFor };
				MyVariables.MyStore.storeExpConsBracOptr(MyVariables.optr_1, MyVariables.optr_2, 0);
				MyVariables.posOfFor = posOfForA;
				break;
			}

			MyVariables.posOfFor++;
		}
	}

	/* format back brackets */

	int consOptrBracBacDone{}, numOfConsOptrBacBrac{ MyVariables.MyCount.calNumOfBracBacOptr() };
	MyVariables.stringSize = MyVariables.MyCount.calStringSize();

	for (; consOptrBracBacDone < numOfConsOptrBacBrac; consOptrBracBacDone++)
	{
		for (char i : MyVariables.expression)
		{
			if (MyVariables.MyCondition.checkIfCondition(7, i) && !MyVariables.MyCondition.checkIfCondition(1, MyVariables.expression[MyVariables.posOfFor + 1]) && !MyVariables.MyCondition.checkIfCondition(7, MyVariables.expression[MyVariables.posOfFor + 1]))
			{
				MyVariables.optr_1 = MyVariables.posOfFor;
				MyVariables.optr_2 = MyVariables.posOfFor + 1;

				int posOfForA{ MyVariables.posOfFor };
				MyVariables.MyStore.storeExpBracOptr(MyVariables.optr_1, MyVariables.optr_2);
				MyVariables.posOfFor = posOfForA;
				break;
			}
			else if (MyVariables.MyCondition.checkIfCondition(7, i) && MyVariables.MyCondition.checkIfCondition(7, MyVariables.expression[MyVariables.posOfFor + 1]))
			{
				MyVariables.optr_1 = MyVariables.posOfFor;
				MyVariables.optr_2 = MyVariables.posOfFor + 1;

				int posOfForA{ MyVariables.posOfFor };
				MyVariables.MyStore.storeExpConsBracOptr(MyVariables.optr_1, MyVariables.optr_2, 1);
				MyVariables.posOfFor = posOfForA;
				break;
			}

			MyVariables.posOfFor++;
		}
	}

	/* format the signs after * and / */

	int consOptrMultDivDone{}, numOfConsOptrMultDiv{ MyVariables.MyCount.calNumOfConsOptr(3) };
	MyVariables.stringSize = MyVariables.MyCount.calStringSize();

	for (; consOptrMultDivDone < numOfConsOptrMultDiv; consOptrMultDivDone++)
	{
		for (char i : MyVariables.expression)
		{
			if (MyVariables.MyCondition.checkIfCondition(3, i) && MyVariables.MyCondition.checkIfCondition(2, MyVariables.expression[MyVariables.posOfFor + 1]))
			{
				MyVariables.optr_1 = MyVariables.posOfFor;
				MyVariables.optr_2 = MyVariables.MyExpression.setAndFind(MyVariables.optr_1 - 1, -1, 2, 1);
				MyVariables.optr_3 = MyVariables.posOfFor + 1;

				MyVariables.MyStore.storeExpConsMultDivOrders(MyVariables.optr_2, MyVariables.optr_3, 0);
				break;
			}

			MyVariables.posOfFor++;
		}
	}

	int consOptrDone{}, numOfConsOptr{ MyVariables.MyCount.calNumOfConsOptr(2) };
	int j{};

	/* formatting the original expression by processing the consecutive signs */
	for (; consOptrDone < numOfConsOptr;)
	{
		MyVariables.reset();
		MyVariables.stringSize = MyVariables.MyCount.calStringSize();
		if (j == 0)
		{
			consOptrDone = forLoopAddSubFormat(MyVariables.optr_1, MyVariables.optr_2, 0, consOptrDone);
			j = 1;
		}
		else if (j == 1)
		{
			consOptrDone = forLoopAddSubFormat(MyVariables.optr_2, MyVariables.optr_1, 1, consOptrDone);
			j = 0;
		}
	}

	int consOptrOrdersDone{}, numOfConsOptrOrders{ MyVariables.MyCount.calNumOfConsOptr(4) };
	MyVariables.stringSize = MyVariables.MyCount.calStringSize();

	/* format the signs after ^ */
	for (; consOptrOrdersDone < numOfConsOptrOrders; consOptrOrdersDone++)
	{
		for (char i : MyVariables.expression)
		{
			if (MyVariables.MyCondition.checkIfCondition(4, i) && MyVariables.MyCondition.checkIfCondition(2, MyVariables.expression[MyVariables.posOfFor + 1]))
			{
				MyVariables.optr_1 = MyVariables.posOfFor;
				MyVariables.optr_2 = MyVariables.MyExpression.setAndFind(MyVariables.optr_1 - 1, -1, 2, 1);
				MyVariables.optr_3 = MyVariables.posOfFor + 1;

				MyVariables.MyStore.storeExpConsMultDivOrders(MyVariables.optr_2, MyVariables.optr_3, 1);
				break;
			}

			MyVariables.posOfFor++;
		}
	}
}

int Format::forLoopAddSubFormat(int optr_1a, int optr_2a, int mode, int consOptrDone)
{
	MyVariables.MyAddSub.optrAddSub(optr_1a, optr_2a, mode);

	if (mode == 0)
	{
		optr_1a = MyVariables.optr_1;
		optr_2a = MyVariables.optr_2;
	}
	else if (mode == 1)
	{
		optr_2a = MyVariables.optr_1;
		optr_1a = MyVariables.optr_2;
	}

	if (optr_1a == optr_2a - 1)
	{
		MyVariables.MyStore.storeExpCons(optr_1a, optr_2a);
		return consOptrDone + 1;
	}

	MyVariables.MyIOError.error();
	return 0;
}