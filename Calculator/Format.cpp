#include "Format.h"

void Format::format()
{
	formConstants();
	formFunc();
	formFroBrac();
	formBacBrac();
	formMultDiv();
	formCons();
	formOrders();
}

void Format::formFunc()
{
	int funcDone{}, numOfFunc{ Count::calNumOfOptr('[') };

	for (; funcDone < numOfFunc;)
		funcDone = forLoopFuncFormat(funcDone);

}

void Format::formConstants()
{
	int constDone{}, numOfConst{ Count::calNumOfOptr('<') };
	Count::calStringSize();

	for (; constDone < numOfConst; constDone++)
		forLoopConstFormat();
}

void Format::formFroBrac()
{

	int consOptrBracFroDone{}, numOfConsOptrFroBrac{ Count::calNumOfBracFroOptr() };
	Count::calStringSize();

	for (; consOptrBracFroDone < numOfConsOptrFroBrac; consOptrBracFroDone++)
	{
		for (; Condition::checkForCondition(1);)
		{
			//if it's ^ followed by a front brackets
			if (Condition::checkIfCondition(4, Variables::expression[Variables::posOfFor])
				&& Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormBrac(Variables::optr_1, Variables::optr_2, -1);
				Count::calStringSize();
				Variables::posOfFor = posOfForA;
				break;
			}

			//if it's anything except for operators followed by a front bracket
			if (!Condition::checkIfCondition(1, Variables::expression[Variables::posOfFor])
				&& !Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor])
				&& Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormBrac(Variables::optr_1, Variables::optr_2, 0);
				Count::calStringSize();
				Variables::posOfFor = posOfForA;
				break;
			}

			//if it's two consecutive front brackets
			if (Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor])
				&& Condition::checkIfCondition(5, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormBrac(Variables::optr_1, Variables::optr_2, 1);
				Count::calStringSize();
				Variables::posOfFor = posOfForA;
				break;
			}

			Variables::posOfFor++;
		}
	}
}

void Format::formBacBrac()
{
	int consOptrBracBacDone{}, numOfConsOptrBacBrac{ Count::calNumOfBracBacOptr() };
	Count::calStringSize();

	for (; consOptrBracBacDone < numOfConsOptrBacBrac; consOptrBracBacDone++)
	{
		for (; Condition::checkForCondition(1);)
		{
			//if it's a back bracket followed by anything except for operators 
			if (Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor])
				&& !Condition::checkIfCondition(1, Variables::expression[Variables::posOfFor + 1]) && !Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormBrac(Variables::optr_1, Variables::optr_2, 0);
				Count::calStringSize();
				Variables::posOfFor = posOfForA;
				break;
			}

			//if it's two consecutive back brackets
			if (Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor])
				&& Condition::checkIfCondition(7, Variables::expression[Variables::posOfFor + 1]))
			{
				setOptr();
				int posOfForA{ Variables::posOfFor };
				Store::storeExpFormBrac(Variables::optr_1, Variables::optr_2, 2);
				Count::calStringSize();
				Variables::posOfFor = posOfForA;
				break;
			}

			Variables::posOfFor++;
		}
	}
}

void Format::formMultDiv()
{
	int consOptrMultDivDone{}, numOfConsOptrMultDiv{ Count::calNumOfConsOptr(3) };

	//do-while loop to process multiplication of multiple negatives
	do
	{
		Count::calStringSize();

		for (; consOptrMultDivDone < numOfConsOptrMultDiv; consOptrMultDivDone++)
			forLoopMultDivOrdersFormat(3, 0); //if * or / is followed by + or -
			
		//next round of for loop
		numOfConsOptrMultDiv = Count::calNumOfConsOptr(3);
		consOptrMultDivDone = 0;
	} while (numOfConsOptrMultDiv != 0); //until there's no more signs directly after * and /
}

void Format::formCons()
{
	int consOptrDone{}, numOfConsOptr{ Count::calNumOfConsOptr(2) };
	int j{};

	Variables::reset();

	for (; consOptrDone < numOfConsOptr;)
	{
		Variables::resetPOF();
		Count::calStringSize();
		if (j == 0)
		{
			//undergo the processing of consecutive signs
			consOptrDone = forLoopAddSubFormat(Variables::optr_1, Variables::optr_2, 0, consOptrDone);
			j = 1;
			Variables::optr_1 = Variables::optr_2;
		}
		else if (j == 1)
		{
			consOptrDone = forLoopAddSubFormat(Variables::optr_2, Variables::optr_1, 1, consOptrDone);
			j = 0;
			Variables::optr_2 = Variables::optr_1;
		}
	}
}

