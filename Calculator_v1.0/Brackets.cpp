#include "Brackets.h"

void Brackets::doBrackets()
{
	Variables::reset();
	Variables::numOfOptr = Count::calNumOfOptr('(');

	//if no brackets then skip the whole function
	if (Variables::numOfOptr == 0)
		return;

	//find the position of two brackets
	Count::calStringSize();
	Variables::optr_1 = Expression::findOptr(0, 1, 1, 5);
	Variables::optr_2 = Expression::findOptr(Variables::optr_1 + 1, 1, 1, 6);

	//for loop to process all brackets
	for (; Variables::optrDone < Variables::numOfOptr;)
	{
		incomSet();
		comSet();		
	}
}

void Brackets::incomSet()
{
	//if the two brackets founded were both front brackets then continue finding the next set of brackets
	if (Variables::expression[Variables::optr_1] == '(' && Variables::expression[Variables::optr_2] == '(')
	{
		Count::calStringSize();
		Variables::optr_1 = Variables::optr_2;
		Variables::optr_2 = Expression::findOptr(Variables::optr_1 + 1, 1, 1, 6);
	}
}

void Brackets::comSet()
{
	//if the two brackets founded were a set of front and back brackets
	if (Variables::expression[Variables::optr_1] == '(' && Variables::expression[Variables::optr_2] == ')')
	{
		//setting the variables of the original expression
		std::string expression_brackets{ Variables::expression };
		int optr_1a{ Variables::optr_1 }, optr_2a{ Variables::optr_2 };
		int stringSizeAf{ Variables::stringSize };
		int optrDoneAf{ Variables::optrDone }, numOfOptrAf{ Variables::numOfOptr };

		//storing the sub-expression inside the brackets
		Variables::expression = Store::storeSubExpBrac(Variables::optr_1, Variables::optr_2);

		Format::format();
		Orders::doOrders();
		MultDiv::multDiv();
		AddSub::doAddSub(1);

		//storing the expression after the sub-expression being evaluated
		Variables::expression = Store::storeSubExpBracResult(optr_1a, optr_2a, expression_brackets, stringSizeAf);
		Variables::optrDone = optrDoneAf + 1;
		Variables::numOfOptr = numOfOptrAf;

		//for continuous processing of brackets
		if (Variables::optrDone != Variables::numOfOptr)
		{
			Count::calStringSize();
			Variables::optr_1 = Expression::findOptr(0, 1, 1, 5);
			Variables::optr_2 = Expression::findOptr(Variables::optr_1 + 1, 1, 1, 6);
		}
	}
}