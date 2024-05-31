#ifndef VARIABLES_H
#define VARIABLES_H

#include "IOError.h"
#include "Expression.h"
#include "AddSub.h"
#include "MultDiv.h"
#include "Orders.h"
#include "Brackets.h"
#include "Format.h"
#include "Condition.h"
#include "Count.h"
#include "Store.h"
#include <string>

class Variables
{
public:
	static IOError MyIOError;
	static Expression MyExpression;
	static AddSub MyAddSub;
	static MultDiv MyMultDiv;
	static Orders MyOrders;
	static Brackets MyBrackets;
	static Format MyFormat;
	static Condition MyCondition;
	static Count MyCount;
	static Store MyStore;

	static int posOfFor; //current position of for loop
	static int stringSize;
	static int numOfOptr, optrDone; //number of operators
	static int optr_1, optr_2, optr_3; //position of operators

	static double result; //the result evaluated from the expression

	static double resultBrac;//the result evaluated from the sub-expression

	static std::string expression;//the string for expression

	//method to reset all variables except result
	static void reset();

	//method to reset current position of for loop
	static void resetPOF();
};

#endif