void Format::formOrders()
{
	int consOptrOrdersDone{}, numOfConsOptrOrders{ Count::calNumOfConsOptr(4) };
	Count::calStringSize();

	for (; consOptrOrdersDone < numOfConsOptrOrders; consOptrOrdersDone++)
		forLoopMultDivOrdersFormat(4, 1); //if ^ is followed by + or -
}

void Format::setOptr()
{
	Variables::optr_1 = Variables::posOfFor;
	Variables::optr_2 = Variables::posOfFor + 1;
}

int Format::forLoopAddSubFormat(int optr_1a, int optr_2a, int mode, int consOptrDone)
{
	AddSub::optrAddSub(optr_1a, optr_2a, mode);

	if (mode == 0)
	{
		optr_1a = Variables::optr_1;
		optr_2a = Variables::optr_2;
	}
	
	if (mode == 1)
	{
		optr_2a = Variables::optr_1;
		optr_1a = Variables::optr_2;
	}

	if (optr_1a == optr_2a - 1)
	{
		Store::storeExpFormConsNegatives(optr_1a, optr_2a);
		Variables::optr_1--;
		Variables::optr_2--;
		return consOptrDone + 1;
	}

	return consOptrDone;
}

void Format::forLoopMultDivOrdersFormat(int ifMode, int mode)
{
	for (; Condition::checkForCondition(1); Variables::posOfFor++)
	{
		if (Condition::checkIfCondition(ifMode, Variables::expression[Variables::posOfFor]) && Condition::checkIfCondition(2, Variables::expression[Variables::posOfFor + 1]))
		{
			Variables::optr_1 = Variables::posOfFor;
			Variables::optr_3 = Variables::posOfFor + 1;
			Variables::optr_2 = Expression::findOptr(Variables::optr_1 - 1, -1, 2, 1);

			int posOfForA{ Variables::posOfFor };	
			Store::storeExpFormConsMultDivOrders(Variables::optr_2, Variables::optr_3, mode);
			Variables::posOfFor = posOfForA;
			break;
		}
	}
}

void Format::forLoopConstFormat()
{
	for (; Condition::checkForCondition(1);)
	{
		//if it's <
		if (Condition::checkIfCondition(9, Variables::expression[Variables::posOfFor]))
		{
			Variables::optr_1 = Variables::posOfFor; //find the front bracket, <
			int posOfForA{ Variables::posOfFor };
			Variables::posOfFor++;
			forLoopConstFormatBacBrac(); //find the bacl bracket, >

			Store::storeConstants(Variables::optr_1, Variables::optr_2);
			Count::calStringSize();
			Variables::posOfFor = posOfForA;
			break;
		}

		Variables::posOfFor++;
	}
}

void Format::forLoopConstFormatBacBrac()
{
	for (; Condition::checkForCondition(1);) //find the closing bracket for the constant, >
	{
		//if it's >
		if (Condition::checkIfCondition(9, Variables::expression[Variables::posOfFor]))
		{
			Variables::optr_2 = Variables::posOfFor;
			break;
		}

		Variables::posOfFor++;
	}
}

int Format::forLoopFuncFormat(int funcDone)
{
	Variables::reset();
	Count::calStringSize();
	Variables::optr_1 = Expression::findOptr(Variables::optr_1, 1, 1, 11);
	Variables::optr_2 = Expression::findOptr(Variables::optr_1 + 1, 1, 1, 10);

	//if both of them are [
	if (Condition::checkIfCondition(11, Variables::expression[Variables::optr_1]) && Condition::checkIfCondition(11, Variables::expression[Variables::optr_2]))
	{
		Variables::optr_1 = Variables::optr_2;
		Functions::mode = 1;
		return funcDone;
	}

	//store the new expression
	Store::storeFunc(Variables::optr_1, Variables::optr_2);

	return (funcDone + 1);
}