#include "Brackets.h"
#include "Variables.h"

void Brackets::doBrackets()
{
	MyVariables.reset();
	MyVariables.numOfOptr = MyVariables.MyCount.calNumOfOptr('(');

	if (MyVariables.numOfOptr == 0)
		return;

	MyVariables.stringSize = MyVariables.MyCount.calStringSize();
	MyVariables.optr_1 = MyVariables.MyExpression.setAndFind(0, 1, 1, 5);
	MyVariables.optr_2 = MyVariables.MyExpression.setAndFind(MyVariables.optr_1 + 1, 1, 1, 6);

	for (; MyVariables.optrDone < MyVariables.numOfOptr;)
	{
		if (MyVariables.expression[MyVariables.optr_1] == '(' && MyVariables.expression[MyVariables.optr_2] == '(')
		{
			MyVariables.stringSize = MyVariables.MyCount.calStringSize();
			MyVariables.optr_1 = MyVariables.optr_2;
			MyVariables.optr_2 = MyVariables.MyExpression.setAndFind(MyVariables.optr_1 + 1, 1, 1, 6);
		}
		else if (MyVariables.expression[MyVariables.optr_1] == '(' && MyVariables.expression[MyVariables.optr_2] == ')')
		{
			std::string expression_brackets{ MyVariables.expression };
			int optr_1a{ MyVariables.optr_1 }, optr_2a{ MyVariables.optr_2 }, stringSizeAf{ MyVariables.stringSize };
			int optrDoneAf{ MyVariables.optrDone }, numOfOptrAf{ MyVariables.numOfOptr };

			MyVariables.expression = MyVariables.MyStore.storeExpBrac(MyVariables.optr_1, MyVariables.optr_2);

			MyVariables.MyFormat.format();
			MyVariables.MyOrders.doOrders();
			MyVariables.MyMultDiv.multDiv();
			MyVariables.MyAddSub.doAddSub(1);

			MyVariables.expression = MyVariables.MyStore.storeExpBracAf(optr_1a, optr_2a, expression_brackets, stringSizeAf);
			MyVariables.optrDone = optrDoneAf + 1;
			MyVariables.numOfOptr = numOfOptrAf;

			if (MyVariables.optrDone != MyVariables.numOfOptr)
			{
				MyVariables.stringSize = MyVariables.MyCount.calStringSize();
				MyVariables.optr_1 = MyVariables.MyExpression.setAndFind(0, 1, 1, 5);
				MyVariables.optr_2 = MyVariables.MyExpression.setAndFind(MyVariables.optr_1 + 1, 1, 1, 6);
			}
		}
	}
}

